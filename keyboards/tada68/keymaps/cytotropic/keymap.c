#include "tada68.h"

// LAYERZ
#define _MBL 0 // Mac Base Layer (_MBL)
#define _WFL 1 // Windows Function Layer (_WFL)

// Tap Dance declarations
enum {
  TD_F1 = 0,
  TD_F2,
  TD_F3,
  TD_F4,
  TD_F5,
  TD_F6,
  TD_F7,
  TD_F8,
  TD_F9,
  TD_F10,
  TD_F11,
  TD_F12
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
    case M_MAC:
        SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK));
        layer_invert(_WFL);
    return false; break;
    case M_WIN:
	SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_TAP(X_SCROLLLOCK));
	layer_invert(_MBL);
    return false; break;
    }
  }
  return true;

};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _MBL: (Mac Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Alt |CMD |        Space          |CMD| FN| Alt|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_MBL] = KEYMAP_ANSI(
  KC_ESC, TD(TD_F1),TD(TD_F2),TD(TD_F3),TD(TD_F4),TD(TD_F5),TD(TD_F6),TD(TD_F7),TD(TD_F8),TD(TD_F9),TD(TD_F10), TD(TD_F11), TD(TD_F12), KC_BSPC,KC_GRV,\
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,  \
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,        KC_QUOT,       KC_ENT,  KC_PGUP, \
  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,   KC_UP,   KC_PGDN, \
  KC_LCTL, KC_LALT, KC_LGUI,                         KC_SPC,                                   KC_RGUI, M_MAC  ,KC_RALT,   KC_LEFT, KC_DOWN,  KC_RGHT),


  /* Keymap _WFL: (Windows Function Layer) 
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Win|Alt |Ctrl |        Space          |Ctrl| FN| Alt|Lef|Dow|Rig|
   * `----------------------------------------------------------------'
   */

[_WFL] = KEYMAP_ANSI(
  KC_ESC, TD(TD_F1),TD(TD_F2),TD(TD_F3),TD(TD_F4),TD(TD_F5),TD(TD_F6),TD(TD_F7),TD(TD_F8),TD(TD_F9),TD(TD_F10), TD(TD_F11), TD(TD_F12), KC_BSPC,KC_GRV,\
  KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,  KC_BSLS, KC_DEL, \
  KC_CAPS,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,  KC_PGUP,\
  KC_LSFT,           KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,      KC_RSFT,  KC_UP,   KC_PGDN,\
  KC_LGUI,   KC_LALT,  KC_LCTL,                        KC_SPC,                          KC_RCTL, M_WIN   ,   KC_RALT,       KC_LEFT, KC_DOWN, KC_RGHT),
};

// Tapdance definitions                                                                                                                               
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_F1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
  [TD_F2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
  [TD_F3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
  [TD_F4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
  [TD_F5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
  [TD_F6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
  [TD_F7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
  [TD_F8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
  [TD_F9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
  [TD_F10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
  [TD_F11] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_F11),
  [TD_F12] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_F12),
};

/*  
// Macros

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch(id) {

    case 0:
         return MACRO(T(SLCK), W(1), T(SLCK), W(1), TG(_WFL), END);

    case 1:
         return MACRO(T(SLCK), W(1), T(SLCK), W(1), TG(_MBL), END);

    }


    }
  return MACRO_NONE;

};
*/
