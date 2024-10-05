




#define BUZZER_PIN 11




#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
#define REST 0



byte deltaTime() {
  static unsigned int lastAtt = millis();
  static unsigned int currentAtt = millis();

  currentAtt = millis();
  if (lastAtt >= currentAtt) {
    lastAtt = currentAtt;
    return 0;
  }

  byte time = currentAtt - lastAtt;
  lastAtt = currentAtt;
  Serial.println(time);
  return time;
}



struct Music {
  const int* notes;
  const byte* duration;
  const byte* repeat;
  const byte notesAmount;
  const int wholenote;
};

// tetris
const int note1[] PROGMEM = { NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_A4, REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_GS4, NOTE_B4, REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4, NOTE_C5, NOTE_E5, NOTE_A5, NOTE_GS5 };
const byte duration1[] PROGMEM = { 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, -4, 8, 4, 4, 4, 4, 8, 4, 8, 8, -4, 8, 4, 8, 8, -4, 8, 4, 8, 8, 4, 8, 8, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 4, 8, 2, 2, 2, 2, 4, 4, 2, 2 };
const byte repeat1[] PROGMEM = { 41, 0, 0, 0 };
const byte notesAmount1 = 58;
const int wholenote1 = (60000 * 4) / 144;

Music song1 = { note1, duration1, repeat1, notesAmount1, wholenote1 };

// greenhill
const int note2[] PROGMEM = { REST, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, REST, NOTE_A4, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, REST, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, REST, NOTE_B4, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_D4, REST, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, REST, NOTE_A4, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, REST, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, REST, NOTE_B4, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_D4, NOTE_D4, NOTE_FS4, NOTE_E4, REST, NOTE_D4, NOTE_E4, NOTE_FS4, REST, NOTE_D4, NOTE_D4, NOTE_FS4, NOTE_F4, REST, NOTE_D4, NOTE_F4, NOTE_E4 };
const byte duration2[] PROGMEM = { 2, 8, 4, 8, 4, 8, 4, 2, 8, 8, 8, 4, 8, 4, 8, 4, 2, 4, 8, 4, 8, 4, 8, 4, 2, 8, 8, 8, 4, 8, 4, 8, 4, 2, 4, 8, 4, 8, 4, 8, 4, 2, 8, 8, 8, 4, 8, 4, 8, 4, 2, 4, 8, 4, 8, 4, 8, 4, 2, 8, 8, 8, 4, 8, 4, 8, 4, 8, 8, 8, -1, 8, 8, 8, -1, 8, 8, 8, 8, -1, 8, 8, 8, -1 };
const byte repeat2[] PROGMEM = { 84, 0, 0, 0 };
const byte notesAmount2 = 84;
const int wholenote2 = (60000 * 4) / 140;

Music song2 = { note2, duration2, repeat2, notesAmount2, wholenote2 };

// bloodytears
const int note3[] PROGMEM = { REST, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_G5, REST, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_A5, NOTE_G5, REST, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_D6, REST, NOTE_C6, REST, NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_C6, NOTE_F6, REST, REST, NOTE_G5, NOTE_D5, NOTE_D6, NOTE_D5, NOTE_C6, NOTE_D5, NOTE_AS5, NOTE_D5, NOTE_A5, NOTE_D5, NOTE_AS5, NOTE_D5, NOTE_A5, NOTE_D5, NOTE_G5, NOTE_D5, NOTE_A5, NOTE_D5, NOTE_AS5, NOTE_D5, NOTE_C6, NOTE_D5, NOTE_AS5, NOTE_D5, NOTE_A5, NOTE_D5, NOTE_F5, NOTE_D5, NOTE_A5, NOTE_D5, NOTE_G5, NOTE_D5, NOTE_C6, NOTE_C6, NOTE_F6, NOTE_D6, REST, REST, REST, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_F6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_F6, NOTE_D6, REST, REST, REST, NOTE_C6, NOTE_D6, NOTE_DS6, NOTE_F6, NOTE_D6, REST, NOTE_DS6, REST, NOTE_C6, NOTE_F6, NOTE_D6, REST, REST, REST, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_F6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_F6, NOTE_D6, REST, REST, REST, NOTE_C6, NOTE_D6, NOTE_DS6, NOTE_F6, NOTE_D5, NOTE_FS5, NOTE_F5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_AS5, NOTE_C6, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_D5, NOTE_D6, NOTE_D5, NOTE_C6, NOTE_D5, NOTE_AS5, NOTE_D5, NOTE_A5, NOTE_D5, NOTE_AS5, NOTE_D5, NOTE_A5, NOTE_D5, NOTE_G5, NOTE_D5, NOTE_A5, NOTE_D5, NOTE_AS5, NOTE_D5, NOTE_C6, NOTE_D5, NOTE_AS5, NOTE_D5, NOTE_A5, NOTE_D5, NOTE_F5, NOTE_D5, NOTE_A5, NOTE_D5, NOTE_G5, NOTE_D5, NOTE_AS5, NOTE_D5, NOTE_D6, NOTE_D5, NOTE_C6, NOTE_D5, NOTE_AS5, NOTE_D5, NOTE_A5, NOTE_D5, NOTE_AS5, NOTE_D5, NOTE_A5, NOTE_D5, NOTE_G5, NOTE_D5, NOTE_A5, NOTE_D5, NOTE_AS5, NOTE_D5, NOTE_C6, NOTE_D5, NOTE_AS5, NOTE_D5, NOTE_A5, NOTE_D5, NOTE_F5, NOTE_D5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_G5, NOTE_AS5, NOTE_G5, NOTE_C6, NOTE_G5, NOTE_D6, NOTE_G5, NOTE_C6, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_G5, NOTE_D6, NOTE_DS5, NOTE_D6, REST, NOTE_C5, REST, NOTE_A4, NOTE_AS4, NOTE_C5, NOTE_D6, NOTE_G4, NOTE_AS4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_D6, NOTE_G4, NOTE_C6, NOTE_F4, NOTE_A4, NOTE_F4, NOTE_F5, NOTE_F4, NOTE_D6, NOTE_DS4, NOTE_D6, REST, NOTE_E4, NOTE_F4 };
const byte duration3[] PROGMEM = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8, 8, 4, 4, 4, 8, 8, 8, 8, 4, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 16, 8, 4, 16, 16, -8, -8, -4, 8, 8, 8, 16, 8, 16, 8, 4, 8, 8, -8, -8, -8, 16, 8, 8, 8, 16, 8, 16, 8, 4, 8, 8, -8, -8, -4, 8, 8, 8, 16, 8, 16, 8, 4, 8, 8, -8, -8, 8, 8, 8, 8, -8, -4, -8, -4, -8, -4, 8, 8, 8, 8, -8, -8, 8, -8, -8, 8, -8, -8, 8, 4, 4, 4, 4, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 32, 32, 32, 32, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 4, 4, 8, 8, -16, -16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 16, 16 };
const byte repeat3[] PROGMEM = { 67, 35, 67, 35, 67, 35, 67, 35, 177, 145, 177, 145, 177, 145, 0, 0 };
const byte notesAmount3 = 253;
const int wholenote3 = (60000 * 4) / 144;

