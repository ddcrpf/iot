#define BLYNK_TEMPLATE_ID "TMPL3iOcDda6Z"
#define BLYNK_DEVICE_NAME "Control LED"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_AUTH_TOKEN "kYSJcSlRqpHsPMkZgbaHbBnYms2nleaQ"
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Nokia G21";//Enter your WIFI name
char pass[] = "bandi12345";//Enter your WIFI password
int ledpin = D4;
//Get the button value
BLYNK_WRITE(V0) {
digitalWrite(ledpin, param.asInt());
}
void setup() {
pinMode(ledpin, OUTPUT);
Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
WiFi.begin(ssid, pass);
Blynk.config(BLYNK_AUTH_TOKEN);
}
void loop() {
//Run the Blynk library
Blynk.run();
}