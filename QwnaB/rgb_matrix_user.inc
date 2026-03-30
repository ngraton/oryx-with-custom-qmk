// !!! DO NOT ADD #pragma once !!! //

RGB_MATRIX_EFFECT(CYBERPUNK_KNIGHT)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// Neon yellow scanner beam sweeping across a neon purple background.
// Bounces left-to-right-to-left like KITT from Knight Rider.
static bool CYBERPUNK_KNIGHT(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    // Neon purple background (HSV ~201, 255, v)
    // Neon yellow beam (HSV ~43, 255, v)
    const uint8_t bg_r = 0x8B, bg_g = 0x00, bg_b = 0xFF;  // neon purple

    // Speed-adjusted time; wraps 0-255
    uint8_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 4);

    // Triangle wave: convert sawtooth (0-255) to bounce (0-255-0)
    uint8_t pos = (time < 128) ? (time * 2) : (255 - (time - 128) * 2);
    // Moving right when time < 128, left when time >= 128
    bool moving_right = (time < 128);

    uint8_t val = rgb_matrix_config.hsv.v;  // respect user brightness

    // Background brightness: ~20% of user brightness
    uint8_t bg_dim = scale8(val, 50);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        uint8_t led_x = g_led_config.point[i].x;
        int16_t signed_dist = (int16_t)led_x - (int16_t)pos;

        // Trailing edge: behind the beam's direction of travel
        bool is_trailing = moving_right ? (signed_dist < 0) : (signed_dist > 0);
        int16_t abs_dist = abs(signed_dist);

        if (abs_dist == 0) {
            // Beam head: full neon yellow
            hsv_t hsv = {43, 255, val};
            rgb_t rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        } else if (is_trailing && abs_dist < 50) {
            // Trailing tail: yellow fading down, but not below background brightness
            uint8_t tail_v = scale8(val, 255 - (uint8_t)(abs_dist * 5));
            if (tail_v < bg_dim) tail_v = bg_dim;
            hsv_t hsv = {43, 255, tail_v};
            rgb_t rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        } else {
            // Background: neon purple
            rgb_matrix_set_color(i,
                scale8(bg_r, bg_dim),
                scale8(bg_g, bg_dim),
                scale8(bg_b, bg_dim));
        }
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
