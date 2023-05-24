const int DAT = 8;
const int CLK = 9;
float avdd = 4.28; // Measurd voltage at theAVDD terminal (E+)
long offset = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(DAT, INPUT);
    pinMode(CLK, OUTPUT);

    // Read the data from HX711
    // CLK　H:1us, L：1us @dataseet
    for (char i = 0; i < 24; i++)
    {
        digitalWrite(CLK, HIGH);
        delayMicroseconds(1);
        digitalWrite(CLK, LOW);
        delayMicroseconds(1);
        offset = (offset << 1) | (digitalRead(DAT));
    }

    // Because the output data is 2's complement...
    offset = offset ^ 0x800000;
    delay(1000);
}

void loop()
{
    float ave, v_vol, weight;
    long sum = 0, data;

    // Read the data from HX711(Average of 10 measurements)
    // CLK　H:1us, L：1us @dataseet
    for (int i = 0; i < 10; i++)
    {
        data = 0;
        while (digitalRead(DAT) != 0)
            ;

        // data: MSB -> LSB with 24bit
        for (char i = 0; i < 24; i++)
        {
            digitalWrite(CLK, HIGH);
            delayMicroseconds(1);
            digitalWrite(CLK, LOW);
            delayMicroseconds(1);
            data = (data << 1) | (digitalRead(DAT));
        }

        digitalWrite(CLK, HIGH);
        delayMicroseconds(1);
        digitalWrite(CLK, LOW);
        delayMicroseconds(1);

        data = data ^ 0x800000;
        sum += data;
    }

    ave = sum / 10 - offset;
    v_vol = ave * (avdd / 16777216.0 / 128);
    weight = v_vol / (0.001 * avdd / 2000.0);
    weight *= 2;
    Serial.print(weight);
    Serial.println("g");
    delay(100);
}