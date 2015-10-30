#include "ArduinoController.hpp"
#include "includes/firmata.h"

ArduinoController::ArduinoController()
{
}

void ArduinoController::init()
{
    firmata = new Firmata("/dev/ttyACM0");
    firmata->setPinMode(13, 0x01);
}

void ArduinoController::digitalWrite(unsigned char pin, unsigned char mode)
{
    firmata->writeDigitalPin(pin, mode);
}
		
