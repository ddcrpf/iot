const int trig = 8; // Trigger Pin of Ultrasonic Sensor
long timeInMicro;
long distanceIncm;
const int echo = 7; // Echo Pin of Ultrasonic Sensor
void setup() {
Serial.begin(9600); // Starting Serial Terminal
pinMode(8,OUTPUT);
pinMode(7,INPUT);
}
void loop() {
digitalWrite(trig,LOW);
delayMicrsecond(2);
digitalWrite(trig,HIGH);
delayMicrsecond(10);
timeinMicro=pulseIn(echo,HIGH);
distanceIncm= timeinMicro/29/2;
Serial.println(distanceIncm);
Delay(1000);
}