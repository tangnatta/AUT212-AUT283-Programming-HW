#define BUTTON 2
#define LED_PIN 13

volatile int brightness = 0;

void setup()
{
    pinMode(BUTTON, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(BUTTON), changeBrightness, CHANGE);
}

void loop()
{
    if (brightness > 255)
    {
        brightness = 0;
    }
    analogWrite(LED_PIN, brightness);
}

void changeBrightness()
{
    brightness += 10;
}