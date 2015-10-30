#ifndef ARDUINOCONTROLLER
#define ARDUINOCONTROLLER
#include "includes/firmata.h"

class ArduinoController
{
    public:
        ArduinoController();
        void init();
		void digitalWrite(unsigned char pin, unsigned char mode);
    private:
        Firmata* firmata;
};

#endif
