#ifndef MUSIC_H
#define MUSIC_H

#include "music.h"
#include <Arduino.h> 

#define BUZZER_PIN 6

struct  Music {
  const int* notes;
  const byte* duration;
  const byte* repeat;
  const byte notesAmount;
  const int wholenote;
};

extern Music* songs[];

void startPlayMusic(Music* song, byte repeat);
void attPlayMusic();


#endif // MUSIC_H
