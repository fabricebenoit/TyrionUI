/*
 TyrionUI.cpp - Arduino UI.
 Created by Fabrice BENOIT, January 10, 2013
 Released into the public domain.
 */

#include "Arduino.h"
#include "TyrionUI.h"


TyrionUI::TyrionUI(int pinLCD, int pinT, int pinB, int pinL, int pinR, int pinC) : _screen(pinLCD), _joystick(pinT, pinB, pinL, pinR, pinC)
{
    _enabled = true;
    _currPage = 0;
    _lastLine1 = "";
    _lastLine2 = "";
    _lastJoyChange = millis();
    _lastJoy = 0;
    editMode = false;
    _pinLCD = pinLCD;
}

void TyrionUI::init(int pagesProps[], int nbPages){
    _pagesProps = pagesProps;
    _nbPages = nbPages;
    _screen.clear();
    enable();
    
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
    
    byte batFull[8]={
      B01110,
      B11111,
      B11111,
      B11111,
      B11111,
      B11111,
      B11111,
      B00000
    };
    
    byte batMid[8]={
      B01110,
      B11011,
      B10001,
      B10001,
      B11111,
      B11111,
      B11111,
      B00000
    };
    
    byte batLow[8]={
      B01110,
      B11011,
      B10001,
      B10001,
      B10001,
      B10001,
      B11111,
      B00000
    };

    _screen.createChar(1, invader);
    _screen.createChar(2, chrono);
    _screen.createChar(3, expo);
    _screen.createChar(4, soleil);
    _screen.createChar(5, ampoule);
    _screen.createChar(6, batFull);
    _screen.createChar(7, batMid);
    _screen.createChar(8, batLow);
}

void TyrionUI::updateScreen(String line1, String line2){
  
  if(line1 != _lastLine1){
    _lastLine1 = line1;
    _screen.setCursor(1,3);
    _screen.print(_lastLine1);
  }
  
  if(line2 != _lastLine2){
    _lastLine2 = line2;
    _screen.setCursor(2,1);
    _screen.print(_lastLine2);
  }
  
}

int TyrionUI::updateState()
{
  int joyPos = _joystick.getJoyStick();
  
  if(joyPos==2){
       editMode = !editMode;
   }
  
  if(editMode){
       
  }else{
      
      if(joyPos==3){
        _prevPage();
      }else
      if(joyPos==5){
        _nextPage();
      }
  }
  
  int retour = _pagesProps[_currPage];
  
  return retour;
  
  //return _currPage;
}

void TyrionUI::_prevPage(){
  if(_currPage!=0){
    _currPage--;
  }else{
    _currPage = _nbPages-1;
  }
}

void TyrionUI::_nextPage(){
  if(_currPage!=_nbPages-1){
    _currPage++;
  }else{
    _currPage = 0;
  }
}


void TyrionUI::setPage(TyrionPage page){
  _screen.clear();
  _screen.setCursor(1,3);
  _screen.print(page.getPageId());
  
}

/*
void TyrionUI::addPage(int icon, String line1, String line2){
  _nbPages++;
}*/

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



TyrionPage::TyrionPage(int pageID){
    _pageID = pageID;
}

int TyrionPage::getPageId(){
  return _pageID;
}


