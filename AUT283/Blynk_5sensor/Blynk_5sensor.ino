#define BLYNK_TEMPLATE_ID "YOUR TEMPLATE ID"
#define BLYNK_DEVICE_NAME "YOUR DEVICE NAME"
#define BLYNK_AUTH_TOKEN "YOUR TOKEN"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define KNOB 36
#define LS_TC_01_1 39
#define LS_TC_01_2 34
#define LS_TC_01_3 32
#define LS_TC_01_4 35
#define LS_TC_01_5 33

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "123";
char pass[] = "1234567890";

BlynkTimer timer;

void sendSensor()
{
    Blynk.virtualWrite(V0, analogRead(KNOB));
    Blynk.virtualWrite(V1, analogRead(LS_TC_01_1));
    Blynk.virtualWrite(V2, analogRead(LS_TC_01_2));
    Blynk.virtualWrite(V3, analogRead(LS_TC_01_3));
    Blynk.virtualWrite(V4, analogRead(LS_TC_01_4));
    Blynk.virtualWrite(V5, analogRead(LS_TC_01_5));
}

void setup()
{
    // Debug console
    Serial.begin(115200);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    // Setup a function to be called every second
    timer.setInterval(500L, sendSensor);
}

void loop()
{
    Blynk.run();
    timer.run();
}