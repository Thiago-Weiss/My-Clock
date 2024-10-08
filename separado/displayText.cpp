#include "displayText.h"
#include "Gvars.h"
#include "music.h"

// text
static char linha1[18] = { '\0' };
static char linha2[18] = { '\0' };

// mains funcs
static void showMenuLinha1();
static void showMenuLinha2();
static void showMenuLinha2Data();
static void showMenuLinha2Temp();
static void showAlarm(uint8_t alarme[]);
static void showConfigData();
static void showConfigSound();
static void showAlarmPlayScreen();

// auxiliarys funcs
static void dayOfWeek(uint8_t dayW, char* result);
static void numToText(uint8_t val, char* result);
static void formatNum(uint8_t val, char* result, uint8_t pos);
static void formatDay(uint8_t val, char* result);



void displayText() {


  switch (currentWindows) {
    case MENU:
      {
        showMenuLinha1();
        showMenuLinha2();
        break;
      }
    case ALARME_1:
      {
        showAlarm(alarme1);
        break;
      }
    case ALARME_2:
      {
        showAlarm(alarme2);
        break;
      }
    case SOUND:
      {
        showConfigSound();
        break;
      }
    case DATA:
      {

        showConfigData();
        break;
      }
    case ALARME_PLAYING:
      {
        showAlarmPlayScreen();
        break;
      }
  }

  lcd.setCursor(0, 0);
  lcd.print(linha1);
  lcd.setCursor(0, 1);
  lcd.print(linha2);
}

static void showMenuLinha1() {
  char result[9];

  // linha1 = "hh:mm:ss sabado ";
  numToText(myRTC.hours, result);
  strcpy(linha1, result);
  strcat(linha1, ":");

  numToText(myRTC.minutes, result);
  strcat(linha1, result);
  strcat(linha1, ":");

  numToText(myRTC.seconds, result);
  strcat(linha1, result);
  strcat(linha1, " ");

  dayOfWeek(myRTC.dayofweek, result);
  strcat(linha1, result);
}

static void showMenuLinha2() {
  static bool data_temp = true;
  static uint8_t timerTrocaLimite = 6;
  static uint8_t timerTroca = 0;
  static uint8_t lastSec = 0;

  if (myRTC.seconds != lastSec) {
    lastSec = myRTC.seconds;
    timerTroca += 1;
    if (timerTroca > timerTrocaLimite) {
      timerTroca = 0;
      data_temp = !data_temp;
    }
  }

  if (data_temp) {
    showMenuLinha2Data();
  } else {
    showMenuLinha2Temp();
  }
}


static void showMenuLinha2Data() {
  char result[9];

  // linha2 = "-- dd/mm/aaaa--";
  strcpy(linha2, "-- ");

  numToText(myRTC.dayofmonth, result);
  strcat(linha2, result);
  strcat(linha2, "/");

  numToText(myRTC.month, result);
  strcat(linha2, result);
  strcat(linha2, "/");

  numToText(myRTC.year, result);
  strcat(linha2, result);
  strcat(linha2, " --");
}


static void showMenuLinha2Temp() {
  sensors_event_t humidity, temp;
  sensorTemp.getEvent(&humidity, &temp);
  char buffer[5];

  // linha2 = "Temp:_30c_H:_50%";
  strcpy(linha2, "Temp: ");

  itoa(temp.temperature, buffer, 10);
  strcat(linha2, buffer);
  strcat(linha2, "C");
  if (temp.temperature < 10) {
    strcat(linha2, " ");
  }
  strcat(linha2, " H: ");

  itoa(humidity.relative_humidity, buffer, 10);
  strcat(linha2, buffer);
  strcat(linha2, "%");
}



static void showAlarm(uint8_t alarme[]) {
  char result[9];

  // linha1 ">HH<:_MM_alarm_1"
  formatNum(alarme[0], result, 0);
  strcpy(linha1, result);
  strcat(linha1, ":");

  formatNum(alarme[1], result, 1);
  strcat(linha1, result);
  strcat(linha1, "alarm ");
  char alarm_num[3];
  itoa(currentWindows, alarm_num, 10);
  strcat(linha1, alarm_num);


  // linha2 "_d-s-t-q-q-s-s__"
  strcpy(linha2, (cursor == 2 ? "" : " "));


  for (int i = 2; i < cursorAlarmLimite; i++) {
    formatDay(i - 1, result);
    if (alarme[i]) {
      result[0] = toupper(result[0]);
    }
    if (cursor == i) {
      char buffer[4] = ">";
      strcat(buffer, result);
      strcat(buffer, "<");
      strcpy(result, buffer);
    } else if (i != cursorAlarmLimite - 1 && i + 1 != cursor) {
      strcat(result, "-");
    }

    strcat(linha2, result);
  }
  strcat(linha2, "  ");
}


