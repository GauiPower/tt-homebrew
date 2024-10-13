import { readFileSync } from "fs"

const buff = readFileSync(process.argv[2])

// this script translates a sysapi dump to a list of hex adresses, so you can paste it in a table or csv

for (let i = 0; i < buff.length - 4; i = i + 4) {
    console.log(`${buff.readUInt32LE(i).toString(16)}`)
}