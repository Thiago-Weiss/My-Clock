#ifndef GVARS_H
#define GVARS_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "Button.h"


// lcd
extern LiquidCrystal_I2C lcd;

// bnt
extern Button bnt2;
extern Button bnt3;
extern Button bnt1;


// Controle
extern byte asd;

// Enum para as telas
enum SCREENS {
    MENU,    
    ALARME_1,    
    ALARME_2,    
    CONFIG_ALARME   
};

// Alarmes
extern byte alarme1[];
extern byte alarme2[];
extern byte *alarmes[];
extern byte maxAlarme[];

// Dados do alarme
extern byte posAlarme;
extern byte posAlarmeLimite;

// Dados
extern byte data[];
extern byte maxData[];
extern byte posData;
extern byte posDataLimite;

// Dados da tela
extern byte telaAtual;
extern byte telaLimite;

// Textos
extern String linha1;
extern String linha2;

#endif // GVARS_H
