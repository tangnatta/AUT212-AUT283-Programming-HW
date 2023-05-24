#include <MsTimer2.h>
#define LED 13
volatile byte state = LOW;

void setup()
{
    pinMode(LED, OUTPUT);
    MsTimer2::set(500, changeState);
    MsTimer2::start();
}

void loop()
{
    digitalWrite(LED, state);

    // delay(10000);
}

void changeState()
{
    state = !state;

    // digitalWrite(LED, state);
}

