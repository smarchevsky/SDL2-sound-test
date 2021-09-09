#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#include<glm/glm.hpp>
#include<glm/gtc/random.hpp>

#include <iostream>

#define LOG(x) std::cout << x << std::endl

SDL_Window* gWindow = NULL;
const int SAMPLE_RATE = 44100;
const float INV_SR = 1.f / SAMPLE_RATE;

float sigmoid(float x) { return x / (abs(x) + 1); }

void audio_callback(void* user_data, Uint8* raw_buffer, int bytes)
{
    Sint16* buffer = (Sint16*)raw_buffer;
    int length = bytes / 2; // 2 bytes per sample for AUDIO_S16SYS
    float* soundTime = reinterpret_cast<float*>(user_data);
    if (!soundTime)
        return;
    for (int sampleIndex = 0; sampleIndex < length; ++sampleIndex) {
        *soundTime = glm::fract(*soundTime + INV_SR);
        float sound = sin(*soundTime * 1000.f * M_PI) * 0.1f;
        //sound = glm::linearRand(-1.f, 1.f);
        buffer[sampleIndex] = (Sint16)(32767 * glm::clamp(sigmoid(sound), -1.f, 1.f));
    }
}


int main()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return -1;
    } else {
        gWindow = SDL_CreateWindow("Sound test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 320, 240, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            return -1;
        } else {
            if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
                printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
                return -1;
            }
        }
    }
    float time = 0;
    SDL_AudioSpec want;
    want.freq = SAMPLE_RATE;
    want.format = AUDIO_S16SYS; // sample type (signed short 16 bit)
    want.channels = 1;
    want.samples = 2048;
    want.callback = audio_callback;
    want.userdata = &time;

    SDL_AudioSpec have;
    SDL_AudioDeviceID audio_device = SDL_OpenAudioDevice(nullptr, 0, &want, &have, 0);
    SDL_PauseAudioDevice(audio_device, 0);

    //SDL_PauseAudioDevice(audio_device, 1);

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.key.repeat == 0) {

                auto keyId = e.key.keysym.sym;
                //if (keyId == SDLK_ESCAPE)
                //    quit = true;

            }
        }
    }

    SDL_CloseAudioDevice(audio_device);
    SDL_DestroyWindow(gWindow);

    Mix_Quit();
    SDL_Quit();
}
