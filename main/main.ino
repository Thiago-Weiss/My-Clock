#include <Wire.h>

#include "Gvars.h"
#include "displayText.h"
#include "save_load.h"
#include "music.h"
#include "utils.h"







void setup() {
  if (!sensorTemp.begin()) {
    while (1) delay(10);
  }
  // talvez fazer um firts load pra zerra todos os valores
  // load data
  load_all();

  // buzzer
  pinMode(BUZZER_PIN, OUTPUT);

  noTone(BUZZER_PIN);

  Serial.begin(9600);

  // lcd
  pinMode(LCD_LIGHT, OUTPUT);
  digitalWrite(LCD_LIGHT, HIGH);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  backMenuTimer.stop();
}

void loop() {
  if (!playingMusic) delay(45);

  myRTC.updateTime();

  bnt1.att();
  bnt2.att();
  bnt3.att();

  attPlayMusic();

  backMenuTimer.att();
  displayOffTimer.att();
  alarmTimer.att();

  displayText();
}
