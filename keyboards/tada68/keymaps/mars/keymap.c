#include "tada68.h"

/* DO TO LIST

*/


// LAYERZ
#define _MBL 0 // Mac Base Layer (_WBL)
#define _WFL 1 // Windows Function Layer (_MFL)
#define _FL  2 // Functional Key Layer

//KEYZ
#define _______ KC_TRNS // transparent key

//Layerz
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _MBL: (Mac Base Layer)
   * ,----------------------------------------------------------------.
   * |~ ` | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Esc |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;| '|Return|PGUP  |
   * |----------------------------------------------------------------|
   * |LSHFT   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .| /|RSHFT|Up|TG(WFL)|
   * |----------------------------------------------------------------|
   * |Ctrl|Alt |CMD |        Space         |CMD|TG(FL)|Alt|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_MBL] = KEYMAP_ANSI(
  KC_GRV, KC_1 , KC_2 , KC_3 , KC_4 , KC_5 , KC_6 , KC_7 , KC_8 , KC_9 , KC_0 , KC_MINS , KC_EQL , KC_BSPC,KC_ESC,\
  KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,  \
  KC_CAPS, KC_A, KC_S, KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,      KC_QUOT,       KC_ENT,  KC_PGUP, \
  KC_LSPO,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,      KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,   KC_UP,   TG(1), \
  KC_LCTL, KC_LALT, KC_LGUI,               KC_SPC,                          KC_RGUI, TG(2),KC_RALT,   KC_LEFT, KC_DOWN,  KC_RGHT),

  /* Keymap _WFL: (Windows Functional Layer) 
   * ,----------------------------------------------------------------.
   * |~ ` | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Esc |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;| '|Return| PGUP |
   * |----------------------------------------------------------------|
   * |LSHFT   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .| /|RSHFT|Up|TG(MBL)|
   * |----------------------------------------------------------------|
   * |Ctrl|WIN|ALT |        Space         |Ctrl|TG(FL)|ALT|Lef|Dow|Rig|
   * `----------------------------------------------------------------'
   */

[_WFL] = KEYMAP_ANSI(
  KC_GRV, KC_1 , KC_2 , KC_3 ,  KC_4 , KC_5 , KC_6 , KC_7 , KC_8 , KC_9 , KC_0 , KC_MINS , KC_EQL , KC_BSPC,KC_ESC,\
  KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,   KC_RBRC, KC_BSLS, KC_DEL, \
  KC_CAPS, KC_A,  KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT,     KC_ENT     ,  KC_PGUP, \
  KC_LSPO,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,      KC_COMM,  KC_DOT,  KC_SLSH,      KC_RSPC,  KC_UP,   TG(1), \
  KC_LCTL,   KC_LGUI,  KC_LALT,             KC_SPC,                   KC_RCTL, TG(2)   ,   KC_RALT,       KC_LEFT, KC_DOWN, KC_RGHT),
 

  /* Keymap _FL: (Functional Key Layer) 
   * ,----------------------------------------------------------------------.
   * |F20|F1| F2| F3| F4| F5| F6| F7| F8 | F9 | F10 | F11 | F12 |     |RESET|
   * |----------------------------------------------------------------------|
   * |    |   |   |   |   |   |   | _  |   |   |W_Ply|W_Prv|W_Nxt|     |    |
   * |----------------------------------------------------------------------|
   * |      |   |   |   |   |   |   | [  |  ] |     |     |   |PRNTSCRN|    |
   * |----------------------------------------------------------------------|
   * |       |   |   |      |     |      |  |Mute|VolD|VolU| |    |MS_U|    |
   * |----------------------------------------------------------------------|
   * |   |    |     |            TO(GL)         |   |   |BTN1|MS_L|MS_D|MS_R|
   * `----------------------------------------------------------------------'
   */

[_FL] = KEYMAP_ANSI(
 KC_F20 , KC_F1 ,KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10 , KC_F11 , KC_F12 , _______, _______,\
 _______, _______,_______,_______,_______,_______,_______,_______, _______,_______,KC_MPLY,KC_MPRV,KC_MNXT, _______,_______, \
 _______,  _______,_______,_______,_______,_______,_______,_______, _______, _______ , _______ ,_______, _______,_______,  \
 _______,   _______,_______,_______,_______,_______, _______, KC_MUTE,KC_VOLD,KC_VOLU,  _______,_______, _______, _______, \
 _______,_______,_______,                 _______,               _______, _______, _______,   _______,   _______,  _______)

  };
