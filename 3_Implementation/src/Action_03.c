
#include <avr/io.h>
#include <util/delay.h>

uint16_t Read_ADC(uint8_t channel)
{
    ADMUX&=0xf8;
    channel=channel&(0b00000111);
    ADMUX|=channel;
    ADCSRA|=(1<<ADSC);
    return 0;
}
int gpio_activity_3()
{
    uint16_t temperature;
    TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);

    DDRB|=(1<<PB1);

    temperature=Read_ADC(0);
    if(temperature>0 && temperature<=200)
        OCR1A=205; /*20per duty cycle*/
    if(temperature>=210 && temperature<=500)
        OCR1A=410; /*40per duty cycle*/
    if(temperature>=510 && temperature<=700)
        OCR1A=717; /*70per duty cycle*/
    if(temperature>=710 && temperature<=1024)
        OCR1A=973; /*95per duty cycle*/
    return 0;
}
