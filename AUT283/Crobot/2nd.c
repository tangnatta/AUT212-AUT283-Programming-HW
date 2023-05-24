// C Robot Simulator

/* Sensor
PA0 : -12.0,  0.0
PA1 : - 6.0, 27.5
PA2 :   0.0, 27.5
PA3 :   6.0, 27.5
PA4 :  12.0,  0.0
*/

int PA0 = 0, PA1 = 1, PA2 = 2, PA3 = 3, PA4 = 4;

int BLACK = 0;
int WHITE = 1024;

int centerLeft = 0, centerMiddle = 0, centerRight = 0, sideLeft = 0, sideRight = 0;

void setup()
{
    ao();
    lcd("Press SW1");
    sw1_press();
    lcd("Started!");

    //! ตามโจทย์จารย์
    runCrossCounter(1);
    turnRight();
    runCrossCounter(1);
    turnRight();
    runCrossCounter(3);
    turnRight();
    turnRight();
    runCrossCounter(2);
    ao();

    //! ตามโจทย์จารย์ + เพิ่มเติม 1
    turnLeft();
    runCrossCounter(1);
    ao();

    // //! ทดลอง
    // runCrossCounter(1);
    // turnRight();
    // runCrossCounter(3);
    // turnRight();
    // runCrossCounter(2);
    // turnRight();
    // turnRight();
    // runCrossCounter(2);
    // ao();
}

void loop()
{
}

/* Basic Line Tracking */
void lineTracking()
{
    lcd("lineTracking");

    centerLeft = analog(PA1);
    centerRight = analog(PA3);

    //! Tle Sensei Ver.
    if (centerLeft == WHITE && centerRight == WHITE)
    {
        fd(100);
    }
    else if (centerLeft == WHITE && centerRight == BLACK)
    {
        fd2(100, -40);
    }
    else if (centerLeft == BLACK && centerRight == WHITE)
    {
        fd2(-40, 100);
    }
    else if (centerLeft == BLACK && centerRight == BLACK)
    {
        fd(100);
    }

    // //!Mine Ver.
    // if (centerLeft == BLACK && centerRight == WHITE)
    // {
    //     fd2(-50, 80);
    // }
    // else if (centerLeft == WHITE && centerRight == BLACK)
    // {
    //     fd2(80, -50);
    // }
    // // //Perfect witḣTruth Table a bit Slower more condition
    // // else if (centerLeft == BLACK && centerRight == BLACK)
    // // {
    // //     fd2(100, 100);
    // // }
    // // else if (centerLeft == WHITE && centerRight == WHITE)
    // // {
    // //     fd2(100, 100);
    // // }
    // else
    // {
    //     fd(100);
    // }
    lcd("1:%d,3:%d", centerLeft, centerRight);
}

void runCrossCounter(int crossCounter)
{
    lcd("runCrossCounter");

    ao();
    if (sideLeft == BLACK || sideRight == BLACK)
    {
        while (sideLeft == BLACK || sideRight == BLACK)
        {
            sideLeft = analog(PA0);
            sideRight = analog(PA4);
            lineTracking();
        }
    }
    for (int i = 1; i <= crossCounter; i++)
    {
        if (i != crossCounter)
        {
            sideLeft = analog(PA0);
            sideRight = analog(PA4);
            while (sideLeft == WHITE || sideRight == WHITE)
            {
                sideLeft = analog(PA0);
                sideRight = analog(PA4);
                lineTracking();
            }
            while (sideLeft == BLACK || sideRight == BLACK)
            {
                sideLeft = analog(PA0);
                sideRight = analog(PA4);
                lineTracking();
            }
        }
        else
        {
            sideLeft = analog(PA0);
            sideRight = analog(PA4);
            // MORE ADD
            // MORE ADD
            while (sideLeft == WHITE || sideRight == WHITE)
            {
                sideLeft = analog(PA0);
                sideRight = analog(PA4);
                lineTracking();
            }
        }
    }
}

void turnLeft()
{
    lcd("turnLeft");

    fd2(-45, 50);
    while (analog(PA2) == BLACK)
        ;
    while (analog(PA2) == WHITE)
        ;
    while (analog(PA3) == WHITE)
        ;
}

void turnRight()
{
    lcd("turnRight");

    fd2(50, -45);
    while (analog(PA2) == BLACK)
        ;
    while (analog(PA2) == WHITE)
        ;
    while (analog(PA1) == WHITE)
        ;
}