#include "api.h"
#include "sdk.c"

// this is just a experiment and currently DOESNT WORK

void main(system_api *apiPara) {
    initTT(apiPara);
    if (api->fpAkOidPara[First_time_exec] == 0) {
        api->fpAkOidPara[First_time_exec] = 1;
        initPlaySoundFifo();
        // put your init code here
        api->play_chomp_voice(3);
        api->gme_registers[0] = 1; //check
    }
    // put your loop code here

    handlePlaySound();
}