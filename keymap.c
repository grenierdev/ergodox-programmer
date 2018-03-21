#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define OTHE 3

#define EPRM M(1) // Macro 1: Reset EEPROM


#ifndef ALGR
#define ALGR(kc) RALT(kc)
#endif

#define CA_RBRC ALGR(KC_RBRC)
#define CA_LBRC ALGR(KC_LBRC)
#define CA_LCBR ALGR(KC_QUOT)
#define CA_RCBR ALGR(KC_BSLS)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(
	// left hand
		KC_GRV,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_TRNS,
		KC_TAB,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_TRNS,
		KC_LSFT,	KC_A,		KC_S,		KC_D,		KC_F,		KC_G,
		KC_LCTL,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS, 
																	KC_TRNS,	KC_TRNS,
																				KC_TRNS,
														KC_SPC,		KC_BSPC,	KC_LGUI,
	// right hand
		KC_DELT,	KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_TRNS,
		KC_BSPC,	KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_TRNS,
					KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	KC_TRNS,
		KC_TRNS,	KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,	KC_TRNS,
								KC_RALT,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,
		KC_TRNS,
		KC_TRNS,	TG(SYMB),	KC_ENT
),
[SYMB] = KEYMAP(
	// left hand
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	CA_LBRC,	CA_LCBR,	KC_LPRN,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS, 
																	KC_TRNS,	KC_TRNS,
																				KC_TRNS,
														KC_TRNS,	KC_TRNS,	KC_TRNS,
	// right hand
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
					KC_RPRN,	CA_RCBR,	CA_RBRC,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
								KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,
		KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS
),
[MDIA] = KEYMAP(
	// left hand
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS, 
																	KC_TRNS,	KC_TRNS,
																				KC_TRNS,
														KC_TRNS,	KC_TRNS,	KC_TRNS,
	// right hand
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
					KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
								KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,
		KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS
),
[OTHE] = KEYMAP(
	// left hand
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS, 
																	KC_TRNS,	KC_TRNS,
																				KC_TRNS,
														KC_TRNS,	KC_TRNS,	KC_TRNS,
	// right hand
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
					KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
								KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,
		KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
	[1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
	  switch(id) {
		case 0:
		if (record->event.pressed) {
		  SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
		}
		break;
		case 1:
		if (record->event.pressed) { // For resetting EEPROM
		  eeconfig_init();
		}
		break;
	  }
	return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

	uint8_t layer = biton32(layer_state);

	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();
	switch (layer) {
	  // TODO: Make this relevant to the ErgoDox EZ.
		case 1:
			ergodox_right_led_1_on();
			break;
		case 2:
			ergodox_right_led_2_on();
			break;
		default:
			// none
			break;
	}

};