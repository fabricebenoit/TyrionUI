
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

int pages[] = {2, 4, 8, 3, 6};

//TyrionPage page1(1);

void setup(){
  delay(2000);
  
  
  
  tyrion.init(pages, 5);
  
  //tyrion.addPages(5);
  
  //delay(5000);
 // tyrion.setPage(page1);
  //tyrion.addPage(2,"TyrionUI","Page 2");
  //tyrion.createHome();
  //delay(1000);
  //tyrion.disable();
  //delay(1000);
  //tyrion.enable();
}

void loop(){
  int pageIndex = tyrion.updateState();
  //int paramIndex = 
  
  
  tyrion.updateScreen(String(pageIndex), String(tyrion.editMode));
  
  //joyCount[tyrion.updateState()]++;
  
  //String lg2 = String(joyCount[1]) + " " + String(joyCount[2]) + " " + String(joyCount[3]) + " " + String(joyCount[4]) + " " + String(joyCount[5]);
  //tyrion.updateScreen("", lg2);
  
}
