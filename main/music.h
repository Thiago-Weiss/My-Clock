#ifndef MUSIC_H
#define MUSIC_H


#include <Arduino.h> 

#define BUZZER_PIN 11



struct Music {
  const int* notes;
  const int* duration;
  const byte* repeat;
  const int notesAmount;
  const int wholenote;
};

extern const Music* songs[];
extern const char* songsNames[];
extern uint8_t currentMusic;
extern const uint8_t songsNamesLimite;
extern bool playingMusic;

void startPlayMusic(const Music* song, byte repeat);
void stopPlayMusic();
void attPlayMusic();


#endif // MUSIC_H
