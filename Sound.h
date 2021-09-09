#ifndef SOUND_H
#define SOUND_H

#include "Osc.h"

class SoundParaneters {
public:
    const float m_invAttenuationTime = 1.f;
};

class Sound {
public:
    void attack(float freq, float level = 1.f) { m_freq = freq, m_level = level; }
    void release() { m_level = 0; }
    float updateWave(float dt)
    {
        float wave = 0;
        wave += m_osc1.genTriangle(m_freq * dt);
        return 0.2f * wave * m_level * m_level;
    }

private:
    Osc m_osc1;
    float m_freq {};
    float m_level {};
};

#endif // SOUND_H
