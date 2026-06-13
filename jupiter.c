#include <AFMotor.h>
#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BT(10, 11); // RX, TX

#define MOTOR_PORT  4
#define MOTOR_WTIME 100 //ms

//DC Motor
AF_DCMotor motor(MOTOR_PORT);

//Servo Motor
#define SERVO_PIN 9 //Servo1=10, Servo2=9
#define SERVO_ROT_MIN   60
#define SERVO_ROT_MAX   120
#define SERVO_ROT_STEP   20

Servo servo_motor;

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

void switch_ready()
{
    servo_motor.write(SERVO_ROT_MIN);
    Serial.println("SWITCH : READY");
}

void switch_off()
{
    int pos;

    for (pos = SERVO_ROT_MIN; pos <= SERVO_ROT_MAX; pos += SERVO_ROT_STEP) {
        servo_motor.write(pos);
         delay(200);
        Serial.println("SWITCH : >>");
    }
    
    switch_ready();
    Serial.println("SWITCH : OFF");    
}

void setup()
{
    Serial.begin(9600);
    BT.begin(9600);    

    motor.setSpeed(200);

    servo_motor.attach(SERVO_PIN);    

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
                switch_off();
                break;

            case '2':
                switch_off();
                break;

            case '3':
                switch_ready();
                rack_right();
                break;

            case '4':
                switch_ready();
                rack_left();
                break;
        }
    }
}
