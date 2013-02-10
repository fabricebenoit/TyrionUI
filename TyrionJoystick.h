class TyrionJoystick
{
  public:
     TyrionJoystick(int pinT, int pinB, int pinL, int pinR, int pinC);
     int getJoyStick();
     
  private:
    int _pinT;
    int _pinB;
    int _pinL;
    int _pinR;
    int _pinC;
    int _lastJoy;
    unsigned long _lastJoyChange;
};
