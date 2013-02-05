/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
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
    
    //serLCD _screen(_pinLCD);
    
    //_screen = new serLCD(_pinLCD);
    
    
    
}

void TyrionUI::init(){
    // Initialisation de l'ecran
    _screen.clear();
    // Laisser le temps au splashscreen de s'afficher 
    //delay(1000);
    _screen.display();
    _screen.print("Tyrion UI");
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

