#ifndef MINISYNTH_H
# define MINISYNTH_H

# include <stdio.h>
# include <SDL.h>
# include <math.h>
# define SAMPLE 1024
# define FREQ 44100
# define CHANNELS 2
# define GAIN 5000

# define A 27.50
# define B 30.87
# define C 16.35
# define D 18.35
# define E 20.60
# define F 21.83
# define G 24.50
# define R 0

typedef     struct s_note
{
    double duration;
    char alternation;
    int octave;
    double pitch;
    int tempo;
}                  t_note;

void wave_sine(SDL_AudioDeviceID audio_device, t_note *s);
void wave_square(SDL_AudioDeviceID audio_device, t_note *s);
void wave_triangle(SDL_AudioDeviceID audio_device, t_note *s);
void wave_saw(SDL_AudioDeviceID audio_device, t_note *s);

#endif