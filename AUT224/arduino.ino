int val = 0;

int last_val = 0;

void setup()

{
    Serial.begin(115200);
}

void loop()
{
    val = analogRead(0);
    if (last_val != val)
    {
        Serial.print("val = ");
        Serial.println(val);
        Serial.print("voltage = ");
        Serial.print(val * 5.0 / 1023.0);
        Serial.println("[V]");

        last_val = val;
    }
    delay(1000);
}

// int val = 0;

// void setup()
// {
//     Serial.begin(9600);
// }

// void loop()
// {
//     val = analogRead(0);
//     Serial.println(val / 4);
//     analogWrite(3, val / 4);
//     delay(500);
// }
