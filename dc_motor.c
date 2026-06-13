#include <AFMotor.h>

#define MPORT   4   // Port (1~4)
#define MDELAY  250

AF_DCMotor motor(MPORT);

void setup()
{
    Serial.begin(115200);
    motor.setSpeed(150);  // Speed (0~255)
}

void loop()
{
    Serial.println(">> Loop ...");

    Serial.println("FORWARD ...");
    motor.run(FORWARD);
    delay(MDELAY);

    motor.run(RELEASE);
    delay(MDELAY);

    Serial.println("BACKWARD ...");
    motor.run(BACKWARD);
    delay(MDELAY);

    motor.run(RELEASE);
    delay(MDELAY);
}
