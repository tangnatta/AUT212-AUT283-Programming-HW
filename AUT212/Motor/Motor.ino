/* Example code for NKP V2.2 line tracking robot
 * Jan. 23, 2023 : Edited by tangnatta
 */

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

    while (digitalRead(SW) == 1)
        ;
}

void loop()
{
    forward(100);
    delay(1000);
    backward(100);
    delay(1000);
    right_around(100);
    delay(1000);
    left_around(100);
    delay(1000);
    right(100);
    delay(1000);
    left(100);
    delay(1000);
    stop();
    delay(1000);
}

/*
control motor right speed = (  -255   <->   255  )
                            (backward <-> forward)
*/
void motor_right(int speed)
{
    // ledcWrite(channel, dutycycle)
    if (speed > 0)
    {
        ledcWrite(MOTOR_R_1_CH, 0);
        ledcWrite(MOTOR_R_2_CH, speed);
    }
    else
    {
        ledcWrite(MOTOR_R_1_CH, -speed);
        ledcWrite(MOTOR_R_2_CH, 0);
    }
}

/*
control motor left speed = (  -255   <->   255  )
                           (backward <-> forward)
*/
void motor_left(int speed)
{
    // ledcWrite(channel, dutycycle)
    if (speed > 0)
    {
        ledcWrite(MOTOR_L_1_CH, 0);
        ledcWrite(MOTOR_L_2_CH, speed);
    }
    else
    {
        ledcWrite(MOTOR_L_1_CH, -speed);
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
    motor(0, speed);
}

void left(int speed)
{
    motor(speed, 0);
}