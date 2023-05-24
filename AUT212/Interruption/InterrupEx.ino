//! Before Interrupt
// #define LED_PIN 13 // pin for LED
// #define BUTTON 7   // the input pin
// int val;           // stores the state of the input pin
// void setup()
// {
//     pinMode(LED_PIN, OUTPUT);
//     pinMode(BUTTON, INPUT);
//     Serial.begin(115200);
// }
// void loop()
// {
//     val = digitalRead(BUTTON);
//     if (val == LOW) // Pull-Up Register
//         digitalWrite(LED, HIGH);
//     else
//         digitalWrite(LED, LOW);
//     Serial.println(val);
// }

//! Interrupt
#define BUTTON 2   // interruption
#define LED_PIN 13 // pin for LED
volatile byte state = HIGH;
void setup()
{
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BUTTON), changeState, CHANGE);
}
void loop()
{
    digitalWrite(LED_PIN, state);
}
void changeState()
{
    Serial.println(millis());
    state = !state;
}
