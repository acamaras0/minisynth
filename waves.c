#include "minisynth.h"

void wave_sine(SDL_AudioDeviceID audio_device, t_note *s)
{
    // pushing 3 seconds of samples to the audio buffer:
    for (int i = 0; i < FREQ * s->duration; i++) 
    {
        // SDL_QueueAudio expects a signed 16-bit value
        // note: "5000" here is just gain so that we will hear something
        int16_t sample = sin(((float)i / (float)FREQ) * 2.0f * M_PI * s->pitch) * GAIN;

        const int sample_size = sizeof(int16_t) * 1;
        SDL_QueueAudio(audio_device, &sample, sample_size);
    }
}

void wave_square(SDL_AudioDeviceID audio_device, t_note *s)
{

    for (int i = 0; i < FREQ * s->duration; i++) 
    {
        int16_t sample = sin(((float)i / (float)FREQ) * 2.0f * M_PI * s->pitch) * GAIN;

        const int sample_size = sizeof(int16_t) * 1;
        SDL_QueueAudio(audio_device, &sample, sample_size);
    }
}

void wave_triangle(SDL_AudioDeviceID audio_device, t_note *s)
{
    for (int i = 0; i < FREQ * s->duration; i++) 
    {
        int16_t sample = sin(((float)i / (float)FREQ) * 2.0f * M_PI * s->pitch) * GAIN;

        const int sample_size = sizeof(int16_t) * 1;
        SDL_QueueAudio(audio_device, &sample, sample_size);
    }
}

void wave_saw(SDL_AudioDeviceID audio_device, t_note *s)
{
    for (int i = 0; i < FREQ * s->duration; i++) 
    {
        int16_t sample = sin(((float)i / (float)FREQ) * 2.0f * M_PI * s->pitch) * GAIN;

        const int sample_size = sizeof(int16_t) * 1;
        SDL_QueueAudio(audio_device, &sample, sample_size);
    }
}