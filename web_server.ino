#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>

WebServer sv(80);

const char *ssid = "mms260131";
const char *senha = "sumumo01";

float val1 = 123.456;
float val2 = 654.321;

void conectado()
{
    sv.send(200, "text/html", html(val1, val2));
}

void nao_encontrado()
{
    sv.send(404, "text/plain", "Não encontrado");
}

String html(float val1, float val2) {
    String cd = "<!DOCTYPE html>\n";
    cd += "<html lang=\"pt-br\">\n";
    cd += "<head>\n";
    cd += "<meta charset=\"UTF-8\">\n";
    cd += "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n";
    cd += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
    cd += "<link rel=\"preconnect\" href=\"https://fonts.googleapis.com\">";
    cd += "<link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin>";
    cd += "<link href=\"https://fonts.googleapis.com/css2?family=Prompt:ital,wght@0,200;1,400&display=swap\" rel=\"stylesheet\">";
    cd += "<style>\n";
    cd += "html {\n";
    cd += "display: inline-block;\n";
    cd += "margin: 0px auto;\n";
    cd += "}\n";
    cd += "body {\n";
    cd += "margin-top: 10%;\n";
    cd += "margin-left: 20%; margin-right: 20%;\n";
    cd += "background: #212121;\n";
    cd += "}\n";
    cd += "h1 {\n";
    cd += "font-family: \"Prompt\", sans-serif;\n";
    cd += "font-size: 40pt;\n";
    cd += "font-style: italic;\n";
    cd += "color: #39B54A;\n";
    cd += "margin-left: 5%; margin-right: 5%; margin-top: 5%; margin-bottom: 5%;\n";
    cd += "}\n";
    cd += "p {\n";
    cd += "font-family: \"Prompt\", sans-serif;\n";
    cd += "font-size: 20pt;\n";
    cd += "color: #b8b8b8;\n";
    cd += "}\n";
    cd += ".container {\n";
    cd += "display: flex;\n";
    cd += "flex-direction: column;\n";
    cd += "}\n";
    cd += ".container::after{\n";
    cd += "content: \" \";\n";
    cd += "display: block;\n";
    cd += "}\n";
    cd += ".left,\n";
    cd += ".center {\n";
    cd += "border-radius: 999999999px;\n";
    cd += "box-shadow:  9px 9px 26px #181818,-9px -9px 26px #2a2a2a;\n";
    cd += " text-align: center;\n";
    cd += "}\n";
    cd += "</style>\n";
    cd += "<title>CarbonEye</title>\n";
    cd += "</head>\n";
    cd += "<body>\n";
    cd += "<div class=\"container\">\n";
    cd += "<div class=\"center\">\n";
    cd += "<h1>CarbonEye🍃</h1>\n";
    cd += "</div>\n";
    cd += "<br>\n";
    cd += "<div class=\"left\">\n";
    cd += "<p>Temperatura: ";
    cd += int(val1);
    cd += "</p>\n";
    cd += "<p>Pressão Atmosférica: ";
    cd += int(val2);
    cd += "</p>\n";
    cd += "</div>\n";
    cd += "</div>\n";
    cd += "</body>\n";
    cd += "</html>\n";

    return cd;
}


void setup()
{
    Serial.begin(115200);
    delay(100);
    Serial.print("Se conectando a: ");
    Serial.println(ssid);
    WiFi.begin(ssid, senha);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConectado");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    sv.on("/", conectado);
    sv.onNotFound(nao_encontrado);
    sv.begin();
    Serial.println("Servidor Online");
}

void loop()
{
    sv.handleClient();
}