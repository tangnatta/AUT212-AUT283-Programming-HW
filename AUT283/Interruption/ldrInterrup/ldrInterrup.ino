#define LDR 2
#define LED_PIN 13

volatile int brightness = 0;
volatile bool state = 0;

void setup()
{
    Serial.begin(115200);

    pinMode(A0, INPUT);
    pinMode(LDR, INPUT);
    pinMode(LED_PIN, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(LDR), changeBrightness, CHANGE);
    // attachInterrupt(digitalPinToInterrupt(LDR), changeState, CHANGE);
}

void loop()
{
    Serial.print("V: ");
    Serial.println(analogRead(A0) * 5.0 / 1023.0);

    if (brightness > 255)
    {
        brightness = 0;
    }
    analogWrite(LED_PIN, brightness);
    // digitalWrite(LED_PIN, state);
}

void changeBrightness()
{
    brightness += 10;
}

void changeState()
{
    state = !state;
}