#include <Servo.h>
#include <Arduino.h>
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define senzor 6
// #define POCET_BAREV 6
Servo prvniServo;
Servo druheServo;
int barva=0;
//int barva;
int frekvenceBarvy = 0;
// int rozsahBarev[POCET_BAREV][6]={{32,45,55,65,-1,1}, {-1,1,43,55,35,47}, {40,53,40,53,-1,1}, {24,38,30,44,-1,1}, {46,56,55,65,-1,1}, {-1,1,45,58,26,40}}
//int i;
//int R,G,B;

int cteniBarvy() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frekvenceBarvy = pulseIn(senzor, LOW);
  int R = frekvenceBarvy;
  Serial.print("R= ");
  Serial.print(frekvenceBarvy);
  Serial.print("  ");
  delay(50);
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frekvenceBarvy = pulseIn(senzor, LOW);
  int G = frekvenceBarvy;
  Serial.print("G= ");
  Serial.print(frekvenceBarvy);
  Serial.print("  ");
  delay(50);
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frekvenceBarvy = pulseIn(senzor, LOW);
  int B = frekvenceBarvy;
  Serial.print("B= ");
  Serial.print(frekvenceBarvy);
  Serial.println("  ");
  delay(50);
  if((R<45 && R>32) && (G<65 && G>55)){
    barva = 1; // červená
  }
  if((G<55 && G>43) && (B<47 && B>35)){
    barva = 2; // oranžová
  }
  if((R<53 && R>40) && (G<53 && G>40)){
    barva = 3; // zelená
  }
  if((R<38 && R>24) && (G<44 && G>30)){
    barva = 4; // žlutá
  }
  if((R<56 && R>46) && (G<65 && G>55)){
    barva = 5; // hnědá
  }
  if ((G<58 && G>45) && (B<40 && B > 26)){
    barva = 6; // modrá
  }
  return barva;  
}

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(senzor, INPUT);
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  prvniServo.attach(7);
  druheervo.attach(8);
  Serial.begin(9600);
}
void loop() {
  prvniServo.write(115);
  delay(500);
  
  for(int i = 115; i > 65; i--) {
    prvniServo.write(i);
    delay(2);
  }
  delay(500);
  
  barva = cteniBarvy();
  delay(10);  
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
