#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  HSV_204_255_255,
  HSV_43_255_255,
  HSV_74_255_255,
  DRAG_SCROLL,
  TOGGLE_SCROLL,
  NAVIGATOR_INC_CPI,
  NAVIGATOR_DEC_CPI,
  NAVIGATOR_TURBO,
  NAVIGATOR_AIM
};



#define DUAL_FUNC_0 LT(11, KC_F3)
#define DUAL_FUNC_1 LT(14, KC_N)
#define DUAL_FUNC_2 LT(4, KC_F16)
#define DUAL_FUNC_3 LT(8, KC_L)
#define DUAL_FUNC_4 LT(1, KC_F16)
#define DUAL_FUNC_5 LT(6, KC_F16)
#define DUAL_FUNC_6 LT(1, KC_F20)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           DUAL_FUNC_0,                                    KC_MINUS,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           
    KC_Q,           KC_W,           DUAL_FUNC_1,    DUAL_FUNC_2,    DUAL_FUNC_3,    DUAL_FUNC_4,                                    KC_BSLS,        KC_Y,           KC_U,           KC_I,           DUAL_FUNC_5,    KC_P,           
    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_GRAVE,                                       KC_QUOTE,       KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        
    MT(MOD_LCTL, KC_Z),LT(4, KC_X),    LT(2, KC_C),    MT(MOD_RSFT, KC_V),MT(MOD_LALT, KC_B),LGUI(LSFT(KC_4)),                                KC_HYPR,        MT(MOD_RALT, KC_N),MT(MOD_RSFT, KC_M),LT(1, KC_COMMA),LT(4, KC_DOT),  MT(MOD_RCTL, KC_SLASH),
                                                    LT(1, KC_ENTER),MT(MOD_LGUI, KC_TAB),                                DUAL_FUNC_6,    LT(2, KC_BSPC)
  ),
  [1] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F11,                                         KC_F12,         KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         
    KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_ESCAPE,                                      KC_EQUAL,       KC_SLASH,       KC_7,           KC_8,           KC_9,           KC_MINUS,       
    KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LBRC,        KC_RBRC,        KC_TRANSPARENT,                                 QK_LLCK,        KC_ASTR,        KC_4,           KC_5,           KC_6,           KC_PLUS,        
    KC_TRANSPARENT, KC_LPRN,        KC_RPRN,        KC_LCBR,        KC_RCBR,        KC_TAB,                                         KC_ENTER,       KC_0,           KC_1,           KC_2,           KC_3,           KC_DOT,         
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        RGB_VAD,        RGB_VAI,                                        KC_TRANSPARENT, KC_HOME,        LCTL(LSFT(KC_TAB)),KC_TRANSPARENT, LCTL(KC_TAB),   KC_PAGE_UP,     
    RGB_SPD,        RGB_SPI,        KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  HSV_204_255_255,                                KC_TRANSPARENT, KC_END,         KC_TRANSPARENT, KC_UP,          KC_TRANSPARENT, KC_PGDN,        
    KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT, HSV_43_255_255,                                 QK_LLCK,        KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HSV_74_255_255,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, NAVIGATOR_INC_CPI,KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, NAVIGATOR_DEC_CPI,KC_MS_BTN3,     KC_TRANSPARENT, TOGGLE_SCROLL,  KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, NAVIGATOR_AIM,  KC_MS_BTN2,     KC_MS_BTN1,     DRAG_SCROLL,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, NAVIGATOR_TURBO,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_MS_BTN1,     KC_MS_BTN2
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LPRN,        KC_RPRN,        LALT(LSFT(KC_LEFT)),LALT(LSFT(KC_RIGHT)),LALT(LSFT(KC_UP)),KC_TRANSPARENT,                                 KC_TRANSPARENT, LALT(KC_UP),    KC_TRANSPARENT, KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LCBR,        KC_RCBR,        KC_LBRC,        KC_RBRC,        LALT(LSFT(KC_DOWN)),KC_TRANSPARENT,                                 QK_LLCK,        LALT(KC_DOWN),  KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  '*', '*', '*', '*'
);




extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {205,251,241}, {205,251,241}, {205,251,241}, {205,251,241}, {205,251,241}, {205,251,241}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {143,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {213,255,255}, {213,255,255}, {0,0,0}, {0,0,0}, {213,255,255}, {213,255,255}, {213,255,255}, {213,255,255}, {143,255,255}, {0,0,0}, {0,0,0}, {205,251,241}, {205,251,241}, {205,251,241}, {205,251,241}, {205,251,241}, {205,251,241}, {219,160,255}, {219,160,255}, {93,255,255}, {93,255,255}, {93,255,255}, {219,160,255}, {169,255,255}, {219,160,255}, {93,255,255}, {93,255,255}, {93,255,255}, {219,160,255}, {143,255,255}, {93,255,255}, {93,255,255}, {93,255,255}, {93,255,255}, {219,160,255}, {0,0,0}, {43,255,255} },

    [2] = { {52,255,255}, {52,255,255}, {52,255,255}, {52,255,255}, {52,255,255}, {52,255,255}, {52,255,255}, {52,255,255}, {187,255,255}, {187,255,255}, {187,255,255}, {204,255,255}, {75,203,255}, {75,203,255}, {75,203,255}, {75,203,255}, {0,0,0}, {43,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {43,255,255}, {204,255,255}, {0,0,0}, {204,255,255}, {43,255,255}, {0,0,0}, {43,255,255}, {0,0,0}, {219,160,255}, {0,0,0}, {43,255,255}, {169,255,255}, {0,0,0}, {219,160,255}, {219,160,255}, {219,160,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {213,255,255}, {0,0,0}, {0,0,0}, {213,255,255}, {0,0,0}, {0,0,0}, {213,255,255}, {93,255,255}, {0,0,0}, {213,255,255}, {0,0,0}, {0,0,0}, {213,255,255}, {93,255,255}, {93,255,255}, {213,255,255}, {0,0,0}, {0,0,0}, {213,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {93,255,255}, {93,255,255} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {187,255,255}, {187,255,255}, {187,255,255}, {0,0,0}, {43,255,255}, {43,255,255}, {43,255,255}, {43,255,255}, {187,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {204,255,255}, {0,0,0}, {219,160,255}, {0,0,0}, {0,0,0}, {169,255,255}, {204,255,255}, {219,160,255}, {219,160,255}, {219,160,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
      case 3:
        set_layer_color(3);
        break;
      case 4:
        set_layer_color(4);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}

extern bool set_scrolling;
extern bool navigator_turbo;
extern bool navigator_aim;
void pointing_device_init_user(void) {
  set_auto_mouse_enable(true);
}

bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
  // All keys are not mouse keys when one shot auto mouse is enabled.
  return false;
}




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX: 
    // Mouse keys with modifiers work inconsistently across operating systems, this makes sure that modifiers are always
    // applied to the mouse key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
    if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_EQUAL);
        } else {
          unregister_code16(KC_EQUAL);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_ESCAPE);
        } else {
          unregister_code16(KC_ESCAPE);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_E);
        } else {
          unregister_code16(KC_E);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LALT(LGUI(LCTL(LSFT(KC_D)))));
        } else {
          unregister_code16(LALT(LGUI(LCTL(LSFT(KC_D)))));
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_R);
        } else {
          unregister_code16(KC_R);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LALT(LGUI(LCTL(LSFT(KC_R)))));
        } else {
          unregister_code16(LALT(LGUI(LCTL(LSFT(KC_R)))));
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_T);
        } else {
          unregister_code16(KC_T);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LALT(LGUI(LCTL(LSFT(KC_T)))));
        } else {
          unregister_code16(LALT(LGUI(LCTL(LSFT(KC_T)))));
        }  
      }  
      return false;
    case DUAL_FUNC_4:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_DELETE);
        } else {
          unregister_code16(KC_DELETE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(KC_GRAVE));
        } else {
          unregister_code16(LCTL(KC_GRAVE));
        }  
      }  
      return false;
    case DUAL_FUNC_5:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_O);
        } else {
          unregister_code16(KC_O);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LALT(LCTL(LSFT(KC_O))));
        } else {
          unregister_code16(LALT(LCTL(LSFT(KC_O))));
        }  
      }  
      return false;
    case DUAL_FUNC_6:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_SPACE);
        } else {
          unregister_code16(KC_SPACE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LGUI(LSFT(KC_M)));
        } else {
          unregister_code16(LGUI(LSFT(KC_M)));
        }  
      }  
      return false;
    case DRAG_SCROLL:
      if (record->event.pressed) {
        set_scrolling = true;
      } else {
        set_scrolling = false;
      }
      return false;
    case TOGGLE_SCROLL:
      if (record->event.pressed) {
        set_scrolling = !set_scrolling;
      }
      return false;
    break;
  case NAVIGATOR_TURBO:
    if (record->event.pressed) {
      navigator_turbo = true;
    } else {
      navigator_turbo = false;
    }
    return false;
  case NAVIGATOR_AIM:
    if (record->event.pressed) {
      navigator_aim = true;
    } else {
      navigator_aim = false;
    }
    return false;
  case NAVIGATOR_INC_CPI:
    if (record->event.pressed) {
        pointing_device_set_cpi(1);
    }
    return false;
  case NAVIGATOR_DEC_CPI:
    if (record->event.pressed) {
        pointing_device_set_cpi(0);
    }
    return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_204_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(204,255,255);
      }
      return false;
    case HSV_43_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(43,255,255);
      }
      return false;
    case HSV_74_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(74,255,255);
      }
      return false;
  }
  return true;
}
