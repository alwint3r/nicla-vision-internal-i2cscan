#include <Arduino.h>
#include <Wire.h>

void setup()
{
    Serial.begin(115200);
    while (!Serial);

    Wire1.begin();
}

void loop()
{
    for (int i = 0; i < 127; i++)
    {
        Wire1.beginTransmission(i);
        if (Wire1.endTransmission() == 0)
        {
            Serial.print("Found I2C device at 0x");
            Serial.println(i, HEX);
        }
    }

    delay(3000);
}