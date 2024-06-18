// Onboard Code
void setup() {
pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
digitalWrite(LED_BUILTIN, HIGH);
delay(1000);
digitalWrite(LED_BUILTIN, LOW);
delay(1000);
}
// External LED
int LEDpin = 13;
int delayT = 1000;
void setup() {
// put your setup code here, to run once:
pinMode(LEDpin, OUTPUT);
}
void loop() {
// put your main code here, to run repeatedly:
digitalWrite(LEDpin, HIGH);
delay(delayT);
digitalWrite(LEDpin, LOW);
delay(delayT);
}