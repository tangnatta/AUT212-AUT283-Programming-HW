#include <ESP32Servo.h>
#define servo1 23
#define servo2 19
#define servo3 18
#define servo4 5

#define KNOB 36

Servo myservo;

void setup()
{
    myservo.attach(servo1);
}

void loop()
{
    int knob = analogRead(KNOB);
    knob = map(knob, 0, 4095, 0, 180);
    myservo.write(knob);
    delay(15);
}
