#include "api.h"

system_api *api;

int i;

void main(system_api *apiPara) {
    api = apiPara;
    if (api->fpAkOidPara[First_time_exec] == 0) {
        api->fpAkOidPara[First_time_exec] = 1;
        i = 0;
    }
    if (api->is_audio_playing() == 0) {
        api->something_chomp_voice(i);
        i++;
    }
}