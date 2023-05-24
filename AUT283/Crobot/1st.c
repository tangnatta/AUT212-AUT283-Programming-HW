// C Robot Simulator

int BLACK = 0;
int WHITE = 1024;

void setup()
{
    lcd("Press SW1");
    sw1_press();
    lcd("SW1 Pressed");
    // sleep(500);
    // motor(1, 100);
    // motor(2, -100);
    // sleep(700);
}

void loop()
{
    // lcd("sw1: %d, sw2: %d, sw3: %d", sw1(), sw2(), sw3());

    // วิ่งสี่เหลี่ยม
    // for (int i = 0; i < 4; i++)
    // {
    //     fd(100);
    //     sleep(1000);
    //     motor(1, 100);
    //     motor(2, -100);
    //     sleep(681);
    // }

    line_Tracking();
}

int S0 = 0, S1 = 0, S2 = 0, S3 = 0, S4 = 0, S5 = 0, S6 = 0, S7 = 0, S8 = 0;

void read_sensor()
{
    // S0 = analog(0);
    S1 = analog(1);
    // S2 = analog(2);
    S3 = analog(3);
    // S4 = analog(4);
    // S5 = analog(5);
    // S6 = analog(6);
    // S7 = analog(7);
    // S8 = analog(8);

    // lcd("S0: %d, S1: %d, S2: %d, S3: %d, S4: %d, S5: %d, S6: %d, S7: %d, S8: %d", S0, S1, S2, S3, S4, S5, S6, S7, S8);
}

void line_Tracking()
{
    read_sensor();

    int CenterLeft = S1;
    int CenterRight = S3;

    if (CenterLeft == BLACK && CenterRight == WHITE)
    {
        fd2(-50, 80);
    }
    else if (CenterLeft == WHITE && CenterRight == BLACK)
    {
        fd2(80, -50);
    }
    else if (CenterLeft == BLACK && CenterRight == BLACK)
    {
        fd(80);
    }
    else
    {
        fd(80);
    }
}