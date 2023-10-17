#include QMK_KEYBOARD_H
#include "quantum.h"
#include "../../features/layers.h"
#include "../../features/achordion.h"

// Momentary Layers
#define CONTROL   MO(_CONTROL)

// Default Layers
#define QWERTY    DF(_QWERTY)
#define HALMAK    DF(_HALMAK)

// Layer Taps
#define NAV       LT(_NAV, KC_SPC)
#define MOUSE     LT(_MOUSE, KC_TAB)
#define MEDIA     LT(_MEDIA, KC_ESC)
#define NUM       LT(_NUMBER, KC_BSPC)
#define SYM       LT(_SYMBOL, KC_ENT)
#define FUN       LT(_FUNCTION, KC_DEL)

// QWERTY Button
#define Q_Z       LT(_BUTTON, KC_Z)
#define Q_SLSH    LT(_BUTTON, KC_SLSH)

// HALMAK Button
#define H_F       LT(_BUTTON, KC_F)
#define H_Y       LT(_BUTTON, KC_Y)

// QWERTY Mod Taps
#define Q_A       LGUI_T(KC_A)
#define Q_S       LALT_T(KC_S)
#define Q_D       LCTL_T(KC_D)
#define Q_F       LSFT_T(KC_F)

#define Q_J       RSFT_T(KC_J)
#define Q_K       RCTL_T(KC_K)
#define Q_L       RALT_T(KC_L)
#define Q_QUOT    RGUI_T(KC_QUOT)

// HALMAK Mod Taps
#define H_S       LGUI_T(KC_S)
#define H_H       LALT_T(KC_H)
#define H_N       LCTL_T(KC_N)
#define H_T       LSFT_T(KC_T)

#define H_A       RSFT_T(KC_A)
#define H_E       RCTL_T(KC_E)
#define H_O       RALT_T(KC_O)
#define H_I       RGUI_T(KC_I)

// Hotkeys
#define OS        CG_TOGG
#define COPY      C(KC_C)
#define CUT       C(KC_X)
#define PASTE     C(KC_V)
#define UNDO      C(KC_Z)
#define REDO      C(KC_Y)

// Combos
#define COMBO_COUNT 3
const uint16_t PROGMEM combo_left[] = {MOUSE, NAV, COMBO_END};
const uint16_t PROGMEM combo_right[] = {SYM, NUM, COMBO_END};
const uint16_t PROGMEM combo_both[] = {MOUSE, SYM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_left, CONTROL),
  COMBO(combo_right, CONTROL),
  COMBO(combo_both, CONTROL)
};

// Tap Dance
enum {
  TD_QK_BOOT
};

void td_double_tap_boot (tap_dance_state_t* state, void* user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}

tap_dance_action_t tap_dance_actions[] = {
  [TD_QK_BOOT] = ACTION_TAP_DANCE_FN(td_double_tap_boot),
};

#define TD_BOOT     TD(TD_QK_BOOT)

//
// QWERTY
//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
          Q_A,     Q_S,     Q_D,     Q_F,    KC_G,                          KC_H,    Q_J,     Q_K,    Q_L,   Q_QUOT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
          Q_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,  Q_SLSH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                MEDIA,   NAV,     MOUSE,           SYM,     NUM,    FUN
                            //`--------------------------'  `--------------------------'

  ),

  //
  // HALMAK
  //

  [1] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
         KC_W,    KC_L,    KC_R,    KC_B,    KC_Z,                      KC_QUOT,    KC_Q,    KC_U,    KC_D,    KC_J,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
          H_S,     H_H,     H_N,     H_T, KC_COMM,                       KC_DOT,     H_A,     H_E,     H_O,     H_I,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
          H_F,    KC_M,    KC_V,    KC_C, KC_SLSH,                         KC_G,    KC_P,    KC_X,    KC_K,     H_Y,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                MEDIA,   NAV,     MOUSE,           SYM,     NUM,    FUN
                            //`--------------------------'  `--------------------------'
  ),

  //
  // NAV
  //

  [2] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         REDO,   PASTE,    COPY,     CUT,    UNDO,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                      KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                KC_NO,   KC_NO,   KC_NO,        KC_ENT, KC_BSPC,  KC_DEL
                            //`--------------------------'    `--------------------------'
  ),

  //
  // MOUSE
  //

  [3] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         REDO,   PASTE,    COPY,     CUT,    UNDO,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                        KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                KC_NO,   KC_NO,   KC_NO,       KC_BTN2, KC_BTN1, KC_BTN3
                            //`--------------------------'    `--------------------------'
  ),

  //
  // BUTTON
  //

  [4] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
         UNDO,     CUT,    COPY,   PASTE,    REDO,                         REDO,   PASTE,    COPY,     CUT,    UNDO,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                        KC_NO, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         UNDO,    CUT,    COPY,    PASTE,    REDO,                         REDO,   PASTE,    COPY,     CUT,    UNDO,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                KC_BTN3, KC_BTN1, KC_BTN2,     KC_BTN2, KC_BTN1, KC_BTN3
                            //`--------------------------'   `--------------------------'
  ),

  //
  // MEDIA
  //

  [5] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                        KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                KC_NO,   KC_NO,   KC_NO,       KC_MSTP, KC_MPLY, KC_MUTE
                            //`--------------------------'   `--------------------------'
  ),

  //
  // NUMBER
  //

  [6] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                        KC_NO, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                KC_DOT,  KC_0,    KC_MINS,       KC_NO,   KC_NO,   KC_NO
                            //`--------------------------'   `--------------------------'
  ),

  //
  // SYMBOL
  //

  [7] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                        KC_NO, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                KC_LPRN, KC_RPRN, KC_UNDS,       KC_NO,   KC_NO,   KC_NO
                            //`--------------------------'   `--------------------------'
  ),

  //
  // FUNCTION
  //

  [8] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
       KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,                        KC_NO, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                KC_APP,  KC_SPC,  KC_TAB,        KC_NO,   KC_NO,   KC_NO
                            //`--------------------------'   `--------------------------'
  ),

  //
  // CONTROL
  //

  [9] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      TD_BOOT, CG_TOGG,  HALMAK,  QWERTY, DM_RSTP,                      DM_RSTP,  QWERTY,  HALMAK, CG_TOGG, TD_BOOT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO, DM_PLY1, DM_REC1,                      DM_REC1, DM_PLY1,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO, DM_PLY2, DM_REC2,                      DM_REC2, DM_PLY2,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_NO,   KC_NO
                            //`--------------------------'   `--------------------------'
  )
};



uint16_t achordion_timeout (uint16_t keycode) {
  switch (keycode) {
    case MEDIA:
    case NAV:
    case MOUSE:
    case SYM:
    case NUM:
    case FUN:
    case Q_Z:
    case Q_SLSH:
    case H_F:
    case H_Y:
      return 0;
    default:
      return 800;
  }
}

bool achordion_chord(
  uint16_t tap_hold_keycode,
  keyrecord_t* tap_hold_record,
  uint16_t other_keycode,
  keyrecord_t* other_record
) {
  return achordion_opposite_hands(tap_hold_record, other_record);
}
