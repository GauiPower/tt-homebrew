#include "api.h"
#include "sdk.c"

// if you already wrote a game with gme-scripts, you can use this code to add a savegame mechanism
// set the first register to 0 to load the savestate or set it to 1 to save the savestate
// then call this game binary
// note: i currently dont know, how to exit a game, you have to do this via a script that calls the exit game action
// or maybe you can just let this run in the background, idk

// this code is untested and may not work

void main(system_api *apiPara) {
    initTT(apiPara);
    if (api->fpAkOidPara[First_time_exec] == 0) {
        api->fpAkOidPara[First_time_exec] = 1;
        // put your init code here
        if (api->gme_registers[0] == 0) {
            // load game
            int file = api->open(L"B:/tt-homebrew.save", 0, 0);
            api->read(file, api->gme_registers, *api->gme_register_count * 2); // oh man, dass muss definitiv getestet werden
            api->close(file);
        } else if (api->gme_registers[0] == 1) {
            int file = api->open(L"B:/tt-homebrew.save", 1, 1);
            api->write(file, api->gme_registers, *api->gme_register_count * 2);
            api->close(file);
            // save game
        }
        
    }
    // put your loop code here

}