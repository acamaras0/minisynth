#include "minisynth.h"

void wave_sin(SDL_AudioDeviceID audio_device, t_note *s)
{
    // pushing 3 seconds of samples to the audio buffer:
    float x = 0;
    for (int i = 0; i < FREQ * s->duration; i++) {
        x += .010f;

        // SDL_QueueAudio expects a signed 16-bit value
        // note: "5000" here is just gain so that we will hear something
        int16_t sample = sin(x * 4) * GAIN;

        const int sample_size = sizeof(int16_t) * 1;
        SDL_QueueAudio(audio_device, &sample, sample_size);
    }
}

int main(void) {
    SDL_Init(SDL_INIT_AUDIO);
    t_note *s;
    s->duration = 5;

    // the representation of our audio device in SDL:
    SDL_AudioDeviceID audio_device;

    // opening an audio device:
    SDL_AudioSpec audio_spec;
    SDL_zero(audio_spec);
    audio_spec.freq = FREQ;
    audio_spec.format = AUDIO_S16SYS;
    audio_spec.channels = CHANNELS;
    audio_spec.samples = SAMPLE;
    audio_spec.callback = NULL;

    audio_device = SDL_OpenAudioDevice(
        NULL, 0, &audio_spec, NULL, 0);
    wave_sin(audio_device, s);

    //unpausing the audio device (starts playing):
    SDL_PauseAudioDevice(audio_device, 0);

    SDL_Delay(3000);

    SDL_CloseAudioDevice(audio_device);
    SDL_Quit();

    return 0;
}