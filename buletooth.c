#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX

void setup()
{
    Serial.begin(9600);
    BT.begin(9600);

    Serial.println("HC-06 Ready");
}

void loop()
{
    // Phone -> Arduino
    if (BT.available())
    {
        char c = BT.read();

        Serial.print("RX: ");
        Serial.println(c);
    }
}
