#ifndef SOUNDPROCESSOR_H
#define SOUNDPROCESSOR_H

#include "Sound.h"

#include <vector>

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
        for (auto& s : m_sounds) {
            s.m_level = glm::max(s.m_level - m_invSampleRate * invAtt, 0.f);
            wave += s.updateWave();
        }
        return wave;
    }
    void addSound(float freq, float level = 1.f)
    {
        m_sounds.push_back(Sound(freq * m_invSampleRate, level));
    }
    //void removeSound(float freq){}

private:
    SoundParaneters m_soundParams;
    std::vector<Sound> m_sounds;
    const float m_invSampleRate = 1.f / 44100.f;
};

#endif // SOUNDPROCESSOR_H
