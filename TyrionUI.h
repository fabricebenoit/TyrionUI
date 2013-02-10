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
#include "TyrionJoystick.h"

class TyrionPage
{
    public:
      TyrionPage(int pageID);
      int getPageId();
      
    private:
      int _pageID;
};

class TyrionUI
{
  public:
    TyrionUI(int pinLCD, int pinT, int pinB, int pinL, int pinR, int pinC);
    void init(int pagesProps[], int nbPages);
    //void addPages(int numberOfPages);
    void disable();
    void enable();
    boolean isEnabled();
    void setPage(TyrionPage page);
    int updateState();
    void updateScreen(String line1, String line2);
    boolean editMode;
    
    
  private:
    int _pinLCD;
    
    serLCD _screen;
    boolean _enabled;
    int _currPage;
    int _nbPages;
    int getJoyStick();
    String _lastLine1;
    String _lastLine2;
    int _lastJoy;
    unsigned long _lastJoyChange;
    void _prevPage();
    void _nextPage();
    int * _pagesProps;
    TyrionJoystick _joystick;
};


#endif
