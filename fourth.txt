// External:
#define LE D0
void setup()
{
pinMode(LED, OUTPUT); //LED pin as output
}
void loop()
{
digitalWrite(LED, HIGH); //turn the led off
delay(1000); //wait for 1 sec
digitalWrite(LED, LOW); //turn the led on
delay(1000); //wait for 1 sec
}

// Onboard:
void setup()
{
pinMode(LED_BUILTIN, OUTPUT); //LED_BUILTIN pin as an output
}
void loop()
{
digitalWrite(LED_BUILTIN, LOW); // Turn the LED on
delay(1000); // Wait for a second
digitalWrite(LED_BUILTIN, HIGH); // Turn the LED off
delay(2000); // Wait for two seconds
}