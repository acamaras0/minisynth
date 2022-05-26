#include "minisynth.h"

int main(void) 
{
    SDL_Init(SDL_INIT_AUDIO);
    t_note *s;
    s->tempo = 110;
    s->duration = 5;
    s->pitch = A * 4 ; // note * 16 = note4 (A * 16 = A4)

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
    //wave_sine(audio_device, s);
    //wave_square(audio_device, s);
    wave_saw(audio_device, s);
    //wave_triangle(audio_device, s);

    //unpausing the audio device (starts playing):
    SDL_PauseAudioDevice(audio_device, 0);

    SDL_Delay(3000);

    SDL_CloseAudioDevice(audio_device);
    SDL_Quit();

    return 0;
}