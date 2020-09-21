#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 75000UL
#endif
#include <util/delay.h>

#define LED_PIN    PB4
#define BUTTON_PIN PB1


ISR(INT0_vect)
{
    PORTB = ~_BV(LED_PIN); //fixes first pulse timing issue

    PORTB =  _BV(LED_PIN); //No &= or |= to execute in a single cycle
    PORTB = ~_BV(LED_PIN); //_BV and ~ get optimized at compile time
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);

    _delay_us(7000);

    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
    PORTB =  _BV(LED_PIN);
    PORTB = ~_BV(LED_PIN);
}

int main (void)
{
    CLKPR =/*sic!*/ _BV(CLKPCE);    //enable clock prescaling 
                                    //see datasheet section 6.4.2)
    CLKPR =/*sic!*/ UINT8_C(0x07);  //divide clock by 128 from 9.6Mhz to 75kHz

    DDRB |=  _BV(   LED_PIN); // set BUTTON pin as  INPUT
    DDRB &= ~_BV(BUTTON_PIN); // set    LED pin as OUTPUT


    MCUCR = UINT8_C(0x03); //set INTO to trigger on a rising edge
    GIMSK = _BV(INT0);     //enable INTO in global interrupt mask

    sei(); //enable interrupts

    while(1) {
        ;
    }
    return 0;
}