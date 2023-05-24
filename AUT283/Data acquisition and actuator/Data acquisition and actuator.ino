#define KNOB 36
#define LS_TC_01_1 39
#define LS_TC_01_2 34
#define LS_TC_01_3 32
#define LS_TC_01_4 35
#define LS_TC_01_5 33

int random_variable;
const int static_variable = 500;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    // randomSeed(analogRead(0));
}
void loop()
{
    // put your main code here, to run repeatedly:
    // random_variable = random(0, 1000);
    Serial.print("KNOB:");
    Serial.print(analogRead(KNOB));
    Serial.print(",");
    Serial.print("LS_TC_01_1:");
    Serial.print(analogRead(LS_TC_01_1));
    Serial.print(",");
    Serial.print("LS_TC_01_2:");
    Serial.print(analogRead(LS_TC_01_2));
    Serial.print(",");
    Serial.print("LS_TC_01_3:");
    Serial.print(analogRead(LS_TC_01_3));
    Serial.print(",");
    Serial.print("LS_TC_01_4:");
    Serial.print(analogRead(LS_TC_01_4));
    Serial.print(",");
    Serial.print("LS_TC_01_5:");
    Serial.print(analogRead(LS_TC_01_5));
    Serial.print("\n");
    delay(100);
}