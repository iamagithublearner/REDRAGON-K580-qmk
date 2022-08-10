#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x0C45
#define PRODUCT_ID      0x5004
#define DEVICE_VER      0x0001

#define MANUFACTURER    Redragon
#define PRODUCT         Redragon K580 VATA
#define DESCRIPTION     K580 VATA

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 21

#define DIODE_DIRECTION ROW2COL

#define MATRIX_COL_PINS { A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, B0, B1, B2, B3, B4, B5 }
#define MATRIX_ROW_PINS { C15, D11, D10, D9, D8, D7 }

/*Encoder support with correct pins*/
#define ENCODERS_PAD_A { D4 }
#define ENCODERS_PAD_B { D3 }
#define ENCODER_DIRECTION_FLIP
#define ENCODER_RESOLUTION 2
#define QMK_KEYS_PER_SCAN 4

// wait DELAY ms before unregistering media keys
#define TAP_CODE_DELAY 5

// Enable NKRO and set polling to 1ms
#undef FORCE_NKRO
#define FORCE_NKRO
#define USB_POLLING_INTERVAL_MS 1


/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

#define LED_NUM_LOCK_PIN    B13
#define LED_CAPS_LOCK_PIN   B14
#define LED_SCROLL_LOCK_PIN B15
#define LED_PIN_ON_STATE    0

#include "config_led.h"
