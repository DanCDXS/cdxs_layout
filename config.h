#pragma once

/******************************************
 *   Master side split keyboard options   *
 ******************************************/
//#define EE_HANDS
//#define SPLIT_USB_DETECT
//#define MASTER_RIGHT
#define MASTER_LEFT
#define USE_SERIAL_PD2

#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define TAPPING_TERM 250
#define NO_ACTION_ONESHOT

#define SPLIT_TRANSPORT_MIRROR

/**********************
 *  OLED file/config  *
 *********************/
#ifdef OLED_ENABLE
#    define OLED_FONT_H "keyboards/crkbd/keymaps/cdxs/glcdfont.c"
// This sends whether or not ctrl, shift, etc. are held to the secondary half of
// the keyboard. Note that it seems to "break" one half entirely unless BOTH
// halves have this enabled.
#    define SPLIT_MODS_ENABLE
// Allow the current layer to be synced between the halves.
#    define SPLIT_LAYER_STATE_ENABLE
// Allow the state of caps lock, num lock, etc. to be synced between the halves.
#    define SPLIT_LED_STATE_ENABLE
#    define SPLIT_OLED_ENABLE
#    undef OLED_TIMEOUT
//  due to timer_read() for render_prompt(), we have own implementation of oled time out
#    define OLED_KEY_TIMEOUT 30000
#endif

/***********************
 *  RGB Matrix Effects *
 ***********************/
#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_KEYPRESSES                                // reacts to keypresses
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100                    // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#    define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
// HSV VALUES SCARLET RED
#    define RGB_MATRIX_HUE_STEP 5
#    define RGB_MATRIX_SAT_STEP 92
#    define RGB_MATRIX_VAL_STEP 94
#    define RGB_MATRIX_SPD_STEP 20
//#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
// Split keyboard specific
#    define RGBLED_NUM 54 // Number of LEDs
#    define DRIVER_LED_TOTAL RGBLED_NUM
#    define RGB_MATRIX_SPLIT \
        { 27, 27 } // Split keyboards, the number of LEDs connected on each half. X = left, Y = Right
#    define ENABLE_RGB_MATRIX_ALPHAS_MODS
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#endif
