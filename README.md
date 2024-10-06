# tt-homebrew
tt-homebrew is a tool that makes it easy to write games for the TipToi in C, providing full access to all features of the pen.

## disclaimer
tt-homebrew is not in anyway afiliated with ravensburger. It's possible that you brick your pen, use this tool at your own risk. It never happened to me in all testing, but you could call functions that overwrite the flash, making it unable to boot again. 

## getting started
Install `nodejs` and `gcc-arm-none-eabi` or just use `nix-shell`.  
Then run `npm i` to install the dependencies.  
Get the syntax with `node build.js -h`.

With `node build.js -i gme/Wimmelbuch.gme -o '/run/media/$(whoami)/tiptoi/Wimmelbuch.gme' -n dump_ram -p -g m` you can compile your first example, that dumps ram from the tiptoi to its storage, you can find it by connecting your pen to your pc and look in the "dump" folder


## roadmap
- [x] Support for 2N and 3L
- [ ] Create a main template, that makes scripts work
- [ ] Create files without tttool (coming soon, checkout gmelib)
- [ ] list files and directorys
- [ ] Microphone support for Pens (in work)
- [ ] Uart
- [ ] Wifi support (i dont have a pen with wifi)
- [ ] add firmware offsets with functions that arent accesable via the game api


## knowledge
on 2N and 3L the system_api seems to be compatible, but different ``fpAkOidPara``

| Processor     | 1             | 2N            | 3L (tested on 4E, other firmwares are different)     
| ------------- | ------------- | ------------- | ------------- |
| Bootrom       | tbd           | 0x0000 0000   | 0x0000 0000?  |
| Bios.bin      | tbd           | 0x0800 0000   | 0x0080 0000   |
| Prog.bin      | tbd           | 0x0800 9000   | 0x0082 9000
| Prog.bin entry| tbd           | 0x0800 9100   | 0x0085 ed01 the 1 at the end means thumb mode / only for 4e / differs on 5E and 6E
| GME bins      | tbd           | 0x0813 2000   | 0x0093 0000?
| GME Gamestate | tbd           | 0x0814 1000   | 0x0094 0000
| Return Game   | tbd           |               | 0x0082 c3c5? looks wrong
| Return Main   | tbd           | 

> i dont have a pen with first gen processor, feel free to test it on your pen
