#include "api.h"
#include "sdk.c"

system_api *api;

void main(system_api *apiPara) {
    api = apiPara;
    if (api->fpAkOidPara[First_time_exec] == 0) {
        api->fpAkOidPara[First_time_exec] = 1;
        // put your init code here
        
    }
    // put here your loop code

}