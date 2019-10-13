# projekt

Cílem mého ročníkového projektu je pomocí Arduina udělat zařízení, které bude rozpoznávat a automaticky třídit barvy / věci podle barvy. 

Postup: vytvořit krabičku, na kterou přilepím nepájivé pole, připojím Arduino UNO, na něj senzor TCS3200, 
který rozpoznává barvy a servo motor, který dokáže tlačit nebo se otáčet s velkou přesností. 
Přilepím na něj papírovou "ruku", která po rozpoznání barvy senzorem odvede danou věc na správné místo 
(nejspíš do jednoduchých papírových / plastových nádob). K vývoji kódu budu používat zpočátku Arduino IDE a poté Platformio.

Důlěžité příkazy: pio run -t upload -> upload na Arduino
                  pio monitor device

Součástky: Arduino UNO, TCS3200 Color Sensor, 2x Servo motor, kabely, nepájivé pole

Odkazy: Platformio - https://docs.platformio.org/en/latest/quickstart.html
Servo motor        - https://www.youtube.com/watch?v=ditS0a28Sko                                                                       
Arduino            - https://www.youtube.com/watch?v=nL34zDTPkcs                                                                       
KiCad              - https://www.youtube.com/watch?v=-tN14xlWWmA                                                                       

EDIT: Při tvorbě projektu nebudu používat nepájivé pole, ale sensor a servo motory k Arduinu připojím přes propojovací kabely F-F (samice-samice).

ROZPOZNÁVÁNÍ BAREV podle RGB 

if(R<45 & R>32 & G<65 & G>55){
    barva = 1; // červená
  }
  
  if(G<55 & G>43 & B<47 &B>35){
    barva = 2; // oranžová
  }
  
  if(R<53 & R>40 & G<53 & G>40){
    barva = 3; // zelená
  }
  
  if(R<38 & R>24 & G<44 & G>30){
    barva = 4; // žlutá
  }
  
  if(R<56 & R>46 & G<65 & G>55){
    barva = 5; // hnědá
  }
  
  if (G<58 & G>45 & B<40 &B>26){
    barva = 6; // modrá
  }
  
  return barva;  
}
