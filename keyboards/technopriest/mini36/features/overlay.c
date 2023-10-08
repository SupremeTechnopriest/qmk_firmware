#include "overlay.h"

layer_state_t default_layer_set_user (layer_state_t state) {
  int16_t layer = _QWERTY;

  if (IS_LAYER_ON_STATE(state, _QWERTY)) {
    layer = _QWERTY;
  } else if (IS_LAYER_ON_STATE(state, _HALMAK)) {
    layer = _HALMAK;
  }

  tap_code16(KC_F13 + layer);
  return state;
}

layer_state_t layer_state_set_user (layer_state_t state) {
  int16_t layer = get_highest_layer(default_layer_state);
  if (IS_LAYER_ON_STATE(state, _QWERTY)) {
    layer = get_highest_layer(default_layer_state);
  } else if (IS_LAYER_ON_STATE(state, _HALMAK)) {
    layer = get_highest_layer(default_layer_state);
  } else if (IS_LAYER_ON_STATE(state, _NAV)) {
    layer = _NAV;
  } else if (IS_LAYER_ON_STATE(state, _MOUSE)) {
    layer = _MOUSE;
  } else if (IS_LAYER_ON_STATE(state, _BUTTON)) {
    layer = _BUTTON;
  } else if (IS_LAYER_ON_STATE(state, _MEDIA)) {
    layer = _MEDIA;
  } else if (IS_LAYER_ON_STATE(state, _NUMBER)) {
    layer = _NUMBER;
  } else if (IS_LAYER_ON_STATE(state, _SYMBOL)) {
    layer = _SYMBOL;
  } else if (IS_LAYER_ON_STATE(state, _FUNCTION)) {
    layer = _FUNCTION;
  } else if (IS_LAYER_ON_STATE(state, _CONTROL)) {
    layer = _CONTROL;
  }

  tap_code16(KC_F13 + layer);
  return state;
}
