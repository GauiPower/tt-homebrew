#include "api.h"
#include "sdk.c"

void main(system_api *apiPara) {
    initTT(apiPara);
    if (api->fpAkOidPara[First_time_exec] == 0) {
        api->fpAkOidPara[First_time_exec] = 1;
        // put your init code here
        playSound(43);
    }
    // put your loop code here
    if (api->fpAkOidPara[new_oid] == 1) {
        api->fpAkOidPara[new_oid] = 0;
        short read_oid = *(short *)&api->fpAkOidPara[oid_offset];
        if (read_oid == 4907) {
            playSound(42);
        } else if (read_oid == 4906) {
            playSound(41);
        } else {
            playSound(20);
        }
    }
}