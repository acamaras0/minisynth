#include "minisynth.h"

void wave_sine(SDL_AudioDeviceID audio_device, t_note *s)
{
    // pushing 3 seconds of samples to the audio buffer:
    for (int i = 0; i < FREQ * (s->tempo / 60) * s->duration; i++) 
    {
        // SDL_QueueAudio expects a signed 16-bit value
        // note: "5000" here is just gain so that we will hear something
        int16_t sample = sin((i / (float)FREQ) * 2.0f * M_PI * s->pitch) * GAIN;

        const int sample_size = sizeof(int16_t) * 1;
        SDL_QueueAudio(audio_device, &sample, sample_size);
    }
}

void wave_square(SDL_AudioDeviceID audio_device, t_note *s)
{
    float sine_value = 0.0;

    for (int i = 0; i < FREQ * (s->tempo / 60) * s->duration; i++) 
    {
        sine_value = sin(((float)i / (float)FREQ) * 2.0f * M_PI * s->pitch) * GAIN;
        sine_value += 1.0/3.0 * sin(((float)i*3 / (float)FREQ) * 2.0f * M_PI * s->pitch) * GAIN;
        sine_value += 1.0/5.0 * sin(((float)i*5 / (float)FREQ) * 2.0f * M_PI * s->pitch) * GAIN;
        sine_value += 1.0/7.0 * sin(((float)i*7 / (float)FREQ) * 2.0f * M_PI * s->pitch) * GAIN;
        sine_value += 1.0/9.0 * sin(((float)i*9 / (float)FREQ) * 2.0f * M_PI * s->pitch) * GAIN;
        sine_value += 1.0/11.0 * sin(((float)i*11 / (float)FREQ) * 2.0f * M_PI * s->pitch) * GAIN;

        int16_t sample = sine_value; 

        const int sample_size = sizeof(int16_t) * 1;
        SDL_QueueAudio(audio_device, &sample, sample_size);
    }
}

void wave_triangle(SDL_AudioDeviceID audio_device, t_note *s)
{
    float sine_value = 0.0;
    for (int i = 0; i < FREQ * s->duration; i++) 
    {
        sine_value = (sin(((float)i / (float)FREQ) * 2.0f * M_PI * s->pitch) * GAIN) + 2 + pow(3, -2);
        sine_value *= -(sin(((float)i*3 / (float)FREQ) * 2.0f * M_PI * s->pitch) * GAIN) + pow(5, -2);
        sine_value *= (sin(((float)i*5 / (float)FREQ) * 2.0f * M_PI * s->pitch) * GAIN) + pow(7, -2);

        int16_t sample = sine_value;

        const int sample_size = sizeof(int16_t) * 1;
        SDL_QueueAudio(audio_device, &sample, sample_size);
    }
}

void wave_saw(SDL_AudioDeviceID audio_device, t_note *s)
{
    for (int i = 0; i < FREQ * (s->tempo / 60) * s->duration; i++) 
    {
        int16_t sample = (-((1.5f * GAIN)/ M_PI) * (tan(-(s->pitch * (float)i / (float)FREQ))));

        const int sample_size = sizeof(int16_t) * 1;
        SDL_QueueAudio(audio_device, &sample, sample_size);
    }
}
