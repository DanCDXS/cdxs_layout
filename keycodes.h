#pragma once

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes { QWERTY = SAFE_RANGE, LOWER, RAISE, ADJUST, RGBRST };

/***************************************
 *        MT(MODIFIER KEY, KEY)        *
 **************************************/
#define ALT_EQL MT(MOD_RALT, KC_EQL)
#define CTL_MIN MT(MOD_LCTL, KC_MINS)
#define GUI_OR MT(MOD_LGUI, KC_PIPE)

/***************************************
 *           LT(LAYER,KEY)             *
 **************************************/
#define LOW_SPC LT(_LOWER, KC_SPC)
#define LOW_LBR LT(_LOWER, KC_LBRC)
#define RAI_ENT LT(_RAISE, KC_ENT)
#define RAI_RBR LT(_RAISE, KC_RBRC)
#define ADJ_GRV LT(_ADJUST, KC_GRV)

#define KC_LOW TG(_LOWER);
