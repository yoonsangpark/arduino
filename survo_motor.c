#include <Servo.h>

#define SERVO_PIN 9 //Servo1=10, Servo2=9

Servo servo_motor;

int pos = 0;

void setup() {
  Serial.begin(115200);

  servo_motor.attach(SERVO_PIN);
}

void loop() { 

  for (pos = 60; pos <= 120; pos += 20) {
    servo_motor.write(pos);
  
    delay(1000);
    Serial.print("servo_motor : ");
    Serial.println(pos);
  }
}
