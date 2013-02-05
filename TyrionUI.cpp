/*
 TyrionUI.cpp - Arduino UI.
 Created by Fabrice BENOIT, January 10, 2013
 Released into the public domain.
 */

#include "Arduino.h"
#include "TyrionUI.h"

TyrionUI::TyrionUI(int pinLCD, int pinT, int pinB, int pinL, int pinR, int pinC) : _screen(pinLCD)
{
    _enabled = true;
    
    _pinLCD = pinLCD;
    _pinT = pinT;
    _pinB = pinB;
    _pinL = pinL;
    _pinR = pinR;
    _pinC = pinC;
    
    // Les pins connectés au joystick sont configurés en entrées
    pinMode(_pinT, INPUT);
    pinMode(_pinB, INPUT);
    pinMode(_pinL, INPUT);
    pinMode(_pinR, INPUT);
    pinMode(_pinC, INPUT);
    
    // On active les résistances internes des pin Arduino pour avoir des valeurs cohérentes
    digitalWrite(_pinT, HIGH);
    digitalWrite(_pinB, HIGH);
    digitalWrite(_pinL, HIGH);
    digitalWrite(_pinR, HIGH);
    digitalWrite(_pinC, HIGH);
}

void TyrionUI::init(){
    _screen.clear();
    enable();
    
    delay(500);
    
    _screen.print("Tyrion UI");
    
    
    byte invader[8] = {
      B00000,
      B01110,
      B11111,
      B10101,
      B11111,
      B01010,
      B10101,
      B00000
    };
    
    byte chrono[8]={
      B00000,
      B00100,
      B01110,
      B10001,
      B10111,
      B10101,
      B01110,
      B00000
    };
    
    byte lab[8]={
      B00000,
      B11011,
      B01010,
      B01010,
      B10001,
      B10001,
      B01110,
      B00000
    };
    
    
    byte bandes[8]={
      B00000,
      B10101,
      B01011,
      B00111,
      B01011,
      B10101,
      B01011,
      B00000
    };
    
    byte expo[8]={
      B00000,
      B11111,
      B10001,
      B10001,
      B10001,
      B10001,
      B11111,
      B00000
    };
 
   byte soleil[8]={
      B00000,
      B00000,
      B10101,
      B01110,
      B11111,
      B01110,
      B10101,
      B00000
    };
    
    byte ampoule[8]={
      B00000,
      B11111,
      B10001,
      B11111,
      B00100,
      B01010,
      B10001,
      B00000
    };

    _screen.createChar(1, invader);
    _screen.createChar(2, chrono);
    _screen.createChar(3, lab);
    _screen.createChar(4, bandes);
    _screen.createChar(5, expo);
    _screen.createChar(6, soleil);
    _screen.createChar(7, ampoule);
    
    _screen.setCursor(2,1);
    _screen.printCustomChar(1);
    _screen.printCustomChar(2);
    _screen.printCustomChar(3);
    _screen.printCustomChar(4);
    _screen.printCustomChar(5);
    _screen.printCustomChar(6);
    _screen.printCustomChar(7);
    //_screen.print("X");

}

void TyrionUI::disable()
{
  _enabled = false;
  _screen.noDisplay();
  _screen.setBrightness(1);
}

void TyrionUI::enable()
{
  _enabled = true;
  _screen.display();
  _screen.setBrightness(30);
}

boolean TyrionUI::isEnabled()
{
    return _enabled;
}

