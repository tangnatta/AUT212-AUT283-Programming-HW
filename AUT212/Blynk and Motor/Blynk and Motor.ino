// Motor pin
#define MOTOR_R_1 2  // Backward
#define MOTOR_R_2 4  // Forward
#define MOTOR_L_1 16 // Backward
#define MOTOR_L_2 17 // Forward

// Motor channel
#define MOTOR_R_1_CH 6 // Backward
#define MOTOR_R_2_CH 7 // Forward
#define MOTOR_L_1_CH 4 // Backward
#define MOTOR_L_2_CH 5 // Forward

#define SW 15 // SWITCH

#define KNOB 36
#define LS_TC_01_1 39
#define LS_TC_01_2 34
#define LS_TC_01_3 32
#define LS_TC_01_4 35
#define LS_TC_01_5 33

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

int speed = 100;
int X = 0;
int Y = 0;

BlynkTimer timer;

BLYNK_CONNECTED()
{
    Blynk.syncAll();
}

BLYNK_WRITE(V12)
{
    int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
    // pinValue = map(pinValue, 0, 255, -255, 255);

    if (pinValue > -10 && pinValue < 10)
    {
        pinValue = 0;
    }

    Serial.print("V12 = ");
    Serial.println(pinValue);
    X = pinValue;
}

BLYNK_WRITE(V14)
{
    int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
    // pinValue = map(pinValue, 0, 255, -255, 255);

    if (pinValue > -10 && pinValue < 10)
    {
        pinValue = 0;
    }

    Serial.print("V14 = ");
    Serial.println(pinValue);
    Y = pinValue;
}

BLYNK_WRITE(V7)
{
    String pinValue = param.asStr(); // assigning incoming value from pin V1 to a variable
    Serial.println(pinValue);
}

BLYNK_WRITE(V11)
{
    int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
    speed = pinValue;
}

// Forward
BLYNK_WRITE(V6)
{
    int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
    Serial.print("V6 = ");
    Serial.println(pinValue);
    if (pinValue == 1)
    {
        forward(speed);
    }
    else
    {
        stop();
    }
}

// Backward
BLYNK_WRITE(V8)
{
    int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
    Serial.print("V8 = ");
    Serial.println(pinValue);
    if (pinValue == 1)
    {
        backward(speed);
    }
    else
    {
        stop();
    }
}

// Left
BLYNK_WRITE(V9)
{
    int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
    Serial.print("V9 = ");
    Serial.println(pinValue);
    if (pinValue == 1)
    {
        left(speed);
    }
    else
    {
        stop();
    }
}

// Right
BLYNK_WRITE(V10)
{
    int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
    Serial.print("V10 = ");
    Serial.println(pinValue);
    if (pinValue == 1)
    {
        right(speed);
    }
    else
    {
        stop();
    }
}

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
    pinMode(SW, INPUT_PULLUP);
    pinMode(MOTOR_R_1, OUTPUT);
    pinMode(MOTOR_R_2, OUTPUT);
    pinMode(MOTOR_L_1, OUTPUT);
    pinMode(MOTOR_L_2, OUTPUT);
    // ledcSetup(ledChannel, freq, resolution);
    ledcSetup(MOTOR_R_1_CH, 5000, 8);
    ledcSetup(MOTOR_R_2_CH, 5000, 8);
    ledcSetup(MOTOR_L_1_CH, 5000, 8);
    ledcSetup(MOTOR_L_2_CH, 5000, 8);
    // ledcAttachPin(GPIO, channel)
    ledcAttachPin(MOTOR_R_1, 6);
    ledcAttachPin(MOTOR_R_2, 7);
    ledcAttachPin(MOTOR_L_1, 4);
    ledcAttachPin(MOTOR_L_2, 5);

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
    handle_car_joystick(X, Y);
}

void handle_car_joystick(int x_val, int y_val)
{
    x_val = map(x_val, -255, 255, -150, 150);
    y_val = map(y_val, -255, 255, -150, 150);

    if (-5 < x_val && x_val < 5)
    {
        x_val = 0;
    }
    if (-5 < y_val && y_val < 5)
    {
        y_val = 0;
    }

    // doing calculations from the joystick to speed
    int turning_percent = 1;
    int base_speed = x_val;
    int left_speed = base_speed - (y_val * turning_percent);
    int right_speed = base_speed + (y_val * turning_percent);
    motor(left_speed, right_speed);
}

/*
control motor right speed = (  -255   <->   255  )
                            (backward <-> forward)
*/
void motor_right(int speed)
{
    if (speed > 255)
        speed = 255;
    else if (speed < -255)
        speed = -255;

    // ledcWrite(channel, dutycycle)
    if (speed > 0)
    {
        ledcWrite(MOTOR_R_1_CH, 0);
        ledcWrite(MOTOR_R_2_CH, speed);
    }
    else if (speed < 0)
    {
        ledcWrite(MOTOR_R_1_CH, -speed);
        ledcWrite(MOTOR_R_2_CH, 0);
    }
    else
    {
        ledcWrite(MOTOR_R_1_CH, 0);
        ledcWrite(MOTOR_R_2_CH, 0);
    }
}

/*
control motor left speed = (  -255   <->   255  )
                           (backward <-> forward)
*/
void motor_left(int speed)
{
    if (speed > 255)
        speed = 255;
    else if (speed < -255)
        speed = -255;

    // ledcWrite(channel, dutycycle)
    if (speed > 0)
    {
        ledcWrite(MOTOR_L_1_CH, 0);
        ledcWrite(MOTOR_L_2_CH, speed);
    }
    else if (speed < 0)
    {
        ledcWrite(MOTOR_L_1_CH, -speed);
        ledcWrite(MOTOR_L_2_CH, 0);
    }
    else
    {
        ledcWrite(MOTOR_L_1_CH, 0);
        ledcWrite(MOTOR_L_2_CH, 0);
    }
}

void stop()
{
    motor(0, 0);
}

void motor(int left_speed, int right_speed)
{
    motor_right(right_speed);
    motor_left(left_speed);
}

void forward(int speed)
{
    motor(speed, speed);
}

void backward(int speed)
{
    motor(-speed, -speed);
}

void left_around(int speed)
{
    motor(speed, -speed);
}

void right_around(int speed)
{
    motor(-speed, speed);
}

void right(int speed)
{
    motor(speed / 5, speed);
}

void left(int speed)
{
    motor(speed, speed / 5);
}