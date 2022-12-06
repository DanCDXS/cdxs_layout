#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "oled.c"

uint8_t rgbmode;
static void setGameRGB(int);
bool rgbStatus = true;

void matrix_scan_user(void) {
    if(rgb_matrix_config.mode != RGB_MATRIX_CUSTOM_LOWER 
    && rgb_matrix_config.mode != RGB_MATRIX_CUSTOM_RAISE 
    && rgb_matrix_config.mode != RGB_MATRIX_CUSTOM_IDLE){
        rgbmode = rgb_matrix_config.mode;
    }
}

void setGameRGB(int n) {
  switch (n) {
    case 1:
        if(!rgbmode) rgbmode = rgb_matrix_config.mode;
        rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_LOWER);
    break;
    case 2:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_RAISE);
    break;
    case 3:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_IDLE);
    break;
  }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    if (record->event.pressed) {
        oled_timer = timer_read();
        is_key_processed = true;
        add_keylog(keycode);
    }
#endif
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        
    case _LOWER:
       setGameRGB(1);
        break;
    case _RAISE:
        setGameRGB(2);
        break;
    case _ADJUST:
       setGameRGB(3);
        break;
    default: //  for any other layers, or the default layer
        rgbStatus = rgb_matrix_is_enabled();
        if(rgbStatus == true){
            rgb_matrix_mode_noeeprom(rgbmode);
        }
        break;
    }
  return state;
}





// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     QK_GESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      GUI_OR,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         CTL_MIN,  LOW_LBR, LOW_SPC,     RAI_ENT, RAI_RBR, ALT_EQL
                                      //|--------------------------|  |--------------------------|
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     QK_GESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_PERC, KC_PLUS, KC_MINS,  KC_UP,  KC_PSLS, KC_ASTR,                      KC_LPRN, KC_RPRN, KC_AMPR, KC_EXLM, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      GUI_OR, KC_HASH, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DLR,                      KC_LBRC, KC_RBRC, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         CTL_MIN, _______,  KC_SPC,     KC_ENT, ADJ_GRV, ALT_EQL
                                      //|--------------------------|  |--------------------------|
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB, KC_PGUP, KC_HOME, KC_MUTE, KC_VOLD, KC_VOLU,                      KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, KC_BRIU,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     MOD_LGUI, KC_PGDN, KC_END,  KC_INS,  KC_DEL, KC_MYCM,                      KC_MSEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LCTL, ADJ_GRV,  KC_SPC,     KC_ENT, _______, KC_ALGR
                                      //|--------------------------|  |--------------------------|
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     XXXXXXX, CK_RST,  CK_DOWN, CK_UP,   CK_TOGG, RGB_TOG,                       MU_TOG, KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,                       MU_MOD, KC_F11,  KC_F4,   KC_F5,   KC_F6,   QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGBRST,                        AU_TOG, KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX,  
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,    _______, KC_VOLD, KC_VOLU 
                                      //|--------------------------|  |--------------------------|
  )
};
// clang-format off
