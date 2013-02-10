#include "Arduino.h"
#include "TyrionJoystick.h"

TyrionJoystick::TyrionJoystick(int pinT, int pinB, int pinL, int pinR, int pinC)
{
    _pinT = pinT;
    _pinB = pinB;
    _pinL = pinL;
    _pinR = pinR;
    _pinC = pinC;
    
    pinMode(_pinT, INPUT);
    pinMode(_pinB, INPUT);
    pinMode(_pinL, INPUT);
    pinMode(_pinR, INPUT);
    pinMode(_pinC, INPUT);
    
    digitalWrite(_pinT, HIGH);
    digitalWrite(_pinB, HIGH);
    digitalWrite(_pinL, HIGH);
    digitalWrite(_pinR, HIGH);
    digitalWrite(_pinC, HIGH);
}

int TyrionJoystick::getJoyStick()
{
  unsigned long currT = millis();
  
  int currJoy = 0;
  int retour = 0;
  
  if(currT-_lastJoyChange>300){
    if(!digitalRead(_pinT)){
        currJoy = 1;//Top
     }else 
     if(!digitalRead(_pinC)){
        currJoy = 2;//Center
     }else 
     if(!digitalRead(_pinL)){
        currJoy = 3;//Left
     }else 
     if(!digitalRead(_pinB)){
        currJoy = 4;//Bottom
     }else 
     if(!digitalRead(_pinR)){
        currJoy = 5;//Right
     }
     
     if(currJoy!=0){
       if(currJoy == _lastJoy){
         _lastJoyChange = currT;
         retour = currJoy;
       }
     }
  }
    
  _lastJoy = currJoy;
  return retour;
  
}
