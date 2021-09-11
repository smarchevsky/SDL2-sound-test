#ifndef SOUND_H
#define SOUND_H

#include "Osc.h"

struct Sound {
public:
    Sound() = default;
    Sound(float sampleRateFreq, float level = 1.f) { attack(sampleRateFreq, level); }
    void attack(float sampleRateFreq, float level = 1.f) { m_sampleRateFreq = sampleRateFreq, m_level = level; }
    void release() { m_level = 0; }
    float updateWave()
    {
        float wave = 0.f;
        wave += m_osc1.genSine(m_sampleRateFreq);
        wave += m_osc2.genSine(m_sampleRateFreq * 2.004f) * 0.5f;
        wave += m_osc3.genTriangle(m_sampleRateFreq * 4.004f) * 0.15f;
        return 0.2f * wave * m_level * m_level;
    }

    float m_sampleRateFreq {};
    float m_level {};
    int tone = 0;
private:
    Osc m_osc1;
    Osc m_osc2;
    Osc m_osc3;

};

#endif // SOUND_H
