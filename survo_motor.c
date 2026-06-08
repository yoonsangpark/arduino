#include <Servo.h>

#define SERVO_MAIN_PIN 10
#define SERVO_SUB_PIN  11

Servo servo_main;
Servo servo_sub;

int pos = 0;

void setup() {
  Serial.begin(115200);

  servo_main.attach(SERVO_MAIN_PIN);
}

void loop() { 

  for (pos = 0; pos <= 180; pos += 10) {
    servo_main.write(pos);
  
    delay(1000);
    Serial.print("servo_main : ");
    Serial.println(pos);
  }
}
