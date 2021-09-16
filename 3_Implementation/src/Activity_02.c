#include <avr/io.h>
#include <util/delay.h>
int gpio_activity_2(){
 if(!(PIND&(1<<PD1)))
     {
         PORTD|=(1<<PD0);
         _delay_ms(20);
         LCD_Init();
       LCD_Command(0xC0);
       LCD_String("Heater is ON");

     }
     else
    {
     PORTD&=~(1<<PD0);
     LCD_Init();
     LCD_Command(0xC0);
       LCD_String("Heater Is OFF");
     _delay_ms(200);
     }
return 0;
}
