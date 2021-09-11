#ifndef REVERBERATIONBUFFER_H
#define REVERBERATIONBUFFER_H

#include <glm/glm.hpp>

template <int32_t BufferSize = 4096>
struct ReverberationBuffer {
    int32_t currentElement = 0;
    float m_sound[BufferSize] {};

    // write current wave position
    void write(float val) { m_sound[currentElement++ % BufferSize] = val; }

    // read delayed wave position, must be >= 0
    float read(int32_t offset)
    {
        return m_sound[(BufferSize - glm::min(offset, BufferSize - 1) + currentElement) % BufferSize];
    }
    float readFloat(float offset)
    {
        int p0 = glm::floor(offset);
        int p1 = glm::floor(offset + 1);
        float fract = glm::fract(offset);
        float s0 = m_sound[(BufferSize - glm::min(p0, BufferSize - 1) + currentElement) % BufferSize];
        float s1 = m_sound[(BufferSize - glm::min(p1, BufferSize - 1) + currentElement) % BufferSize];
        return glm::mix(p0, p1, fract);
    }
    constexpr int32_t getSize() { return BufferSize; }
};

#endif // REVERBERATIONBUFFER_H
