#include "kb.h"
enum {
	TD_MPLY_MNXT = 0
}; 

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_MPLY_MNXT] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT)
};

#define _GAME 0
#define _FUNCTION 1
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_GAME] = KEYMAP(
		KC_ESC, KC_F4, KC_F5, KC_F11, KC_F12, KC_BSPACE, TG(1), 
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, 
		KC_TAB, TD(TD_MPLY_MNXT), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_PLUS, 
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, 
		KC_LSFT, KC_SLEP, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ENT, 
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_DOT, KC_F19),

	[_FUNCTION] = KEYMAP(
		KC_ESC, KC_F14, KC_F15, KC_F16, KC_F17, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_PPLS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_P4, KC_P5, KC_P6, 
		KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_ENT, 
		KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_P0, KC_PDOT, KC_TRNS)

};


static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}



void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    } else if (index == 2) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    return false;
}





void keyboard_post_init_user(void) {

  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

