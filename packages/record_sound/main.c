#include "api.h"
#include "sdk.c"

// this is a try to record sounds with the pen
// THIS DOES CURRENTLY NOT WORK

void main(system_api *apiPara) {
    initTT(apiPara);
    if (api->fpAkOidPara[First_time_exec] == 0) {
        api->fpAkOidPara[First_time_exec] = 1;
        // put your init code here
        
    }
    // put your loop code here

}