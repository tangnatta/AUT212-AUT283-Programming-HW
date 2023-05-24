/**
   ESP32 + DHT22 Example for Wokwi

   https://wokwi.com/arduino/projects/322410731508073042
*/

#include "DHTesp.h"

const int DHT_PIN = 15;

DHTesp dhtSensor;

void setup()
{
    Serial.begin(115200);
    dhtSensor.setup(DHT_PIN, DHTesp::DHT11);
}

void loop()
{
    TempAndHumidity data = dhtSensor.getTempAndHumidity();

    int temperature = data.temperature;
    int humidity = data.humidity;

    Serial.println("Temp: " + String(data.temperature, 2) + "°C");
    Serial.println("Humidity: " + String(data.humidity, 1) + "%");
    Serial.println("---");

    delay(1000);
}