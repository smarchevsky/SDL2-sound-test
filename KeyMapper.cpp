#include "KeyMapper.h"

#include <unordered_map>

KeyMapper KeyMapper::m_staticToneMapper = {};

KeyMapper::KeyMapper()
{
    std::unordered_map<SDL_Keycode, int> keyToneMap {
#define OCTAVE 0
        { SDLK_CAPSLOCK, -15 + OCTAVE },
        { SDLK_LSHIFT, -14 + OCTAVE },
        { SDLK_a, -13 + OCTAVE },
        { SDLK_z, -12 + OCTAVE },
        { SDLK_s, -11 + OCTAVE },
        { SDLK_x, -10 + OCTAVE },
        { SDLK_c, -9 + OCTAVE },
        { SDLK_f, -8 + OCTAVE },
        { SDLK_v, -7 + OCTAVE },
        { SDLK_g, -6 + OCTAVE },
        { SDLK_b, -5 + OCTAVE },
        { SDLK_n, -4 + OCTAVE },
        { SDLK_j, -3 + OCTAVE },
        { SDLK_m, -2 + OCTAVE },
        { SDLK_k, -1 + OCTAVE },
        { SDLK_COMMA, 0 + OCTAVE },
        { SDLK_l, 1 + OCTAVE },
        { SDLK_PERIOD, 2 + OCTAVE },
        { SDLK_SLASH, 3 + OCTAVE },
        { SDLK_QUOTE, 4 + OCTAVE },
        { SDLK_RSHIFT, 5 + OCTAVE },
#undef OCTAVE
#define OCTAVE -36
        { SDLK_TAB, 0 + OCTAVE },
        { SDLK_1, 2 + OCTAVE },
        { SDLK_q, 3 + OCTAVE },
        { SDLK_2, 4 + OCTAVE },
        { SDLK_w, 5 + OCTAVE },
        { SDLK_3, 6 + OCTAVE },
        { SDLK_e, 7 + OCTAVE },
        { SDLK_r, 8 + OCTAVE },
        { SDLK_5, 9 + OCTAVE },
        { SDLK_t, 10 + OCTAVE },
        { SDLK_6, 11 + OCTAVE },
        { SDLK_y, 12 + OCTAVE },
        { SDLK_7, 13 + OCTAVE },
        { SDLK_u, 14 + OCTAVE },
        { SDLK_i, 15 + OCTAVE },
        { SDLK_9, 16 + OCTAVE },
        { SDLK_o, 17 + OCTAVE },
        { SDLK_0, 18 + OCTAVE },
        { SDLK_p, 19 + OCTAVE },
        { SDLK_LEFTBRACKET, 20 + OCTAVE },
        { SDLK_EQUALS, 21 + OCTAVE },
        { SDLK_RIGHTBRACKET, 22 + OCTAVE },
        { SDLK_BACKSPACE, 23 + OCTAVE },
        { SDLK_BACKSLASH, 24 + OCTAVE },

#undef OCTAVE
    };
    m_keyToneMap = std::move(keyToneMap);
}
