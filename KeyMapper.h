#ifndef TONEMAPPER_H
#define TONEMAPPER_H

#include "SDL2/SDL_keycode.h"

#include <optional>
#include <unordered_map>

#include <math.h>

class KeyMapper {
public:
    static KeyMapper& get()
    {
        return m_staticToneMapper;
    }
    bool getTone(SDL_Keycode key, int& tone)
    {
        std::optional<int> result;
        auto it = m_keyToneMap.find(key);
        if (it != m_keyToneMap.end()) {
            tone = it->second;
            return true;
        }
        return false;
    }

private:
    KeyMapper();
    static KeyMapper m_staticToneMapper;
    std::unordered_map<SDL_Keycode, int> m_keyToneMap;
};

#endif // TONEMAPPER_H
