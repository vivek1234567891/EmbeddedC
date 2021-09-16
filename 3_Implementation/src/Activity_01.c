#include <avr/io.h>
#include <util/delay.h>



int gpio_activity( )
{
 if(!(PIND&(1<<PD7)))
      {
       PORTD|=(1<<PD4);
       LCD_Init();
       LCD_String("Person is Seated");
       LCD_Command(0xC0);
        _delay_ms(20);


      }
        else{


        PORTD&=~(1<<PD4);
        _delay_ms(200);
        LCD_Init();
       LCD_String("Empty Seat");
       LCD_Command(0xC0);
        }

return 0;
}
