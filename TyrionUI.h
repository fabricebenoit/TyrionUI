/*
  TyrionUI.h - Arduino UI.
  Created by Fabrice BENOIT, January 10, 2013
  Released into the public domain.
*/
#ifndef TyrionUI_h
#define TyrionUI_h

#include "Arduino.h"
#include <SoftwareSerial.h>
#include <serLCD.h>

class TyrionUI
{
  public:
    TyrionUI(int pinLCD, int pinT, int pinB, int pinL, int pinR, int pinC);
    void init();
    void disable();
    void enable();
    boolean isEnabled();
  private:
    int _pinLCD;
    int _pinT;
    int _pinB;
    int _pinL;
    int _pinR;
    int _pinC;
    serLCD _screen;
    boolean _enabled;
};

#endif
