#include <SoftwareSerial.h>  // Requis pour serLCD
#include <serLCD.h>          // A télécharger et installer

// pin Arduino connecté au Rx de l'écran LCD
int LCDpin = 4;
serLCD lcd(LCDpin);

// Assignation des pins pour le joystick
int pinHaut = 9;
int pinCentre = 8;
int pinGauche = 7;
int pinBas = 6;
int pinDroite = 5;

void setup(){
  // Les pins connectés au joystick sont configurés en entrées
  pinMode(pinHaut, INPUT);
  pinMode(pinCentre, INPUT);
  pinMode(pinGauche, INPUT);
  pinMode(pinBas, INPUT);
  pinMode(pinDroite, INPUT);
  
  // On active les résistances internes des pin Arduino pour avoir des valeurs cohérentes
  digitalWrite(pinHaut, HIGH);
  digitalWrite(pinCentre, HIGH);
  digitalWrite(pinGauche, HIGH);
  digitalWrite(pinBas, HIGH);
  digitalWrite(pinDroite, HIGH);
  
   // Initialisation de l'ecran
  lcd.clear();
  // Laisser le temps au splashscreen de s'afficher 
  delay(1000);
  lcd.display();
  lcd.print("Tyrion UI");
}

void loop(){
  
}
