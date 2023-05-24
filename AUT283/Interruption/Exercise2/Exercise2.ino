/*
 * Exercise 2: Pseudo Multitasking without delay
 * Requirements:
    • 2 LEDs blink at the separate timing. A Red LED blinks
    every 100ms and a Green LED blinks every 300ms.
    • Each LED’s turn-on time and turn-off time can be the
    same, but red LED and green led must blink separately
 * Constrains:
    • Do not use delay() command
    • Use millis() command to get current time.
*/

#define RED_BLINK_TIME_MS 100
#define GREEN_BLINK_TIME_MS 300

#define RED_LED_PIN 13
#define GREEN_LED_PIN 12

unsigned long lastRedTimeMS = 0;
unsigned long lastGreenTimeMS = 0;

void setup()
{
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
}

void loop()
{
    unsigned long currentTimeMS = millis();
    if (currentTimeMS - lastRedTimeMS >= RED_BLINK_TIME_MS)
    {
        lastRedTimeMS = currentTimeMS;
        digitalWrite(RED_LED_PIN, !digitalRead(RED_LED_PIN));
    }
    if (currentTimeMS - lastGreenTimeMS >= GREEN_BLINK_TIME_MS)
    {
        lastGreenTimeMS = currentTimeMS;
        digitalWrite(GREEN_LED_PIN, !digitalRead(GREEN_LED_PIN));
    }
}