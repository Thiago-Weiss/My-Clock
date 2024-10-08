#include "funcsBnt.h"
#include "utils.h"
#include "save_load.h"
#include "Gvars.h"
#include "music.h"


// funcs
static void configDataValues();


void bnt_1_Funcs() {
  if (displayTurnOn()) return;
  if (alarmOff()) return;


  backMenuTimer.reset();
  lcd.clear();
  cursor = 0;
  nextVal(&currentWindows, WINDOWS_LIMITE);

  // preenche os campos de configuraçao de data
  switch (currentWindows) {
    case DATA:
      {
        stopPlayMusic();
        configDataValues();
        break;
      }
    case MENU:{
      saveAll();
    }
  }
}


void bnt_2_Funcs() {
  if (displayTurnOn()) return;
  if (alarmOff()) return;


  switch (currentWindows) {
    case MENU:
      {
        // faz nada
        break;
      }
    case ALARME_1:
      {
        nextVal(&cursor, cursorAlarmLimite);
        break;
      }
    case ALARME_2:
      {
        nextVal(&cursor, cursorAlarmLimite);
        break;
      }
    case SOUND:
      {
        previousVal(&currentMusic, songsNamesLimite);
        startPlayMusic(songs[currentMusic], 0);
        break;
      }
    case DATA:
      {
        nextVal(&cursor, cursorDataLimite);
        break;
      }
  }
}



void bnt_3_Funcs() {
  if (displayTurnOn()) return;
  if (alarmOff()) return;

  switch (currentWindows) {
    case MENU:
      {
        // faz nada
        break;
      }
    case ALARME_1:
      {
        nextVal(&alarme1[cursor], maxAlarme[cursor]);
        break;
      }
    case ALARME_2:
      {
        nextVal(&alarme2[cursor], maxAlarme[cursor]);
        break;
      }
    case SOUND:
      {
        nextVal(&currentMusic, songsNamesLimite);
        startPlayMusic(songs[currentMusic], 0);
        break;
      }
    case DATA:
      {
        if (cursor == cursorDataLimite) {
          // data         DD/MM/AA - d hh:mm Button 
          // seconds, minutes, hours, day of the week, day of the month, month, year
          myRTC.setDS1302Time(0, data[5], data[4], data[3], data[0], data[1], data[2]);
          backMenu();
        }
        nextVal(&data[cursor], maxData[cursor]);
        break;
      }
  }
}



static void configDataValues() {
  // data         hh:mm - DD/MM/AA - d

  data[0] = myRTC.hours;
  data[1] = myRTC.minutes;
  data[2] = myRTC.dayofmonth;
  data[3] = myRTC.month;
  data[4] = myRTC.year;
  data[5] = myRTC.dayofweek;
}



