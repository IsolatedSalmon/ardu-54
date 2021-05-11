#include <AP_HAL/AP_HAL.h>

const AP_HAL::HAL& hal = AP_HAL::get_HAL();

void setup();
void loop();

void setup()
{
    hal.console->begin(57600);
    // hal.rcin->init();
    hal.console->printf("begin rcin test\n");
}

void loop()
{
    u_int8_t ret;
    ret = hal.rcin->num_channels();
    for(uint8_t i=0;i<ret;i++)
    {
        hal.console->printf("%d is %d", i, hal.rcin->read(i));
    }
    hal.console->printf("\n");
    hal.scheduler->delay(1000);
}

AP_HAL_MAIN();