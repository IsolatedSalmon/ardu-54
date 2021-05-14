#include <AP_HAL/AP_HAL.h>

const AP_HAL::HAL& hal = AP_HAL::get_HAL();
void setup();
void loop();

void uart_setup(AP_HAL::UARTDriver *uart, const char* name)
{
    if(uart ==nullptr)
    {
        return;
    }
    uart->begin(57600);
}

void setup()
{
    hal.scheduler->delay(1000);
    // hal.scheduler->register_timer_process(FUNCTOR_BIND_MEMBER)
    // uart_setup(hal.uartA,"UARTA");
    // uart_setup(hal.uartB,"UARTB");
    // uart_setup(hal.uartC,"UARTC");
    
}

void uart_test(AP_HAL::UARTDriver *uart, const char* name)
{
    if(uart==nullptr)
    {
        return;
    }
    uart->printf("%s at time %.3f\n", name, AP_HAL::millis()*0.001f);
}

void loop()
{
    hal.scheduler->delay(500);
    // uart_test(hal.uartA,"helloA");
    // uart_test(hal.uartB,"helloB");
    // uart_test(hal.uartC,"helloC");
    hal.console->printf("this is begin\n");
}
AP_HAL_MAIN();