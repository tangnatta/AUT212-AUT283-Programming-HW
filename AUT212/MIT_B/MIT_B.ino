#include <SoftwareSerial.h>
#define RX_PIN 50 // for MEGA
#define TX_PIN 51
// bult-in LED
#define LED_PIN 13
String btData;
SoftwareSerial
    btSerial(RX_PIN, TX_PIN);
// for the Bluetooth
void setup()
{
    btSerial.begin(9600);
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
    btSerial.println("AT+NAME=TEST_212224");
}
void loop()
{
    if (btSerial.available() > 0)
    {
        // Communication via Bluetooth is done
        btData = btSerial.readString();
        Serial.println(btData);

        // Read data that reached to RX_PIN
        /**/ if (btData == "1")
        { // LED ON
            digitalWrite(LED_PIN, HIGH);
        }
        else if (btData == "0")
        { // LED OFF
            digitalWrite(LED_PIN, LOW);
        }
    }
    delay(100);
}