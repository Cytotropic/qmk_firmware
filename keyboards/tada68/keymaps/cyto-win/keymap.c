#include "tada68.h"

/* DO TO LIST
- Mac Screen Brightness keys
CHECK - Mac Media keys
CHECK - Win Media keys
CHECK - Reset key
CHECK - backlight changes
*/


// LAYERZ
#define _MBL 1 // Mac Base Layer (_MBL)
#define _WFL 0 // Windows Function Layer (_WFL)
#define _FL  2 // Functional Key Layer

//KEYZ
#define _______ KC_TRNS // transparent key

// Tap Dance
enum {
  TDM_1 = 0, TDM_2, TDM_3, TDM_4, TDM_5, TDM_6, TDM_7, TDM_8, TDM_9, TDM_10, TDM_11, TDM_12,
  TDW_1,     TDW_2, TDW_3, TDW_4, TDW_5, TDW_6, TDW_7, TDW_8, TDW_9, TDW_10, TDW_11, TDW_12
};

// Macros
enum custom_keycodes {
  M_MAC = SAFE_RANGE,
  M_WIN
};

// Macro rules
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
    case M_WIN:
        SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK));
        layer_invert(1);
	backlight_set(10);
    return false; break;
    case M_MAC:
	SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK));
	layer_invert(1);
	backlight_set(0);
    return false; break;
    }
  }
  return true;

};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _MBL: (Mac Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |~ ` | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Esc |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;| '|Return|TG(FL)|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .| /|Shift|Up|TG(WFL)|
   * |----------------------------------------------------------------|
   * |Ctrl|Alt |CMD |        Space         |CMD|M_Mac|Alt|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_MBL] = KEYMAP_ANSI(
  KC_GRV, KC_1 , KC_2 , KC_3 , KC_4 , KC_5 , KC_6 , KC_7 , KC_8 , KC_9 , KC_0 , KC_MINS , KC_EQL , KC_BSPC,KC_ESC,\
  KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,  \
  KC_CAPS,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,      KC_QUOT,       KC_ENT,  _______, \
  KC_LSFT,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,      KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,   KC_UP,   _______, \
  KC_LCTL, KC_LALT, KC_LGUI,               KC_SPC,                          KC_RGUI, M_MAC  ,KC_RALT,   KC_LEFT, KC_DOWN,  KC_RGHT),

 
  /* Keymap _WFL: (Windows Function Layer) 
   * ,----------------------------------------------------------------.
   * |~ ` | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Esc |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;| '|Return|TG(FL)|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Alt|Ctrl |        Space         |Ctrl|M_WIN|Win|Lef|Dow|Rig|
   * `----------------------------------------------------------------'
   */

[_WFL] = KEYMAP_ANSI(
  KC_GRV, KC_1 , KC_2 , KC_3 ,  KC_4 , KC_5 , KC_6 , KC_7 , KC_8 , KC_9 , KC_0 , KC_MINS , KC_EQL , KC_BSPC,KC_ESC,\
  KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,   KC_RBRC,  KC_BSLS, KC_DEL, \
  KC_CAPS,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN,  KC_QUOT,       KC_ENT     ,  TG(2), \
  KC_LSFT,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,      KC_COMM,  KC_DOT,  KC_SLSH,      KC_RSFT,  KC_UP,   TG(1), \
  KC_LCTL,   KC_LALT,  KC_LCTL,             KC_SPC,                   KC_RCTL, M_WIN   ,   KC_RGUI,       KC_LEFT, KC_DOWN, KC_RGHT),

 
  /* Keymap _FL: (Functional Key Layer) 
   * ,----------------------------------------------------------------------.
   * |   |F1| F2| F3| F4| F5| F6| F7| F8 | F9 | F10 | F11 | F12 |     |RESET|
   * |----------------------------------------------------------------------|
   * |    |   |   |   |   |   |   |   |   |W_Prv|W_Ply|W_Nxt|   |     |     |
   * |----------------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |M_Prv|M_Ply|M_Nxt|   |      |      |
   * |----------------------------------------------------------------------|
   * |       |   |   |BL_DEC|BL_TG|BL_INC|  |Mute|VolD|VolU| |BTN1|MS_U|BTN2|
   * |----------------------------------------------------------------------|
   * |   |    |     |                            |   |   |   |MS_L|MS_D|MS_R|
   * `----------------------------------------------------------------------'
   */

[_FL] = KEYMAP_ANSI(
 _______, KC_F1 ,KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10 , KC_F11 , KC_F12 , _______, RESET,\
 _______, _______,_______,_______,_______,_______,_______,_______,_______,KC_MPRV,KC_MPLY,KC_MNXT,_______, _______,_______,\
 _______,  _______,_______,_______,_______,_______,_______,_______, KC_MRWD , KC_MPLY , KC_MFFD ,_______,_______,_______,  \
 _______,   _______,_______,BL_DEC, BL_TOGG,BL_INC, _______, KC_MUTE,KC_VOLD,KC_VOLU,  _______, KC_BTN1, KC_MS_U, KC_BTN2, \
 _______,_______,_______,                 _______,               _______, _______, _______,   KC_MS_L,   KC_MS_D,  KC_MS_R),
  };

// Tapdance definitions                                                                                                                               
qk_tap_dance_action_t tap_dance_actions[] = {
  //[TDM_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_1),
  //[TDM_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_2),
  //[TDM_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_3),
  //[TDM_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_4),
  //[TDM_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_5),
  //[TDM_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_6),
  //[TDM_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_MRWD),
  //[TDM_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_MPLY),
  //[TDM_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_MFFD),
  //[TDM_10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_MUTE),
  //[TDM_11] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_VOLD),
  //[TDM_12] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_VOLU),
  //[TDW_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_1),
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
}; 
