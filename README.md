# projekt

Cílem mého ročníkového projektu je pomocí Arduina udělat zařízení, které bude rozpoznávat a automaticky třídit barvy / věci podle barvy. 

Postup: vytvořit krabičku, na kterou přilepím nepájivé pole, připojím Arduino UNO, na něj senzor TCS3200, který rozpoznává barvy a servo motor, který dokáže tlačit nebo se otáčet s velkou přesností. Přilepím na něj papírovou "ruku", která po rozpoznání barvy senzorem odvede danou věc na správné místo (nejspíš do jednoduchých papírových / plastových nádob). 
K vývoji kódu budu používat zpočátku Arduino IDE a poté Platformio.

Důlěžité příkazy: 
pio run                                                                                                                      pio run -t upload  -> upload na Arduino                                                                                      pio device monitor -> monitoruje ve VS Code terminálu

Součástky: Arduino UNO, TCS3200 Color Sensor, 2x Servo motor, kabely, nepájivé pole

Odkazy: Platformio  - https://docs.platformio.org/en/latest/quickstart.html                                                             Servo motor - https://www.youtube.com/watch?v=ditS0a28Sko                                                                       Arduino     - https://www.youtube.com/watch?v=nL34zDTPkcs                                                                       KiCad       - https://www.youtube.com/watch?v=-tN14xlWWmA                                                                       Tvorba samotného zařízení - https://www.youtube.com/watch?v=4DbrWAGDADs
