#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX

#define MOTOR_PORT  4
#define MOTOR_WTIME 100 //ms

AF_DCMotor motor(MOTOR_PORT);

void rack_left()
{
    motor.run(FORWARD);
    delay(MOTOR_WTIME);
    motor.run(RELEASE);

    Serial.println("RACK : LEFT");
}

void rack_right()
{
    motor.run(BACKWARD);
    delay(MOTOR_WTIME);
    motor.run(RELEASE);

    Serial.println("RACK : RIGH");
}

void setup()
{
    Serial.begin(9600);
    BT.begin(9600);    

    motor.setSpeed(200);

    Serial.println("Welcome !!!");
}

void loop()
{
    if (BT.available())
    {
        char cmd = BT.read();

        Serial.print("CMD: ");
        Serial.println(cmd);

        switch(cmd)
        {
            case '1':
                rack_left();
                break;

            case '2':
                rack_left();
                break;

            case '3':
                rack_right();
                break;

            case '4':
                rack_left();
                break;
        }
    }
}
