#define BUTTON_INCREASE 2
#define BUTTON_DECREASE 3
#define LED_PIN 13

volatile int brightness = 0;

void setup()
{
    pinMode(BUTTON_INCREASE, INPUT_PULLUP);
    pinMode(BUTTON_DECREASE, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(BUTTON_INCREASE), increaseBrightness, RISING);
    attachInterrupt(digitalPinToInterrupt(BUTTON_DECREASE), decreaseBrightness, FALLING);
}

void loop()
{
    if (brightness > 255)
    {
        brightness = 255;
    }
    else if (brightness < 0)
    {
        brightness = 0;
    }
    analogWrite(LED_PIN, brightness);
}

void increaseBrightness()
{
    brightness += 10;
}

void decreaseBrightness()
{
    brightness -= 10;
}