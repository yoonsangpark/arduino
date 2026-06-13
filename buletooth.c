#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX

void setup()
{
    Serial.begin(9600);
    BT.begin(9600);   // HC-06 기본 속도

    Serial.println("HC-06 Ready");
}

void loop()
{
    // 스마트폰 -> Arduino
    if (BT.available())
    {
        char c = BT.read();

        Serial.print("RX: ");
        Serial.println(c);

        // 받은 데이터 에코
        BT.print("Received: ");
        BT.println(c);
    }

    // Arduino IDE 시리얼 모니터 -> 스마트폰
    if (Serial.available())
    {
        BT.write(Serial.read());
    }
}
