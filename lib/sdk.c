#include "api.h"

extern system_api *api;

void playSound(unsigned int sound_id) {
    int filehandle_current_gme = *api->p_filehandle_current_gme;
    unsigned int mediaFileTableOffset;
    unsigned int soundOffset;
    unsigned int soundLength;

    api->seek(filehandle_current_gme, 4, 0);  // set reading point to adrr 4 in gme file because there is offset for media file table

    api->read(filehandle_current_gme, &mediaFileTableOffset, 4);  // reads int from filehandle

    api->seek(filehandle_current_gme, mediaFileTableOffset + sound_id * 8, 0);  // times 8 because every entry is 4 bytes offset and 4 bytes length

    api->read(filehandle_current_gme, &soundOffset, 4);
    api->read(filehandle_current_gme, &soundLength, 4);

    api->last_thing_that_gets_called_to_play_sound(filehandle_current_gme, soundOffset, soundLength);
}