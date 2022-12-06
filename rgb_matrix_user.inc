RGB_MATRIX_EFFECT(LOWER)
RGB_MATRIX_EFFECT(RAISE)
RGB_MATRIX_EFFECT(IDLE)

/************************
 *   COLOR VARIATIONS   *
 ************************/
// 0x00, 0x13, 0xf0);  //Blue
// 0x6f, 0x13, 0xf0);  //Purple
// 0x8c, 0x13, 0xf0);  //Purple Joker //EVA PURPLE
// 0xf0, 0x13, 0xec);  //Pink
// 0x43, 0xf0, 0x13);  //Neon Green //EVA GREEN
// 0xf0, 0x81, 0x13);  //EVA GOLD
// 0xff, 0x13, 0x13);  //SCARLET RED

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

int underglow[] = {0, 1, 2, 3, 4, 5, 27, 28, 29, 30, 31, 32};
int arrow_keys[] = {16, 15, 20, 12};
int numbers[] = {23, 18, 17, 10, 9, 36, 37, 44, 45, 50};
int fkeys[] = {24, 23, 18, 17, 10, 9, 36, 37, 44, 45, 50, 51};
int control_basics_qwerty[] = {21, 20, 15, 14, 12, 11};
int media_keys[] = {8, 11, 16, 35, 38, 43, 46};
int quick_access[] = {7, 34};
int batman_beyond[] ={24, 23, 18, 17, 10,           37, 44, 45, 50, 51,
                          22, 19, 16, 11, 8,    35, 38, 43, 46, 49,
                              20, 15, 12, 7,    34, 39, 42, 47,
                                      13, 6,    33, 40,
                                          5,    32,
                                            6, 33};



static bool LOWER(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    //Turn off all leds
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);        
    }

    //UNDERGLOW LED
    for (uint8_t i = 0; i < 12; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(underglow[i], 0x8c, 0x13, 0xf0);  //Purple Joker 
    }

    //NUMBERS
    for (uint8_t i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(numbers[i], 0x6f, 0x13, 0xf0);  //Purple 
    }

    //ARROWS
    for (uint8_t i = 0; i < sizeof(arrow_keys)/sizeof(arrow_keys[0]); i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(arrow_keys[i], 0xf0, 0x13, 0xec);  //Pink
    }

    return rgb_matrix_check_finished_leds(led_max);
}

/*****************************
 *   EVANGELION/LEGO JOKER   *
 *****************************/
static bool RAISE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    //Turn off all leds
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);        
    }

    //UNDERGLOW LED
    for (uint8_t i = 0; i < 12; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(underglow[i], 0x43, 0xf0, 0x13);  //Neon Green   
    }

    //FKEYS
    for (uint8_t i = 0; i < sizeof(fkeys)/sizeof(fkeys[0]); i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(fkeys[i], 0x43, 0xf0, 0x13);  //Neon Green    
    }

    //MEDIA KEYS
    for (uint8_t i = 0; i < sizeof(media_keys)/sizeof(media_keys[0]); i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(media_keys[i], 0x8c, 0x13, 0xf0);  //Purple Joker  
    }

    //QUICK ACCESS
    for (uint8_t i = 0; i < sizeof(quick_access)/sizeof(quick_access[0]); i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(quick_access[i], 0xf0, 0x81, 0x13);  //EVA GOLD  
    }

    return rgb_matrix_check_finished_leds(led_max);
}

/*****************************
 *      BATMAN LOGO IDLE     *
 *****************************/
static bool IDLE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    //Turn off all leds first
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);        
    }

    //UNDERGLOW LED
    for (uint8_t i = 0; i < 12; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(underglow[i], 0xf0, 0x13, 0x13);  //SCARLET RED   
    }

    //BATMAN BEYOND WINGS
    for (uint8_t i = 0; i < sizeof(batman_beyond)/sizeof(batman_beyond[0]); i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(batman_beyond[i], 0xff, 0x13, 0x13);  //SCARLET RED  
    }

    return rgb_matrix_check_finished_leds(led_max);
}



#endif  //RGB_MATRIX_CUSTOM_EFFECT_IMPLS