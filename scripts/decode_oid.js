import { readFileSync } from "fs"

const buff = readFileSync(process.argv[2])

const time = []
const clk = []
const sio = []

buff.toString().split("\n").forEach((x) => {
    const arr = x.split(",")
    time.push(parseFloat(arr[0]))
    sio.push(parseInt(arr[1]))
    clk.push(parseInt(arr[2]))

})

let output = []
let lastClk = clk[1];
let lastSio = sio[1];
let lastClkUp = 0;
let isDataTransmitted = true;
let blockNextRound = false;
const outsammlung = []

for (let i = 2; i < time.length; i++) {
    if (((time[i] - lastClkUp) * 1000 * 1000) > 78 && isDataTransmitted == true) {
        isDataTransmitted = false
        console.log("timed out")
        console.log(output)
        outsammlung.push(output)
        console.log("data end")
        output = []
    }
    if (blockNextRound) {
        console.log("round_blocked")
        blockNextRound = false;
        continue
    }


    if (lastSio == 1 && sio[i] == 0) {
        // pulled data low
        if (isDataTransmitted == false) {
            isDataTransmitted = true
            console.log("slave init")
            lastClkUp = time[i]
            blockNextRound = true
        }
    }
    if (lastSio == 0 && sio[i] == 1) {
        // pulled data hith
    }
    if (lastClk == 1 && clk[i] == 0) {
        // pulled clk low
        output.push(sio[i])
        lastClkUp = time[i]
    }
    if (lastClk == 0 && clk[i] == 1) {
        // pulled clk high
    }

    lastClk = clk[i]
    lastSio = sio[i]
}
console.log("reached end")
console.log(output)
console.log(output.length)
console.log(outsammlung)
console.log("===============")
outsammlung.forEach((x) => {
    // todo: fix this
    if (x.length > 8) { // this catches the sensor initialed values that got parsed wrong and fixes it
        x.shift()

        if (x.length > 40) {
            const end = x.slice(-16)

            const neuarr = x.slice(0, 8)
            if (neuarr.join("") == "00000000") {
                console.log(`got oid ${parseInt(end.join(""), 2)}`)
            }
        }

    }
})
