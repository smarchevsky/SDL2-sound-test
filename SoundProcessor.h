#ifndef SOUNDPROCESSOR_H
#define SOUNDPROCESSOR_H

#include "Sound.h"

#include <vector>

static float getToneMultiplier(int tone) { return 440.f * powf(2.f, tone / 12.f); }

#define POLYFONY_MAX_SIZE 1024

class SoundParaneters {
public:
    void setAttenuationTime(float time) { m_invAttenuationTime = 1.f / time; }
    float m_invAttenuationTime = .2f;
};

//template <class SoundType = Sound>
class SoundProcessor {
public:
    SoundProcessor(float sampleRate)
        : m_invSampleRate(1.f / sampleRate)
    {
    }
    float update()
    {
        float wave = 0.f;
        const float& invAtt = m_soundParams.m_invAttenuationTime;
        for (int i = 0; i < m_polyCount; ++i) {
            auto& s = m_sounds[i];
            s.m_level = glm::max(s.m_level - m_invSampleRate * invAtt, 0.f);
            wave += s.updateWave();
        }
        return wave;
    }

    void addSound(int tone, float level = 1.f)
    {
        if (m_polyCount < POLYFONY_MAX_SIZE) {
            float freq = getToneMultiplier(tone);
            m_sounds[m_polyCount] = Sound(freq * m_invSampleRate, level);
            m_sounds[m_polyCount].tone = tone;
            m_polyCount++;
        }
    }
    void removeSound(int tone)
    {
        for (int i = 0; i < m_polyCount; ++i) {
            auto& s = m_sounds[i];
            if (s.tone == tone) {
                --m_polyCount;
                std::swap(m_sounds[i], m_sounds[m_polyCount]);
            }
        }
    }

private:
    SoundParaneters m_soundParams;
    std::size_t m_polyCount {};
    Sound m_sounds[POLYFONY_MAX_SIZE];
    const float m_invSampleRate = 1.f / 44100.f;
};

#endif // SOUNDPROCESSOR_H
