

//! Interrupt
// woring with push button and Phototransistors (Ground)
#define LED 11
#define BUTTON 2 // interruption
#define DELAY_TIME 100
volatile int brightness = 0;

void setup()
{
    Serial.begin(115200);

    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BUTTON), changeBrightness, CHANGE);
}

void loop()
{
    if (brightness > 255)
        brightness = 0;
    analogWrite(LED, brightness);
    Serial.println(brightness);
    delay(DELAY_TIME);
}

void changeBrightness()
{
    brightness += 10;
    // if (brightness > 255)
    //     brightness = 0;
}