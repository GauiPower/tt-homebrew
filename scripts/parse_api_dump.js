import { readFileSync } from "fs"

const buff = readFileSync("sysapi.bin")

for (let i = 0; i < buff.length; i = i + 4) {
    console.log(`${buff.readUInt32LE(i).toString(16)}`)
}