/*
    CarbonEye - bioTech
    A EXPERIMENTAL CO2 measure tool.
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
#include "credentials.h"

WebServer server(80);

const char *ssid = NAME;
const char *password = PASS;

byte delay_time = 200;
String version = "2 0 1";
int gasPin = 34;

int gasVal = 0;
int tempVal = 0;

void gui_draw(int delay_time, int val1, int val2);
void title_and_version_draw();
void lines_draw();
void table_content_draw(int x, int y);
void ip_display();

int randomppm();

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);
DHT dht(2, DHT22);

int randomppm()
{
    int randomVal;
    randomVal = random(450, 600);
    return randomVal;
}

void handleRoot()
{
    String s = MAIN_page;
    server.send(200, "text/html", s);
}

void handleVal1()
{
    gasVal = randomppm();
    String val1 = String(gasVal);
    Serial.print("GasVal: ");
    Serial.println(val1);

    // String val1 = "fuck ";

    server.send(200, "text/plane", val1);
}

void handleVal2()
{
    tempVal = dht.readTemperature();
    String val2 = String(tempVal);
    Serial.print("TmpVal: ");
    Serial.println(val2);

    // String val2 = "you!";

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

    ip_display();

    server.on("/", handleRoot);
    server.on("/readVal1", handleVal1);
    server.on("/readVal2", handleVal2);

    server.begin();
    Serial.println("HTTP server started");
}

void loop(void)
{
    gui_draw(1000, gasVal, tempVal);
    server.handleClient();
    delay(1);
}

void ip_display()
{
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_helvB08_tf);
    u8g2.setCursor(0, 54);
    String network = ssid;
    u8g2.print("Connected to " + network);
    u8g2.setCursor(0, 64);
    u8g2.print(WiFi.localIP());
    u8g2.sendBuffer();
    delay(5000);
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_DigitalDisco_te);
    u8g2.drawStr(36, 35, "bioTech");
    u8g2.sendBuffer();
    delay(5000);
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
    u8g2.drawStr(2, 24, "PPM");
    u8g2.drawStr(66, 24, "Cº");

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
    u8g2_font_helvB08_tf
*/
