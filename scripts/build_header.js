import fs from "fs"

const lines = fs.readFileSync(process.argv[2]).toString().split("\n")
for (let i = 0; i < lines.length; i++) {
    const fields = lines[i].split("\t")
    if (fields[2] != "FALSCH") {
        if (fields[0] == "") {
            console.log(`    void (*tbd${i})();`)
        } else {
            console.log(`    void (*${fields[0].replace("()", "")})();`)
        }
    } else {
        console.log(`    int (tbd${i});`)
    }
}