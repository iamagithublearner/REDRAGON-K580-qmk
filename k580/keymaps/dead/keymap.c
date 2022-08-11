#include QMK_KEYBOARD_H

// K580 Media Keys
// 1,20                 1,19            6,20           4,20
// Vol/Brightness       Media prev.     Play/Pause     Media next
// K580 Macro Keys
// 5,16     5,14    4,16    4,15    4,14    1,13
// G1       G2      G3      G4      G5      Rec

enum layer_names {
    _BASE,
    _FN,
    _WIND,
};

enum my_tapDances{
    TD_LALT_MUTE,
    FN_LAYR,
    GUI_LAYR2,
};

// Macro Keys (for default keymap)
enum {
  U_G1 = SAFE_RANGE,
  U_G2,
  U_G3,
  U_G4,
  U_G5,
  U_REC,
  U_VOLBRI, // Volume/Brightness toggle

  XXX_SAFE,
};

enum my_keycodes {
    HEATMAPKEY=XXX_SAFE,
    ALPHAMOD,
    GRADIENT,
    PIXELRAIN,
    HUEWAVE,
    JELLYBEAN,
    CHEVRON,
    BANDVALUE,
    MULTINEXUS,
    REACTWIDE,
    SPIRAL,
};

bool BRI = false; // Keep track of volume/brightness for the encoder

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  Row:        0           1           2           3        4           5        6        7           8           9           10          11          12          13          14          15          16          17          18          19          20     */
    [_BASE] = { {   KC_ESC,     KC_F1,      KC_F2,      KC_F3,   KC_F4,      KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     U_REC,      KC_PSCR,    KC_SLCK,    KC_PAUS,    KC_NO,      KC_NO,      KC_MPRV,    U_VOLBRI},
                {   KC_GRV,     KC_1,       KC_2,       KC_3,    KC_4,       KC_5,    KC_6,    KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    KC_INS,     KC_HOME,    KC_PGUP,    KC_NLCK,    KC_PSLS,    KC_PAST,    KC_PMNS },
                {   KC_TAB,     KC_Q,       KC_W,       KC_E,    KC_R,       KC_T,    KC_Y,    KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_DEL,     KC_END,     KC_PGDN,    KC_P7,      KC_P8,      KC_P9,      KC_PPLS },
                {   KC_CAPS,    KC_A,       KC_S,       KC_D,    KC_F,       KC_G,    KC_H,    KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_NO,      KC_ENT,     U_G5,       U_G4,       U_G3,       KC_P4,      KC_P5,      KC_P6,      KC_MNXT },
                {   KC_LSFT,    KC_NO,      KC_Z,       KC_X,    KC_C,       KC_V,    KC_B,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_NO,      KC_RSFT,    U_G2,       KC_UP,      U_G1,       KC_P1,      KC_P2,      KC_P3,      KC_PENT },
                {   KC_LCTL,    TD(GUI_LAYR2),    TD(TD_LALT_MUTE),    KC_SPC,     KC_RALT, TD(FN_LAYR), KC_APP,     KC_B,       KC_RCTL,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_H,       KC_P0,      KC_PDOT,    KC_MPLY }
              },
    [_FN]   = { {   RESET,      KC_MSEL,    KC_VOLD,    KC_VOLU, KC_MUTE,    KC_MSTP, KC_MPRV, KC_MPLY,    KC_MNXT,    KC_MAIL,    KC_SLEP,    KC_CALC,    RGB_TOG,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   _______,    TO(_BASE),  TO(_FN),    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    RGB_SPD,    RGB_SPI,    _______,    _______,    _______,    _______,    _______,    RGB_HUD,    RGB_HUI,    KC_BRIU },
                {   _______,    _______,    HUEWAVE,    _______, _______,    _______, _______, _______,    _______,    _______,    PIXELRAIN,    _______,    _______,    _______,    _______,    _______,    _______,    RGB_M_P,    RGB_M_B,    RGB_M_SW,    KC_BRID },
                {   _______,    ALPHAMOD,    SPIRAL,   _______, _______, GRADIENT, HEATMAPKEY, JELLYBEAN, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,    _______ },
                {   _______,    _______,    _______,    _______, CHEVRON,    _______, BANDVALUE, REACTWIDE,    MULTINEXUS,    _______,    _______,    _______,    _______,    _______,    _______,    RGB_SAI,    _______,    RGB_MOD,    RGB_M_G,    RGB_RMOD,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    RGB_SPD,    RGB_SAD,    RGB_SPI,    _______,    RGB_TOG,    BL_TOGG,    _______ }
             },
    [_WIND]   = { {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   KC_VOLU,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   KC_VOLD,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   _______,    _______,    _______,   _______, _______,     _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ }
            },
};


/* Macro LED support
                    {G1, G2, G3, G4, G5, REC} */
int macro_state[] = {0,  0,  0,  0,  0,  0  };

