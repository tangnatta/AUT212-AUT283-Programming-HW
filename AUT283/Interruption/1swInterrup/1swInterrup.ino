#define BUTTON 2
#define LED_PIN 13

volatile bool state = LOW;

void setup()
{
    pinMode(BUTTON, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(BUTTON), changeState, CHANGE);
}

void loop()
{
    digitalWrite(LED_PIN, state);
}

void changeState()
{
    state = !state;
}