#ifndef __API_H__
#define __API_H__

typedef struct {                                                                                               // this seems to be the same on 2N and 3L, but fpAkOidPara differs
    void (*tbd0)();                                                                                            // 0
    void (*tbd1)();                                                                                            // 1
    void (*printf)(unsigned char *);                                                                           // 2
    int (*is_audio_playing)();                                                                                 // 3
    void (*tbd4)();                                                                                            // 4
    int (*open)(unsigned short *, unsigned int, unsigned int);                                                 // 5
    int (*read)(int filehandle, void *buff, unsigned int size);                                                // 6 
    int (*write)(int filehandle, void *buff, unsigned int size);                                               // 7
    int (*close)(int filehandle);                                                                              // 8
    int (*seek)(int, unsigned int, int allways_is_zero);                                                       // 9
    void (*tbd10)();                                                                                           // 10
    int (*last_thing_that_gets_called_to_play_sound)(int filehandle, unsigned int offset, unsigned int size);  // 11
    char *(*returns_if_p_audPlayer_is_null)();                                                                 // 12
    unsigned char *(fpAkOidPara);                                                                              // 13
    int(*p_filehandle_current_gme);                                                                            // 14
    int(*tbd15);
    int(*tbd16);
    void (*IMP_acces_from_gme_gametable_offset_maybe_init)();
    int(*tbd18);
    void (*tbd19)();
    int(*tbd20);
    int(*tbd21);
    int(*tbd22);
    int(*tbd23);
    int(*tbd24);
    int(*tbd25);
    int(*tbd26);
    void (*imp_maybe_xor)();
    void (*parse_new_gme_header)();
    void (*inits_resets_the_gme_registers_to_default)();
    void (*parses_start_and_end_oid)();
    void (*parse_play_script_into_lines)(unsigned short oid);  // ig unsigned short
    void (*finds_script_line_that_meets_condition)();
    void (*check_oid_script_condition)();
    void (*parses_action_part_of_script_line)();
    void (*executes_play_script_comman)();
    void (*tbd36)();
    void (*parses_media_offsets_and_size)();
    void (*also_parses_media_offsets_and_size)();
    void (*sets_script_related_stuff_to_zero)();
    void (*parses_og_game_table)();
    void (*parses_aditional_script_table)();
    void (*checks_product_id_and_ravensburg_id)();
    void (*something_mod)();
    int(*tbd44);
    int(*tbd45);
    int(*tbd46);
    int(*tbd47);
    int(*tbd48);
    int(*tbd49);
    int(*tbd50);
    int(*tbd51);
    int(*tbd52);
    int(*tbd53);
    int(*tbd54);
    int(*tbd55);
    int(*tbd56);
    int(*tbd57);
    int(*tbd58);
    int(*tbd59);
    int(*tbd60);
    int(*tbd61);
    int(*tbd62);
    int(*tbd63);
    int(*tbd64);
    int(*tbd65);
    int(*tbd66);
    int(*tbd67);
    int(*tbd68);
    int(*tbd69);
    int(*tbd70);
    int(*tbd71);
    int(*tbd72);
    int(*tbd73);
    int(*tbd74);
    int(*tbd75);
    int(*tbd76);
    int(*tbd77);
    int(*tbd78);
    int(*tbd79);
    int(*tbd80);
    int(*tbd81);
    int(*tbd82);
    int(*tbd83);
    int(*tbd84);
    int(*tbd85);
    int(*tbd86);
    int(*tbd87);
    int(*tbd88);
    int(*tbd89);
    int(*tbd90);
    int(*tbd91);
    int(*tbd92);
    int(*tbd93);
    int(*tbd94);
    int(*tbd95);
    int(*tbd96);
    int(*tbd97);
    int(*tbd98);
    void (*play_chomp_voice)();
    void (*get_random_number_or_counter)();
    void (*maybe_mkFile_maybe_delete)();
    void (*tbd102)();
    void (*tbd103)(); // from here on (including this) is only on newer pens (not on 2N) todo: check on which (its confirmed to exist in 4E)
    void (*returns_booc_rec_str)();
    void (*tbd105)();
    void (*record_sound)();
    void (*also_record_sound)();
    void (*another_record_sound)();
    void (*more_record_sound)();
    void (*end_of_record_sound)();
    void (*used_in_rec_main)();
    void (*tbd112)();
    void (*tbd113)();
    void (*tbd114)();
    void (*tbd115)();
    void (*tbd116)();
    void (*spam_print_and_sounds)();
    void (*tbd118)();
    void (*tbd119)();
    void (*tbd120)();
    void (*something_with_tomplay_wav)();
    void (*idk_but_can_say_record_full)();
    void (*used_in_rec_main2)();
    void (*IMP_has_record_filepath_string)();
    void (*tbd125)();
    void (*tbd126)();
    void (*something_play_atmo_short)();
    void (*tbd128)();
    void (*if_stuff_not_null_executes_funcs_and_sets_it_null)();
    void (*tbd130)();
    void (*tbd131)();
    void (*get_book_recordings_string)();
    void (*tbd133)();
    void (*tbd134)();
    void (*tbd135)();
    void (*tbd136)();
    void (*other_book_recc_str)();
    void (*tbd138)();
    void (*tbd139)();
    void (*tbd140)();
} system_api;

// #define build_for_2N
#ifdef build_for_2N
// #pragma message("Compiling for 2N")
#define First_time_exec 0xdec
#define anotherMain_last_maybe_exit 0xdee
#define new_oid 0xded
#define oid_offset 0x4
#define otherMain_equals_100 0x58

#define SAVEDATA 0x08141000
#define START_PROG_BIN 0x08009000
#else
// #pragma message("Compiling for 3L")
#define First_time_exec 0x1318
#define anotherMain_last_maybe_exit 0x131a
#define new_oid 0x1319
#define oid_offset 0xc
#define otherMain_equals_100 0x6

#define SAVEDATA 0x00940000
#define START_PROG_BIN 0x00829000
#endif

#endif