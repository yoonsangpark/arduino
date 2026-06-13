#include <AFMotor.h>

AF_DCMotor motor(4);   // Port (1~4)

void setup()
{
    Serial.begin(115200);
    motor.setSpeed(200);  // Speed (0~255)
}

void loop()
{
    Serial.println(">> Loop ...");

    Serial.println("FORWARD ...");
    motor.run(FORWARD);
    delay(3000);

    motor.run(RELEASE);
    delay(1000);

    Serial.println("BACKWARD ...");
    motor.run(BACKWARD);
    delay(3000);

    motor.run(RELEASE);
    delay(1000);
}
