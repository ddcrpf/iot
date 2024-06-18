//sender:
#include <LoRa.h>
#include <DHT.h>
#define DHTPIN 0 //pin where the dht11 is connected
DHT dht(DHTPIN, DHT11);
#define SS 15
#define RST 16
#define DIO0 2
String data1;
String data2;
const int rightForward = 0;
const int rightBackward = 2;
void setup(){
 Serial.begin(9600);
 while (!Serial);
 Serial.println("Sender Host");
 LoRa.setPins(SS, RST, DIO0);
if (!LoRa.begin(433E6)) {
 Serial.println("LoRa Error");
 delay(100);
 while (1);
 }
}
void loop()
{
 float h = dht.readHumidity();
 float t = dht.readTemperature();
 data1 = t;
 data2 = h;
 Serial.print("Sending Data: ");
 Serial.println(data1);
 Serial.println(data2);
 LoRa.beginPacket();
 LoRa.print("Temparature: ");
 LoRa.print(t);
 LoRa.print(" *C");
 LoRa.print("\n");
 LoRa.print("Humidity: ");
 LoRa.print(h);
 LoRa.print(" %");
 LoRa.print("\n");
 LoRa.endPacket();
 delay(3000);
}

//Receiver:
#include <ESP8266WiFi.h> 
#include <LoRa.h>
String apiKey = "MXKN78RD40818DX2";// Enter your Write API key from 
ThingSpeak
const char *ssid = "vivo 1904"; // replace with your wifi ssid and wpa2 key
const char *pass = "1e544b2103a4";
const char* server = "api.thingspeak.com";
#define SS D8
#define RST D0
#define DIO0 D1
WiFiClient client;
void setup() {
 //digitalWrite(rightForward,HIGH);
 //digitalWrite(rightBackward,LOW);
 Serial.begin(9600);
 while (!Serial);
 Serial.println("Receiver Host");
 LoRa.setPins(SS, RST, DIO0);
 delay(1000);
 if (!LoRa.begin(433E6)) {
 Serial.println("LoRa Error");
 delay(100);
 while (1);
 }
 Serial.println("Connecting to ");
 Serial.println(ssid);
 WiFi.begin(ssid, pass);
 while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected");
}
void loop() {
 int packetSize = LoRa.parsePacket();
 if (packetSize) {
 Serial.println("Receiving Data: ");
 while (LoRa.available()) {
 String data = LoRa.readString();
 Serial.println(data);
 String temp = data.substring(18, 14);
 Serial.println(temp);
 client.connect(server,80); // "184.106.153.149" or api.thingspeak.com
 String postStr = apiKey;
 postStr +="&field1=";
 postStr += String(temp);
 postStr += "\r\n\r\n";
 client.print("POST /update HTTP/1.1\n");
 client.print("Host: api.thingspeak.com\n");
 client.print("Connection: close\n");
 client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
 client.print("Content-Type: application/x-www-form-urlencoded\n");
 client.print("Content-Length: ");
 client.print(postStr.length());
 client.print("\n\n");
 client.print(postStr); 
 client.stop();
 }}}