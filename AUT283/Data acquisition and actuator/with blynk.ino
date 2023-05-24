#define BLYNK_TEMPLATE_ID "YOUR TEMPLATE ID"
#define BLYNK_DEVICE_NAME "YOUR DEVICE NAME"
#define BLYNK_AUTH_TOKEN "YOUR TOKEN"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "123";
char pass[] = "1234567890";

BlynkTimer timer;

void sendSensor()
{
    int knob = analogRead(A0);
    int static_1 = 500;
    Blynk.virtualWrite(V0, knob);
    Blynk.virtualWrite(V13, static_1); // static
    Serial.print("knob:");
    Serial.print(knob);
    Serial.print(",");
    Serial.print("static:");
    Serial.print(static_1);
    Serial.print("\n")
}

void setup()
{
    // Debug console
    Serial.begin(115200);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    // Setup a function to be called every second
    timer.setInterval(1000L, sendSensor);
}

void loop()
{
    Blynk.run();
    timer.run();
}