static void showConfigSound() {
  // linha1 "alarm 1-2  music"
  strcpy(linha1, "alarm 1-2  music");
  // linha1 "<     name     >"
  strcpy(linha2, songsNames[currentMusic]);
}

static void showConfigData() {
  char result[9];

  // linha1 "_dd/mm/aaaa_day_"
  strcpy(linha1, (cursor == 0 ? "" : " "));
  for (int i = 0; i < 3; i++) {
    numToText(data[i], result);
    if (i == 2) {
      char buffer[5] = "20";
      strcat(buffer, result);
      strcpy(result, buffer);
    }
    if (cursor == i) {
      char buffer[7] = ">";
      strcat(buffer, result);
      strcat(buffer, "<");
      strcpy(result, buffer);
    } else if (i != 2 && i + 1 != cursor) {
      strcat(result, "/");
    }
    strcat(linha1, result);
  }

  // linha1 "_dd/mm/aaaa_day_"
  dayOfWeek(data[3] + 1, result);
  result[3] = '\0';
  if (cursor == 3) {
    strcat(linha1, ">");
    strcat(linha1, result);
    strcat(linha1, "<");
  } else if (cursor == 2) {
    strcat(linha1, result);
    strcat(linha1, " ");
  } else {
    strcat(linha1, " ");
    strcat(linha1, result);
    strcat(linha1, " ");
  }


  // linha2 "_HH_:_MM__Data__"
  formatNum(data[5], result, 4);
  strcpy(linha2, result);
  strcat(linha2, ":");

  formatNum(data[6], result, 5);
  strcat(linha2, result);
  strcat(linha2, (cursor == 6 ? ">Data?<" : " Data  "));
}



static void showAlarmPlayScreen() {

  // linha1 "--- Alarm 1  ---"
  strcpy(linha1, "--- Alarm ");

  char buffer[9];
  itoa(alarmPlaying, buffer, 10);
  strcat(linha1, buffer);

  strcat(linha1, "  ---");



  // linha2 "18:30 20/04  sab"
  uint8_t* alarme = (alarmPlaying == 1 ? alarme1 : alarme2);

  numToText(alarme[0], buffer);
  strcpy(linha2, buffer);
  strcat(linha2, ":");

  numToText(alarme[1], buffer);
  strcat(linha2, buffer);
  strcat(linha2, " ");

  numToText(myRTC.dayofmonth, buffer);
  strcat(linha2, buffer);
  strcat(linha2, "/");

  numToText(myRTC.month, buffer);
  strcat(linha2, buffer);
  strcat(linha2, "  ");

  dayOfWeek(myRTC.dayofweek, buffer);
  buffer[3] = '\0';
  strcat(linha2, buffer);
}






static void dayOfWeek(uint8_t dayW, char* result) {
  switch (dayW) {
    case 1:
      strcpy(result, "Domingo");
      break;
    case 2:
      strcpy(result, "Segunda");
      break;
    case 3:
      strcpy(result, "Terca  ");
      break;
    case 4:
      strcpy(result, "Quarta ");
      break;
    case 5:
      strcpy(result, "Quinta ");
      break;
    case 6:
      strcpy(result, "Sexta  ");
      break;
    case 7:
      strcpy(result, "Sabado ");
      break;
    default:
      strcpy(result, '\0');
  }
}

static void numToText(uint8_t val, char* result) {
  if (val < 10) {
    strcpy(result, "0");

    char buffer[3];
    itoa(val, buffer, 10);

    strcat(result, buffer);
  } else {
    itoa(val, result, 10);
  }
}

static void formatNum(uint8_t val, char* result, uint8_t pos) {
  numToText(val, result);
  if (cursor == pos) {
    char buffer[5] = ">";
    strcat(buffer, result);
    strcat(buffer, "<");
    strcpy(result, buffer);
  } else {
    char buffer[5] = " ";
    strcat(buffer, result);
    strcat(buffer, " ");
    strcpy(result, buffer);
  }
}


static void formatDay(uint8_t val, char* result) {
  dayOfWeek(val, result);
  result[0] = tolower(result[0]);
  result[1] = '\0';
}
