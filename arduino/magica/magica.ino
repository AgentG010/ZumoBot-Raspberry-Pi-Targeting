#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 

void setup()
{
    lcd.begin(20, 4);
    Serial.begin(9600);
}

void loop()
{
    delay(300);
    if (Serial.available() > 0)
    {
        char bytes[Serial.available()];
        const int len = Serial.available();
        
        Serial.readBytes(bytes, len);
        Serial.flush();

        //Serial.print("you entered ");
        //Serial.println(bytes);
        lcd.clear();
        lcd.print(bytes);
    }
}
