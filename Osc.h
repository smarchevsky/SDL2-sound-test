#ifndef OSC_H
#define OSC_H

#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>

class Osc {
public:
    Osc() { }
    float genSine(float freq)
    {
        float x = (updatedPhase(freq) - .5f) * 2.f;
        return (4.f * x) * (1.f - fabs(x));
    }
    float genSaw(float freq) { return updatedPhase(freq) * 2.f - 1.f; }
    float genTriangle(float freq) { return m_phase * 4.f + glm::clamp(2.f - updatedPhase(freq) * 8.f, -4.f, 0.f); }
    float genSquare(float freq) { return updatedPhase(freq) > .5f ? -1.f : 1.f; }
    static float genWhiteNoise() { return glm::linearRand(-1.f, 1.f); }

private:
    float updatedPhase(float freqSampleRateScale)
    {
        m_phase = glm::fract<float>(m_phase + freqSampleRateScale);
        return m_phase;
    }
    float m_phase = 0;
};

#endif // OSC_H
