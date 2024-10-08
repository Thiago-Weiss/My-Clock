#ifndef MUSIC_H
#define MUSIC_H


#include <Arduino.h> 

#define BUZZER_PIN 6



struct Music {
  const int* notes;
  const int* duration;
  const byte* repeat;
  const int notesAmount;
  const int wholenote;
};

extern const Music* songs[];
extern const char* songsNames[];
extern const uint8_t songsNamesLimite;
extern bool playingMusic;

void startPlayMusic(Music* song, byte repeat);
void attPlayMusic();


#endif // MUSIC_H