Music song3 = { note3, duration3, repeat3, notesAmount3, wholenote3 };

// cantinaband
const int note4[] PROGMEM = { NOTE_B4, NOTE_E5, NOTE_B4, NOTE_E5, NOTE_B4, NOTE_E5, NOTE_B4, REST, NOTE_AS4, NOTE_B4, NOTE_B4, NOTE_AS4, NOTE_B4, NOTE_A4, REST, NOTE_GS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_B4, NOTE_E5, NOTE_B4, NOTE_E5, NOTE_B4, NOTE_E5, NOTE_B4, REST, NOTE_AS4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E5, NOTE_B4, NOTE_E5, NOTE_B4, NOTE_E5, NOTE_B4, REST, NOTE_AS4, NOTE_B4, NOTE_D5, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_B4, NOTE_D5, NOTE_F5, NOTE_E5, NOTE_AS4, NOTE_AS4, NOTE_B4, NOTE_G4 };
const byte duration4[] PROGMEM = { -4, -4, -4, -4, 8, -4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, -2, -4, -4, -4, -4, 8, -4, 8, 8, 8, 8, -4, -4, 8, -4, 8, -4, -4, -4, -4, -4, -4, -4, 8, -4, 8, 8, 8, 8, 4, -4, 8, -4, -4, -2, 2, 2, 2, 2, -4, -4, 8, 8, 4, 4 };
const byte repeat4[] PROGMEM = { 64, 0, 0, 0 };
const byte notesAmount4 = 64;
const int wholenote4 = (60000 * 4) / 140;

Music song4 = { note4, duration4, repeat4, notesAmount4, wholenote4 };


Music* songs[] = { &song1, &song2, &song3, &song4 };


// padrao
bool playingMusic = true;
int currentDuration = 0;
int thisNote = 0;
byte notesRepeatPos = 0;
byte musicRepeat = 0;

// varia de musica pra musica
const int* notes = nullptr;
const byte* duration = nullptr;
const byte* repeats = nullptr;
byte notesAmount = 0;
int wholenote = 0;


void startPlayMusic(Music* song, byte repeat);

void startPlayMusic(Music* song, byte repeat) {
  // controle da musica
  playingMusic = true;
  thisNote = 0;
  notesRepeatPos = 0;
  currentDuration = 0;
  musicRepeat = repeat;

  // musica em si
  wholenote = song->wholenote;
  notesAmount = song->notesAmount;
  notes = song->notes;
  repeats = song->repeat;
  duration = song->duration;
}



void attPlayMusic() {
  if (!playingMusic) return;


  currentDuration -= deltaTime();

  if (currentDuration <= 0) {

    if (thisNote == pgm_read_byte(&repeats[notesRepeatPos])) {
      thisNote = pgm_read_byte(repeats[notesRepeatPos + 1]);
      notesRepeatPos += 2;
    }

    int divider = 0;
    int noteDuration = 0;

    noTone(BUZZER_PIN);

    // calculates the duration of each note
    divider = pgm_read_byte(&duration[thisNote]);

    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;  // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(BUZZER_PIN, pgm_read_word(&notes[thisNote]), noteDuration * 0.9);

    currentDuration = noteDuration;

    thisNote += 1;
    if (thisNote >= notesAmount) {
      if (musicRepeat >= 1) {
        musicRepeat--;
        thisNote = 0;
        notesRepeatPos = 0;
        currentDuration = 500;
      } else {
        playingMusic = false;
      }
    }
  }
}






void setup() {
  Serial.begin(9600);
  startPlayMusic(songs[2], 0);
  Serial.println("time");
}

void loop() {
  attPlayMusic();
}