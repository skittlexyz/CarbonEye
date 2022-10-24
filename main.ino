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
#include"DHT.h"
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

byte delay_time = 1000;
String version = "1.0.3";

int gasVal = 0;
int tempVal = 0;

void gui_draw(int delay_time, int val1, int val2);
void title_and_version_draw();
void lines_draw();
void table_content_draw(int x, int y);

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
DHT dht(2, DHT22);

void setup() {
    dht.begin();
    u8g2.begin();
    u8g2.clearBuffer();
    pinMode(15, INPUT);
    Serial.begin(9600);
}

void loop (){
    gasVal = analogRead(15);
    tempVal = dht.readTemperature();
    gui_draw(1000, gasVal, tempVal);
}

void gui_draw(int delay_time, int val1, int val2){
    u8g2.clearBuffer(); 
    title_and_version_draw();
    lines_draw();
    table_content_draw(val1,val2);
    u8g2.sendBuffer();
    delay(delay_time);
}

void title_and_version_draw(){
    u8g2.setFont(u8g2_font_DigitalDisco_te); 
    u8g2.drawStr(0,13,"Carbon Eye");
    u8g2.setFont(u8g2_font_fivepx_tr); 
    u8g2.drawStr(108,13,"1.0.2");
    u8g2.setCursor(108,13);
    u8g2.print(version);
}

void lines_draw(){
    u8g2.drawLine(0, 17, 128, 17);
    u8g2.drawLine(64, 17, 64, 64);
    u8g2.drawLine(0, 17, 0, 64);
    u8g2.drawLine(127, 17, 127, 64);
    u8g2.drawLine(0, 63, 128, 63);
    u8g2.drawLine(0, 25, 128, 25);
}

void table_content_draw(int x, int y){
    u8g2.setFont(u8g2_font_fivepx_tr); 
    u8g2.drawStr(2, 24, "CO2");
    u8g2.drawStr(66, 24, "H2O");

    u8g2.setFont(u8g2_font_inr16_mn);

    u8g2.setCursor(4, 50);
    u8g2.print(x);

    u8g2.setCursor(68, 50);
    u8g2.print(y);
}
/*
Fonts used:
    u8g2_font_DigitalDisco_te
    u8g2_font_fivepx_tr
    u8g2_font_inr16_mn
*/
