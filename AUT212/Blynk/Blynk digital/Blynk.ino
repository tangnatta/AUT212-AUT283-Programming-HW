#define BLYNK_TEMPLATE_ID "YOUR TEMPLATE ID"
#define BLYNK_DEVICE_NAME "YOUR DEVICE NAME"
#define BLYNK_AUTH_TOKEN "YOUR TOKEN"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "123";
char pass[] = "0847797257";

void setup()
{
    // Debug console
    Serial.begin(115200);

    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
    // You can also specify server:
    // Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
    // Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
    Blynk.run();
    // You can inject your own code or combine it with other sketches.
    // Check other examples on how to communicate with Blynk. Remember
    // to avoid delay() function!
}