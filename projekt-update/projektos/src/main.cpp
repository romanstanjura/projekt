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
int barva;
int frekvenceBarvy = 0;
int i;
int red;
int green,
int blue;
int rozsahBarev[POCET_BAREV][6]={{32,45,55,65,-1,1}, {-1,1,43,55,35,47}, {40,53,40,53,-1,1}, {24,38,30,44,-1,1}, {46,56,55,65,-1,1}, {-1,1,45,58,26,40}}

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
  
  //zatim nejsou upraveny rozsahyBarev ([i][dane cislo])
  // porovnani vsech prectenych hodnot z fotodiod a nasledne vyhodnoceni barvy objektu
  for(i = 0; i < POCET_BAREV;i++){
	  if((red > rozsahyBarev[i][0]&& red < rozsahyBarev[i][1]) && (green > rozsahyBarev[i][2] && green < rozsahyBarev[i][3]) && (blue > rozsahyBarev[i][4] && blue < rozsahyBarev[i][5])){
	  	barva = i+1; // cervena
	  }
	  if((red > rozsahyBarev[i][0]&& red < rozsahyBarev[i][1]) && (green > rozsahyBarev[i][2] && green < rozsahyBarev[i][3]) && (blue > rozsahyBarev[i][4] && blue < rozsahyBarev[i][5])){
	  	barva = i+2; // oranzova
	  }
	  if((red > rozsahyBarev[i][0]&& red < rozsahyBarev[i][1]) && (green > rozsahyBarev[i][2] && green < rozsahyBarev[i][3]) && (blue > rozsahyBarev[i][4] && blue < rozsahyBarev[i][5])){
	  	barva = i+3; // zelena
	  }
	  if((red > rozsahyBarev[i][0]&& red < rozsahyBarev[i][1]) && (green > rozsahyBarev[i][2] && green < rozsahyBarev[i][3]) && (blue > rozsahyBarev[i][4] && blue < rozsahyBarev[i][5])){
	  	barva = i+4; // zluta
	  }
	  if((red > rozsahyBarev[i][0]&& red < rozsahyBarev[i][1]) && (green > rozsahyBarev[i][2] && green < rozsahyBarev[i][3]) && (blue > rozsahyBarev[i][4] && blue < rozsahyBarev[i][5])){
	  	barva = i+5; // hneda
	  }
	  if((red > rozsahyBarev[i][0]&& red < rozsahyBarev[i][1]) && (green > rozsahyBarev[i][2] && green < rozsahyBarev[i][3]) && (blue > rozsahyBarev[i][4] && blue < rozsahyBarev[i][5])){
	  	barva = i+6; // modra
	  }
  }
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
