#include "api.h"
#include "sdk.c"

void main(system_api *apiPara) {
    initTT(apiPara);
    if (api->fpAkOidPara[First_time_exec] == 0) {
        api->fpAkOidPara[First_time_exec] = 1;
        // put your init code here
        playSoundNow(43);
    }
    // put your loop code here
    short read_oid = getOid();
    if (read_oid != 0) {
        if (read_oid == 4907) {
            playSoundNow(42);
        } else if (read_oid == 4906) {
            playSoundNow(41);
        } else {
            playSoundNow(20);
        }
    }
}