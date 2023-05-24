int PA0 = 0;
int PA1 = 1;
int PA2 = 2;
int PA3 = 3;
int PA4 = 4;

int sideLeft = 0;
int sideRight = 0;
int centerLeft = 0;
int centerRight = 0;

int WHITE = 1024;
int BLACK = 0;
void setup()
{
    sw1_press();
}
void loop()
{
    runCrossCount(1);
    turnLeft();
    runCrossCount(1);
    turnLeft();
    ao();
    sw1_press();
}
void lineTracking()
{
    centerLeft = analog(PA1);
    centerRight = analog(PA3);
    if (centerLeft == WHITE && centerRight == WHITE)
    {
        fd(80);
    }
    else if (centerLeft == BLACK && centerRight == WHITE)
    {
        fd2(-20, 50);
    }
    else if (centerLeft == WHITE && centerRight == BLACK)
    {
        fd2(50, -20);
    }
    else if (centerLeft == BLACK && centerRight == BLACK)
    {
        fd(80);
    }
}
void runCrossCount(int crossCount)
{
    for (int i = 1; i <= crossCount; i++)
    {
        if (i != crossCount)
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
    fd2(-45, 50);
    while (analog(PA1) == BLACK)
        ;
    while (analog(PA1) == WHITE)
        ;
    while (analog(PA2) == BLACK)
        ;
    while (analog(PA2) == WHITE)
        ;
    fd(50);
    sleep(100);
}