// Map Macro state to RGB channels of LED indices 77 and 78
void set_macro_leds(int state[]) {
    rgb_matrix_set_color(118, state[2]*255, state[1]*255, state[0]*255);
    rgb_matrix_set_color(119, state[5]*255, state[4]*255, state[3]*255);
}

void macro_led_toggle(int i) {
    macro_state[i] = 1-macro_state[i];
    set_macro_leds(macro_state);
}

void macro_led_on(int i) {
    macro_state[i] = 1;
    set_macro_leds(macro_state);
}

void macro_led_off(int i) {
    macro_state[i] = 0;
    set_macro_leds(macro_state);
}

void macro_led_clear(void) {
    for (int i = 0; i < 6; i++){
        macro_state[i] = 0;
    }
    set_macro_leds(macro_state);
}


// Macro support (for default keymap)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case HEATMAPKEY:
      if (record->event.pressed) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
      } else {
        // Do something else when release
      }
      return false; // Skip all further processing of this key
    case ALPHAMOD:
      if (record->event.pressed) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
      } else {
        // Do something else when release
      }
      return false; // Skip all further processing of this key
    case GRADIENT:
        if (record->event.pressed) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_GRADIENT_UP_DOWN);
        } else {
            // Do something else when release
        }
        return false;  // Skip all further processing of this key
    case PIXELRAIN:
        if (record->event.pressed) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_PIXEL_RAIN  );
        } else {
            // Do something else when release
        }
        return false;  // Skip all further processing of this key
    case HUEWAVE:
        if (record->event.pressed) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_HUE_WAVE);
        } else {
            // Do something else when release
        }
        return false;  // Skip all further processing of this key
    case JELLYBEAN:
        if (record->event.pressed) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_JELLYBEAN_RAINDROPS);
        } else {
            // Do something else when release
        }
        return false;  // Skip all further processing of this key
    case CHEVRON:
        if (record->event.pressed) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
        } else {
            // Do something else when release
        }
        return false;  // Skip all further processing of this key
    case BANDVALUE:
        if (record->event.pressed) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_SPIRAL_VAL);
        } else {
            // Do something else when release
        }
        return false;  // Skip all further processing of this key
    case MULTINEXUS:
        if (record->event.pressed) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
        } else {
            // Do something else when release
        }
        return false;  // Skip all further processing of this key
    case REACTWIDE:
        if (record->event.pressed) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);
        } else {
            // Do something else when release
        }
        return false;  // Skip all further processing of this key
    case SPIRAL:
        if (record->event.pressed) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_SPIRAL);
        } else {
            // Do something else when release
        }
        return false;  // Skip all further processing of this key
    case U_VOLBRI:
        if (record->event.pressed) {
            // switch volume/brightness for encoder
            BRI = !BRI;
        } else {
            // on release
        }
        break;
    case U_G1:
        if (record->event.pressed) {
            macro_led_toggle(0);
        }
        break;
    case U_G2:
        if (record->event.pressed) {
            macro_led_toggle(1);
        }
        break;
    case U_G3:
        if (record->event.pressed) {
            macro_led_toggle(2);
        }
        break;
    case U_G4:
        if (record->event.pressed) {
            macro_led_toggle(3);
        }
        break;
    case U_G5:
        if (record->event.pressed) {
            macro_led_toggle(4);
        }
        break;
    case U_REC:
        if (record->event.pressed) {
            macro_led_toggle(5);
        }
        break;
    }
    return true;
};


//encoder support
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            if(BRI){
                rgblight_increase_val_noeeprom();
            }else{
                tap_code(KC_VOLU);
            }
        } else {
            if(BRI){
                rgblight_decrease_val_noeeprom();
            }else{
                tap_code(KC_VOLD);
            }
        }
    }
    return true;  //TODO: try returning Flase here maybe it will fix flicker
}



void matrix_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINBOW_PINWHEELS);
}


// Define a type for as many tap dance states as you need            TAP DANCE CODE
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;
typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;
// Declare the functions to be used with your tap dance key(s)
// Function associated with all tap dances
td_state_t cur_dance(qk_tap_dance_state_t *state);
// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);
void ql2_finished(qk_tap_dance_state_t *state, void *user_data);
// Determine the current tap dance state
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}
// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
// Functions that control what our tap dance key does
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_NO);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_FN);
            break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_FN)) {
                // If already set, then switch it off
                layer_off(_FN);
            } else {
                // If not already set, then switch the layer on
                layer_on(_FN);
            }
            break;
        default:
            break;
    }
}
void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_FN);
    }
    ql_tap_state.state = TD_NONE;
}
void ql2_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_LGUI);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_WIND);
            break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_WIND)) {
                // If already set, then switch it off
                layer_off(_WIND);
            } else {
                // If not already set, then switch the layer on
                layer_on(_WIND);
            }
            break;
        default:
            break;
    }
}
void ql2_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_WIND);
    }
    ql_tap_state.state = TD_NONE;
}
// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LALT_MUTE] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_MUTE),
    [FN_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 275),
    [GUI_LAYR2] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql2_finished, ql2_reset, 275),
};

                                                                                //custom keycode

