import { GmeFile } from "gmelib"
import { readFileSync } from "fs"
import readline from "readline"
import child from "child_process"
import minimist from "minimist"
const argv = minimist(process.argv.splice(2))

const printHelp = () => {
    console.log(`        tt-homebrew buildscript
        usage:
        -i      .gme file as input
        -o      .gme file output
        -n      the name of the package that should be build, for example dump_ram or play_sounds
        -l      list games inside the input .gme file
        -p      patch the output file insadt of writing it new, its faster, especially if you output on the pen direct | note: only works if you have dd installed
        -d      output dd commands, that you can use instad of this script
        -b      which binary inside the .gme file should be overwritten
                write a number to overwrite the corrosponding game or write M to overwrite the main binary `)
    process.exit(1)
}

if (argv.h | argv.help) {
    printHelp();
}

if (!argv.i) {
    console.error("please specify the input file\n")
    printHelp();
}

const gmefile = new GmeFile(readFileSync(argv.i))

if (argv.l || argv.b > gmefile.game1binariesTable.length - 1 || (typeof argv.b === "string" && argv.b.toString().toLowerCase() !== "m")) { // todo fix this mess
    console.log(`Valid games are 0-${gmefile.game1binariesTable.length - 1} or M for the main binary`)
    process.exit(1)
}

if (argv.d) {
    if (argv.b.toString().toLowerCase() == "m") {
        console.log(`dd if=main_1.bin of=${argv.o ?? "output.gme"} bs=1 seek=${gmefile.main1binaryTable[0].offset} count=${gmefile.main1binaryTable[0].size} conv=notrunc`)
        console.log(`dd if=main_2N.bin of=${argv.o ?? "output.gme"}  bs=1 seek=${gmefile.main2NbinaryTable[0].offset} count=${gmefile.main2NbinaryTable[0].size} conv=notrunc`)
        console.log(`dd if=main_3L.bin of=${argv.o ?? "output.gme"}  bs=1 seek=${gmefile.main3LbinaryTable[0].offset} count=${gmefile.main3LbinaryTable[0].size} conv=notrunc`)
    } else {
        console.log(`dd if=game_1.bin of=${argv.o ?? "output.gme"}  bs=1 seek=${gmefile.game1binariesTable[argv.b].offset} count=${gmefile.game1binariesTable[argv.b].size} conv=notrunc`)
        console.log(`dd if=game_2N.bin of=${argv.o ?? "output.gme"}  bs=1 seek=${gmefile.game2NbinariesTable[argv.b].offset} count=${gmefile.game2NbinariesTable[argv.b].size} conv=notrunc`)
        console.log(`dd if=game_3L.bin of=${argv.o ?? "output.gme"}  bs=1 seek=${gmefile.game3LbinariesTable[argv.b].offset} count=${gmefile.game3LbinariesTable[argv.b].size} conv=notrunc`)
    }
    process.exit()
}

if (!argv.n) {
    console.error("use -n to specify which package to build, for example dump_ram")
    printHelp()
}

if (!argv.o) {
    console.error("specify a output file with -o output.gme")
    printHelp()
}

console.log(child.execSync("make", {cwd: `packages/${argv.n}`}).toString())
// process.exit()

if (argv.p) {
    // patch the output with dd
    child.execSync(`dd if=packages/${argv.n}/build/2N.bin of=${argv.o} bs=1 seek=${gmefile.main2NbinaryTable[0].offset} count=${gmefile.main2NbinaryTable[0].size} conv=notrunc`)
    child.execSync(`dd if=packages/${argv.n}/build/3L.bin of=${argv.o} bs=1 seek=${gmefile.main3LbinaryTable[0].offset} count=${gmefile.main3LbinaryTable[0].size} conv=notrunc`)
} else {
    // todo: fix this
    if (argv.b.toString().toLowerCase() == "m") {
        gmefile.replaceBinary(readFileSync(`packages/${argv.n}/build/2N.bin`), gmefile.main2NbinaryTable, gmefile.main2NbinaryTableOffset, 0)
    } else {
        gmefile.replaceBinary(readFileSync(`packages/${argv.n}/build/2N.bin`), gmefile.game2NbinariesTable, gmefile.game2NbinariesTableOffset, argv.b)
    }
}

