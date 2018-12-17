#include "tada68.h"

/* DO TO LIST

*/


// LAYERZ
#define _WBL 1 // Windows Base Layer (_WBL)
#define _MFL 0 // Mac Function Layer (_MFL)
#define _FL  3 // Functional Key Layer
#define _GL  2 // Gaming Layer

//KEYZ
#define _______ KC_TRNS // transparent key

// Tap Dance
/*
enum {
  TDW_1 = 0, TDW_2, TDW_3, TDW_4, TDW_5, TDW_6, TDW_7, TDW_8, TDW_9, TDW_10, TDW_11, TDW_12
};
*/

// Macroz
/*
enum custom_keycodes {
  M_MAC = SAFE_RANGE,
  M_WIN
};
*/

// Macro rulez
/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
    case M_WIN:
        SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK));
        layer_invert(1);
	//layer_on(1);
	backlight_set(10);
    return false; break;
    case M_MAC:
	SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK));
	layer_invert(1);
	//layer_on(0);
	backlight_set(0);
    return false; break;
    }
  }
  return true;

};
*/

//Layerz
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _WBL: (Windows Base Layer) 
   * ,----------------------------------------------------------------.
   * |~ ` | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Esc |
   * |----------------------------------------------------------------|
   * |(3,Tab)|  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| \ |Del |
   * |----------------------------------------------------------------|
   * |CTL(ESC)|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;| '|ENT  |TG(FL)|
   * |----------------------------------------------------------------|
   * |LSPO    |  Z|  X|  C|  V|  B|  N|  M|  ,|  .| /|RSPC |Up|TG(WFL)|
   * |----------------------------------------------------------------|
   * |CTL(CAPS)|Alt|Ctrl |     Space       |Ctrl|_____|Win|Lef|Dow|Rig|
   * `----------------------------------------------------------------'
   */

[_WBL] = KEYMAP_ANSI(
  KC_GRV, KC_1 , KC_2 , KC_3 ,  KC_4 , KC_5 , KC_6 , KC_7 , KC_8 , KC_9 , KC_0 , KC_MINS , KC_EQL , KC_BSPC,KC_ESC,\
  LT(3,KC_TAB),   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,   KC_RBRC, KC_BSLS, KC_DEL, \
  LCTL_T(KC_ESC), KC_A,  KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT,     KC_ENT     ,  _______, \
  KC_LSPO,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,      KC_COMM,  KC_DOT,  KC_SLSH,      KC_RSPC,  KC_UP,   _______, \
  LCTL_T(KC_CAPS),   KC_LALT,  KC_LCTL,             KC_SPC,                   KC_RCTL, _______   ,   KC_RGUI,       KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _MFL: (Mac Functional Layer)
   * ,----------------------------------------------------------------.
   * |~ ` | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Esc |
   * |----------------------------------------------------------------|
   * |(3,Tab)|  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| \ |Del |
   * |----------------------------------------------------------------|
   * |CTL(ESC) |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;| '|ENT |TG(FL)|
   * |----------------------------------------------------------------|
   * |LSPO    |  Z|  X|  C|  V|  B|  N|  M|  ,|  .| /|RSPC |Up|TG(WFL)|
   * |----------------------------------------------------------------|
   * |CTL(CAPS)|Alt |CMD |     Space       |CMD|_____|Alt|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_MFL] = KEYMAP_ANSI(
  KC_GRV, KC_1 , KC_2 , KC_3 , KC_4 , KC_5 , KC_6 , KC_7 , KC_8 , KC_9 , KC_0 , KC_MINS , KC_EQL , KC_BSPC,KC_ESC,\
  LT(3,KC_TAB),   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,  \
  LCTL_T(KC_ESC), KC_A, KC_S, KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,      KC_QUOT,       KC_ENT,  TG(3),   \
  KC_LSPO,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,      KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,   KC_UP,   TG(1)  , \
  LCTL_T(KC_CAPS), KC_LALT, KC_LGUI,               KC_SPC,                          KC_RGUI, _______  ,KC_RCTL,   KC_LEFT, KC_DOWN,  KC_RGHT),
 
  /* Keymap _FL: (Functional Key Layer) 
   * ,----------------------------------------------------------------------.
   * |F20|F1| F2| F3| F4| F5| F6| F7| F8 | F9 | F10 | F11 | F12 |     |RESET|
   * |----------------------------------------------------------------------|
   * |    |   |   |   |   |   |   | _  | =  |   |W_Ply|W_Prv|W_Nxt|    |    |
   * |----------------------------------------------------------------------|
   * |      |   |   |   |   |   |   | [  |  ] | {   |  }  |   |PRNTSCRN|    |
   * |----------------------------------------------------------------------|
   * |       |   |   |      |     |      |  |Mute|VolD|VolU| |    |MS_U|    |
   * |----------------------------------------------------------------------|
   * |   |    |     |            TO(GL)         |   |   |BTN1|MS_L|MS_D|MS_R|
   * `----------------------------------------------------------------------'
   */

[_FL] = KEYMAP_ANSI(
 KC_F20 , KC_F1 ,KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10 , KC_F11 , KC_F12 , _______, RESET,\
 _______, _______,_______,_______,_______,_______,_______,KC_UNDS, KC_EQL,_______,KC_MPLY,KC_MPRV,KC_MNXT, _______,_______, \
 _______,  _______,_______,_______,_______,_______,_______,KC_LBRC, KC_RBRC, LSFT(KC_LBRC) , LSFT(KC_RBRC),_______, KC_PSCR,_______, \
 _______,   _______,_______,_______,_______,_______, _______, KC_MUTE,KC_VOLD,KC_VOLU,  _______,_______, KC_MS_U, _______, \
 _______,_______,_______,                 TO(2),               _______, _______, KC_BTN1,   KC_MS_L,   KC_MS_D,  KC_MS_R),

  /* Keymap _GL: (Gaming Layer, sets CAPS and Shifts to normal keys)
   * ,----------------------------------------------------------------.
   * |~ ` | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Esc |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;| '|Return|TG(3) |
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|    |
   * |----------------------------------------------------------------|
   * |Ctrl|Alt|Ctrl |        Space         |Ctrl|TO(0)|Win|Lef|Dow|Rig|
   * `----------------------------------------------------------------'
   */

[_GL] = KEYMAP_ANSI(
  KC_GRV, KC_1 , KC_2 , KC_3 ,  KC_4 , KC_5 , KC_6 , KC_7 , KC_8 , KC_9 , KC_0 , KC_MINS , KC_EQL , KC_BSPC,KC_ESC,\
  KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P, KC_LBRC,   KC_RBRC, KC_BSLS, KC_DEL, \
  KC_CAPS, KC_A,  KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT,     KC_ENT     ,  TG(3), \
  KC_LSFT,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,      KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,  KC_UP, _______, \
  KC_LCTL,   KC_LALT,  KC_LCTL,             KC_SPC,                   KC_RCTL, TO(0)   ,   KC_RGUI,    KC_LEFT, KC_DOWN, KC_RGHT),

  };

// Tapdance definitionz

//qk_tap_dance_action_t tap_dance_actions[] = {
  //[TDW_1] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_F20),
  //[TDW_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_2),
  //[TDW_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_3),
  //[TDW_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_4),
  //[TDW_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_5),
  //[TDW_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_6),
  //[TDW_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_MPRV),
  //[TDW_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_MPLY),
  //[TDW_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_MNXT),
  //[TDW_10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_MUTE),
  //[TDW_11] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_VOLD),
  //[TDW_12] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_VOLU),
//}; 
