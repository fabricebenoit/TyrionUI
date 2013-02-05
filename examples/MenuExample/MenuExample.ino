
#include <SoftwareSerial.h>
#include <serLCD.h>
#include "TyrionUI.h"


int LCDpin = 4;

// Assignation des pins pour le joystick
int pinHaut = 9;
int pinCentre = 8;
int pinGauche = 7;
int pinBas = 6;
int pinDroite = 5;

TyrionUI tyrion(LCDpin, pinHaut, pinBas, pinGauche, pinDroite, pinCentre);

void setup(){
  delay(1000);
  tyrion.init();
  //tyrion = new TyrionUI(LCDpin, pinHaut, pinBas, pinGauche, pinDroite, pinCentre);
  delay(1000);
  tyrion.disable();
  delay(1000);
  tyrion.enable();
}

void loop(){
  
}
