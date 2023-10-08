#pragma once

#include QMK_KEYBOARD_H
#include "quantum.h"

// Settings
#define MIN_WALK_SPEED 10
#define MIN_RUN_SPEED 40

// Advanced settings
#define ANIM_FRAME_DURATION 200
#define ANIM_SIZE 96

// Renders luna oled pet
void render_luna (
  int x,
  int y
);

void process_luna (
  uint16_t keycode,
  keyrecord_t *record
);
