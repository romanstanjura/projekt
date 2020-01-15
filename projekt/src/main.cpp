//deklarace potrebnych knihoven a pinu pro modul TCS230
#include <Servo.h>
#include <Arduino.h>
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define senzor 6

Servo prvniServo;
Servo druheServo;
int barva=0;
int frekvenceBarvy = 0;

int cteniBarvy() {
  //aktivace cervenych fotodiod modulu TCS230, aby mohli "cist" barvu
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // "precteni" frekvence barvy
  frekvenceBarvy = pulseIn(senzor, LOW);
  int R = frekvenceBarvy;
  Serial.print("R= ");
  Serial.print(frekvenceBarvy);
  Serial.print("  ");
  delay(50);
  
  //aktivace zelenych fotodiod modulu TCS230, aby mohli "cist" barvu
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // "precteni" frekvence barvy
  frekvenceBarvy = pulseIn(senzor, LOW);
  int G = frekvenceBarvy;
  Serial.print("G= ");
  Serial.print(frekvenceBarvy);
  Serial.print("  ");
  delay(50);
  
  //aktivace modrych fotodiod modulu TCS230, aby mohli "cist" barvu
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // "precteni" frekvence barvy
  frekvenceBarvy = pulseIn(senzor, LOW);
  int B = frekvenceBarvy;
  Serial.print("B= ");
  Serial.print(frekvenceBarvy);
  Serial.println("  ");
  delay(50);
  
  // porovnani vsech prectenych hodnot z fotodiod a nasledne vyhodnoceni barvy objektu
  if((R<45 && R>32) && (G<65 && G>55)){
    barva = 1; // vyhodnoceni barvy jako cervena
  }
  if((G<55 && G>43) && (B<47 && B>35)){
    barva = 2; // vyhodnoceni barvy jako oranzova
  }
  if((R<53 && R>40) && (G<53 && G>40)){
    barva = 3; // vyhodnoceni barvy jako zelena
  }
  if((R<38 && R>24) && (G<44 && G>30)){
    barva = 4; // vyhodnoceni barvy jako zluta
  }
  if((R<56 && R>46) && (G<65 && G>55)){
    barva = 5; // vyhodnoceni barvy jako hneda
  }
  if ((G<58 && G>45) && (B<40 && B > 26)){
    barva = 6; // vyhodnoceni barvy jako modra
  }
  return barva;  
}

void setup() {	
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(senzor, INPUT);
  // Nastaveni frekvenci skalovani barev na 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  
  prvniServo.attach(7);
  druheervo.attach(8);
  Serial.begin(9600);
}
void loop() {
   //servo motor se otoci do polohy tak, aby objekt byl pod modulem TCS230 pro nasledne cteni barev
  prvniServo.write(115);
  delay(500);
  
  for(int i = 115; i > 65; i--) {
    prvniServo.write(i);
    delay(2);
  }
  delay(500);
  
  // ctení hodnoty barev voláním funkce a ulozeni hodnot do promenne
  barva = cteniBarvy();
  delay(10);  
  
  // podle detekovane barvy se motor servo otaci do spravne polohy, aby objekt mohl po papirove "skluzavce" sjet do spravne nadoby/krabicky
  switch (barva) {
    case 1:
      druheServo.write(50);
      break;
    case 2:
      druheServo.write(75);
      break;
    case 3:
      druheServo.write(100);
      break;
    case 4:
      druheServo.write(125);
      break;
    case 5:
      druheServo.write(150);
      break;
    case 6:
      druheServo.write(175);
      break;
    
    case 0:
      break;
  }
  delay(300);
  
  //servo motor se vraci do vychozi polohy, aby mohl modul vyhodnotit dalsi objekt
  for(int i = 65; i > 29; i--) {
    prvniServo.write(i);
    delay(2);
  } 
  delay(200);
  
  for(int i = 29; i < 115; i++) {
    prvniServo.write(i);
    delay(2);
  }
  barva=0;
}
