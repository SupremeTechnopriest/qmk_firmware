#include "quantum.h"
#include "features/achordion.h"
#include "features/oled.h"
#include "features/luna.h"

#ifdef OLED_ENABLE
  bool oled_task_user (void) {
    if (is_keyboard_master()) {
      // OS Logo
      if (keymap_config.swap_lctl_lgui) {
        render_osx_logo(0, 0);
      } else {
        render_windows_logo(0, 0);
      }

      // Layer Info
      render_default_layer(0, 3);
      render_line(0, 4);
      render_layer(0, 5);

      // LED State
      render_led_state(0, 7);

      // Pet
      render_luna(0, 13);
    } else {
      render_logo(0, 0);
      render_girl(0, 9);
      render_current_wpm(0, 14);
    }
    return false;
  }
#endif

bool process_record_user (uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) {
    return false;
  }

  process_luna(keycode, record);

  #ifdef CONSOLE_ENABLE
    uprintf(
      "KL: kc: 0x%04X, pos: [%u, %u] pressed: %u, time: %5u, int: %u, count: %u, mod state: %#06X, capsword: %u \n\n",
      keycode, record->event.key.row, record->event.key.col, record->event.pressed,
      record->event.time, record->tap.interrupted, record->tap.count, get_mods(), is_caps_word_on()
    );
  #endif

  return true;
}

void matrix_scan_user (void) {
  achordion_task();
}
