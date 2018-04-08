#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default
#define SYMB 1 // symbols
#define MDIA 2 // media keys

#define EPRM M(1) // Macro 1: Reset EEPROM


#ifndef ALGR
#define ALGR(kc) RALT(kc)
#endif

#define CA_RBRC ALGR(KC_RBRC)
#define CA_LBRC ALGR(KC_LBRC)
#define CA_LCBR ALGR(KC_QUOT)
#define CA_RCBR ALGR(KC_BSLS)
#define CA_PLMN ALGR(KC_1)
#define CA_ACOM ALGR(KC_2)
#define CA_EURO ALGR(KC_3)
#define CA_CENT ALGR(KC_4)
#define CA_DCRO ALGR(KC_5)
#define CA_NOSE ALGR(KC_6)
#define CA_BPIP ALGR(KC_7)
#define CA_SQUA ALGR(KC_8)
#define CA_CUBE ALGR(KC_9)
#define CA_QUAR ALGR(KC_0)
#define CA_HALF ALGR(KC_MINS)
#define CA_3QUA ALGR(KC_EQL)
#define CA_EACUTE KC_SLSH
#define CA_CECID KC_RBRC
#define CA_GRAVE KC_QUOT
#define CA_DIAERESIS RSFT(KC_RBRC)
#define CA_CIRC KC_LBRC
#define CA_HASH KC_GRV
#define CA_DIVI KC_HASH
#define CA_TILD ALGR(KC_SCLN)
#define CA_UNDERC RSFT(KC_MINS)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  | DEL  |           |BACKSP|   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | #      |   Q  |   W  |   E  |   R  |   T  | INS  |           |      |   Y  |   U  |   I  |   O  |   P  |^(âêîûô)|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |`(àèìùò)|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | END  |           | HOME |   N  |   M  |   ,  |   .  |   é  |¨(äëïüö)|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |      | PgDn | Down | Right|                                       | LEFT |  Up  | PgUp |      | ¸ (ç) |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | ~L2  |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Space| LALT |------|       |------|  ~L1   |Enter |
 *                                 |      |      | WIN  |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 *
 * Keymap 1: Symbol layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   ±  |   @  |   £  |   ¢  |   ¤  |      |           |      |   ¬  |   ¦  |   ²  |   ³  |   ¼  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   _  |   ~  |   /  |   *  |      |           |      |   +  |   -  |   =  |   ½  |   ¾  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   [  |   {  |   (  |------|           |------|   )  |   }  |   ]  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |   <  |      |           |      |   >  |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 *
 * Keymap 2: Media layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F12   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | Mute | VolUp| VolDn|      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = KEYMAP(
	// left hand
		KC_ESC,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_DELT,
		CA_HASH,	KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_INS,
		KC_TAB,		KC_A,		KC_S,		KC_D,		KC_F,		KC_G,
		KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_END,
		KC_LCTL,	KC_TRNS,	KC_PGDN,	KC_DOWN,	KC_RGHT, 
																	KC_TRNS,	KC_FN2,
																				KC_TRNS,
														KC_SPC,		KC_LALT,	KC_LGUI,
	// right hand
		KC_BSPC,	KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_TRNS,
		KC_TRNS,	KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		CA_CIRC,
					KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	CA_GRAVE,
		KC_HOME,	KC_N,		KC_M,		KC_COMM,	KC_DOT,		CA_EACUTE,	CA_DIAERESIS,
								KC_LEFT,	KC_UP,		KC_PGUP,	KC_TRNS,	CA_CECID,
		KC_TRNS,	KC_TRNS,
		KC_TRNS,
		KC_TRNS,	KC_FN1,	KC_ENT
),
[SYMB] = KEYMAP(
	// left hand
		KC_TRNS,	CA_PLMN,	CA_ACOM,	CA_EURO,	CA_CENT,	CA_DCRO,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	CA_UNDERC,	CA_TILD,	CA_DIVI,	KC_ASTR,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	CA_LBRC,	CA_LCBR,	KC_LPRN,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_BSLS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS, 
																	KC_TRNS,	KC_TRNS,
																				KC_TRNS,
														KC_TRNS,	KC_TRNS,	KC_TRNS,
	// right hand
		KC_TRNS,	CA_NOSE,	CA_BPIP,	CA_SQUA,	CA_CUBE,	CA_QUAR,	KC_TRNS,
		KC_TRNS,	KC_PLUS,	KC_MINS,	KC_EQL,		CA_HALF,	CA_3QUA,	KC_TRNS,
					KC_RPRN,	CA_RCBR,	CA_RBRC,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_PIPE,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
								KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,
		KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS
),
[MDIA] = KEYMAP(
	// left hand
		KC_TRNS,	KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F11,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_MUTE,	KC_VOLU,	KC_VOLD,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS, 
																	KC_TRNS,	KC_TRNS,
																				KC_TRNS,
														KC_TRNS,	KC_TRNS,	KC_TRNS,
	// right hand
		KC_TRNS,	KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F12,
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
	[1] = ACTION_LAYER_TAP_TOGGLE(SYMB),                // FN1 - Momentary Layer 1 (Symbols)
	[2] = ACTION_LAYER_TAP_TOGGLE(MDIA)                 // FN2 - Momentary Layer 2 (Media)
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

/*
 *
 * Keymap 2: Media layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
/*[OTHE] = KEYMAP(
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
),*/