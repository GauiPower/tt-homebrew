#include "api.h"
#include "sdk.c"

int currentSoundId;
system_api *api;

void main(system_api *apiPara) {
    api = apiPara;
    if (api->fpAkOidPara[First_time_exec] == 0) {
        api->fpAkOidPara[First_time_exec] = 1;
        currentSoundId = 0;
    }
    if (api->is_audio_playing() == 0) {
        playSound(currentSoundId);
        currentSoundId++;
    }
}
