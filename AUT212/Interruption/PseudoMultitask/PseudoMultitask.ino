class PseudoMultitask
{
private:
    unsigned long _lastTime;
    unsigned long _onTime;
    unsigned long _offTime;
    void *_task;

public:
    PseudoMultitask();
    PseudoMultitask(unsigned long Interval, void (*f)())
    {
        setInterval(Interval);
        setTask(f);
    }
    PseudoMultitask(unsigned long onTime, unsigned long offTime, void (*f)())
    {
        setTiming(onTime, offTime);
        setTask(f);
    }
    ~PseudoMultitask();
    void setTiming(unsigned long onTime, unsigned long offTime)
    {
        _onTime = onTime;
        _offTime = offTime;
        _lastTime = millis();
    }
    void setInterval(unsigned long Interval)
    {
        setTiming(Interval, Interval);
    }
    void setTask(void (*f)())
    {
        _task = f;
    }
};

#define LED_RED 13
const unsigned long interval = 1000;
unsigned long previousTime = 0;
int ledState = LOW;
void setup()
{
    pinMode(LED_RED, OUTPUT);
}
void loop()
{
    unsigned long currentTime = millis();
    if (currentTime - previousTime >= interval)
    {
        // Update the timing for the next time around
        previousTime = currentTime;
        // Action Code
        ledState = !ledState; // change it’s state. ! means ”not” logically
        digitalWrite(LED_RED, ledState);
    }
}