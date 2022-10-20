/*
    Carbon Eye - bioTech

    A CO2 measure tool.

    by:
        Moisés Corrêa (CODE)
        Lethicia Barros Souza (JOURNAL)
        Rebeca Queiroz Rodrigues de Paiva (PROTOTYPE)
        Leonardo Lopes Santos (JOURNAL)
*/

#include<U8g2lib.h>
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);
    u8g2.begin();
    u8g2.clearBuffer();          // clear the internal memory
    u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
    u8g2.drawStr(0,10,"Hello World!");  // write something to the internal memory
    u8g2.sendBuffer();
}

void loop (){
  
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    delay(1000);
    u8g2.begin();
    u8g2.clearBuffer();          // clear the internal memory
    u8g2.setFont(u8g2_font_8x13B_tr); // choose a suitable font
    u8g2.drawStr(0,10,"Carbon Eye");  // write something to the internal memory
    u8g2.sendBuffer();
}