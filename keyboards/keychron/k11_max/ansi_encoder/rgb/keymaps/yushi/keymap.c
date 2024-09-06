#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers { MAC_BASE, WIN_BASE, MAC_FN1, WIN_FN1, FN2, CAPSLOCK, SYMBOLS, NUMBERS };
enum TD_keycodes {
    TD_CBR,
    TD_ABR,
    TD_PRN,
    TD_SBR,
};
tap_dance_action_t tap_dance_actions[] = {
    [TD_CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_ABR] = ACTION_TAP_DANCE_DOUBLE(KC_LABK, KC_RABK),
    [TD_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_SBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
};
// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)
// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_69_ansi(
        KC_CAPS,  KC_1,	   KC_2,	 KC_3,	  KC_4,    KC_5,	KC_6,	  KC_7,    KC_8,	KC_9,	 KC_0,	   KC_MINS,  KC_EQL,   KC_BSPC,          KC_MPLY,
        KC_TAB,  KC_Q,	   KC_W,	 KC_E,	  KC_R,    KC_T,	KC_Y,	  KC_U,    KC_I,	KC_O,	 KC_P,	   KC_LBRC,  KC_RBRC,  KC_BSLS,          MO(MAC_FN1),
        LT(CAPSLOCK,KC_ESC),HOME_A,HOME_S,HOME_D,HOME_F,KC_G,             KC_H,    HOME_J,  HOME_K,  HOME_L,   HOME_SCLN,KC_QUOT,  KC_ENT,           MO(FN2),
        KC_LSFT,           KC_Z,	 KC_X,	  KC_C,    KC_V,	KC_B,     KC_B, KC_N,	KC_M,	 KC_COMM,  KC_DOT,	 KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPTN, KC_LCMMD,          LT(SYMBOLS,KC_SPC),LALT(KC_BSPC) , LT(NUMBERS,KC_ENT),LT(SYMBOLS,KC_BSPC),KC_RCMMD,   KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_69_ansi(
        KC_ESC,  KC_1,	   KC_2,	 KC_3,	  KC_4,    KC_5,	KC_6,	  KC_7,    KC_8,	KC_9,	 KC_0,	   KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,	   KC_W,	 KC_E,	  KC_R,    KC_T,	KC_Y,	  KC_U,    KC_I,	KC_O,	 KC_P,	   KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,	   KC_S,	 KC_D,	  KC_F,    KC_G,              KC_H,    KC_J,	KC_K,	 KC_L,	   KC_SCLN,  KC_QUOT,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,	 KC_X,	  KC_C,    KC_V,	KC_B,	  KC_B,    KC_N,	KC_M,	 KC_COMM,  KC_DOT,	 KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,           KC_SPC,           MO(WIN_FN1), MO(FN2),       KC_SPC,            KC_RALT,            KC_LEFT, KC_DOWN, KC_RGHT),

    [MAC_FN1] = LAYOUT_69_ansi(
        AC_TOGG,  KC_BRID,  KC_BRIU, KC_MCTRL, KC_LNPAD,RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          KC_INS,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI,           _______, _______, _______, _______,  _______,  _______,  _______,          KC_END,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, KC_PGUP,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, KC_PGDN, _______),

    [WIN_FN1] = LAYOUT_69_ansi(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FILE, RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, _______,  _______, _______, _______, _______,  _______,	 _______,  _______,          KC_INS,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI,           _______, _______, _______, _______,  _______,  _______,  _______,          KC_END,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, KC_PGUP,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, KC_PGDN, _______),

    [FN2] = LAYOUT_69_ansi(
        KC_TILD, KC_F1,    KC_F2,	 KC_F3,   KC_F4,   KC_F5,	KC_F6,	  KC_F7,   KC_F8,	KC_F9,	 KC_F10,   KC_F11,	 KC_F12,   _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, BAT_LVL,  BAT_LVL, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),


    [CAPSLOCK] = LAYOUT_69_ansi(
        KC_CAPS, KC_F1,    KC_F2,	 KC_F3,   KC_F4,   KC_F5,	KC_F6,	  KC_F7,   KC_F8,	KC_F9,	 KC_F10,   KC_F11,	 KC_F12,  _______,           _______,
        _______, _______,  _______,  _______, _______, _______, _______,  DM_REC1, DM_PLY1, DM_PLY2, DM_REC2,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______,           KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_LSFT,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, KC_PGUP,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, KC_PGDN, _______),

    [SYMBOLS] = LAYOUT_69_ansi(
        _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,         _______,
        _______,  TD(TD_PRN),KC_HASH,KC_CIRC, KC_AMPR, KC_TILD,  KC_AT,   KC_DLR, KC_COLN, TD(TD_SBR),_______,  _______,  _______, _______,         _______,
        _______,  KC_ASTR,  KC_LT,   KC_EQL,  KC_GT,   KC_EXLM,           KC_PERC, KC_SCLN, KC_GRV,   KC_DQUO,  _______,  _______, _______,         _______,
        _______,           _______,  KC_UNDS, KC_DOT,  KC_PIPE, TD(TD_CBR),TD(TD_CBR),KC_MINS, KC_PLUS,  _______,  _______,  _______, _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),
    [NUMBERS] = LAYOUT_69_ansi(
        _______, _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______,  KC_KP_7, KC_KP_8, KC_KP_9,  _______, _______,  _______,  _______,          _______,
        _______,KC_F5, LSFT(KC_F11),  KC_F11,  KC_F10, _______,            KC_DOT, KC_KP_4, KC_KP_5, KC_KP_6, _______,   _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3,   _______,  _______,  _______,
        _______, _______,  _______,       LCTL(KC_F5),          _______,  _______,          _______,           _______,            _______, _______, _______)

};
#if defined(ENCODER_MAP_ENABLE)
	const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
		[MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
		[WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
		[MAC_FN1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
		[WIN_FN1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
		[FN2]	   = {ENCODER_CCW_CW(_______, _______)},
        [CAPSLOCK] = {ENCODER_CCW_CW(KC_MPRV,KC_MNXT)},
        [SYMBOLS]  = {ENCODER_CCW_CW(_______, _______)},
        [NUMBERS]  = {ENCODER_CCW_CW(_______, _______)}

	};
#endif // ENCODER_MAP_ENABLE
// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}
