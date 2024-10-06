#include "api.h"

system_api *api;

void main(system_api *apiOrgi) {
    api = apiOrgi;
    if (api->fpAkOidPara[First_time_exec] == 0) {
        api->fpAkOidPara[First_time_exec] = 1; 

        int file2 = api->open(L"B:/dump/sysapi", 1, 1);
        api->write(file2, apiOrgi, 0x1ff);
        api->close(file2);
        // todo: add more offsets for diffrent pens

    }
}
