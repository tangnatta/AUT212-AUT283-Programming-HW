/*
 * Exercise 1: Interrupt
 * Requirements:
    • Use a push button as a hardware interrupt.
    • Use timer interrupt every 1 sec to count up number by 1
    which starts from 0. (Declare the variable named count.)
    • In loop function, display the number of the count on
    Serial monitor.
    • When the bush button is pushed, the number of count
    will be set as 0 at any time.
 * Constrains:
    • Do not use digitalRead or analogRead commands.
    • Do not use delay command
 */
#include <MsTimer2.h>

#define BUTTON 2

volatile unsigned int count = 0;
unsigned int lastCount = 99999;

void setup()
{
    pinMode(BUTTON, INPUT_PULLUP);
    Serial.begin(115200);

    // define Timer Interrupt
    MsTimer2::set(1000, increseCount);
    MsTimer2::start();

    // define Hardware Interrupt
    attachInterrupt(digitalPinToInterrupt(BUTTON), resetCount, RISING);
}

void loop()
{
    if (lastCount != count)
    {
        lastCount = count;
        Serial.println(count);
    }
}

void resetCount()
{
    count = 0;
}

void increseCount()
{
    count++;
}