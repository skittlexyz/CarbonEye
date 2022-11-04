/*
    Carbon Eye - bioTech
    A CO2 measure tool.
    by:
        Moisés Corrêa (CODE)
        Lethicia Barros Souza (JOURNAL)
        Rebeca Queiroz Rodrigues de Paiva (PROTOTYPE)
        Leonardo Lopes Santos (JOURNAL)
*/

/*
Fonts used:
    u8g2_font_DigitalDisco_te
    u8g2_font_fivepx_tr
    u8g2_font_inr16_mn
*/

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <U8g2lib.h>
#include "DHT.h"
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#include "index.h"

WebServer server(80);

const char *ssid = "FAB LAB";
const char *password = "fl4ce0ss3@camp";

byte delay_time = 200;
String version = "1.0.6";
int gasPin = 4;

int gasVal = 0;
int tempVal = 0;

void gui_draw(int delay_time, int val1, int val2);
void title_and_version_draw();
void lines_draw();
void table_content_draw(int x, int y);

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
DHT dht(2, DHT22);

void handleRoot()
{
    String s = MAIN_page;
    server.send(200, "text/html", s);
}

void handleVal1()
{
    gasVal = analogRead(gasPin);
    String val1 = String(gasVal);
    server.send(200, "text/plane", val1);
}

void handleVal2()
{
    String val2 = String(tempVal);
    server.send(200, "text/plane", val2);
}

void setup(void)
{
    Serial.begin(115200);
    Serial.println();
    Serial.println("Booting Sketch...");

    dht.begin();
    u8g2.begin();
    u8g2.clearBuffer();
    pinMode(gasPin, INPUT);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    Serial.println("Connecting to ");
    Serial.print(ssid);

    while (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
        Serial.print(".");
    }

    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/", handleRoot);
    server.on("/readVal1", handleVal1);
    server.on("/readVal2", handleVal2);

    server.begin();
    Serial.println("HTTP server started");
}

void loop(void)
{    
    tempVal = dht.readTemperature();
    Serial.print(gasVal);Serial.print(" ");Serial.print(tempVal);Serial.println(" ");
    gui_draw(1000, gasVal, tempVal);
    server.handleClient();
    delay(1);
}

void gui_draw(int delay_time, int val1, int val2)
{
    u8g2.clearBuffer();
    title_and_version_draw();
    lines_draw();
    table_content_draw(val1, val2);
    u8g2.sendBuffer();
    delay(delay_time);
}

void title_and_version_draw()
{
    u8g2.setFont(u8g2_font_DigitalDisco_te);
    u8g2.drawStr(0, 13, "Carbon Eye");
    u8g2.setFont(u8g2_font_fivepx_tr);
    u8g2.drawStr(108, 13, "1.0.2");
    u8g2.setCursor(108, 13);
    u8g2.print(version);
}

void lines_draw()
{
    u8g2.drawLine(0, 17, 128, 17);
    u8g2.drawLine(64, 17, 64, 64);
    u8g2.drawLine(0, 17, 0, 64);
    u8g2.drawLine(127, 17, 127, 64);
    u8g2.drawLine(0, 63, 128, 63);
    u8g2.drawLine(0, 25, 128, 25);
}

void table_content_draw(int x, int y)
{
    u8g2.setFont(u8g2_font_fivepx_tr);
    u8g2.drawStr(2, 24, "CO2");
    u8g2.drawStr(66, 24, "H2O");

    u8g2.setFont(u8g2_font_inr16_mn);

    u8g2.setCursor(4, 50);
    u8g2.print(x);

    u8g2.setCursor(68, 50);
    u8g2.print(y);
}
