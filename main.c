/*
 */

#include <avr/io.h>
#include <util/delay.h>
#define LCD_Data_Dir DDRB		/* Define LCD data port direction */
#define LCD_Command_Dir DDRC		/* Define LCD command port direction register */
#define LCD_Data_Port PORTB		/* Define LCD data port */
#define LCD_Command_Port PORTC		/* Define LCD data port */
#define RS PC4				/* Define Register Select (data/command reg.)pin */
#define RW PC1				/* Define Read/Write signal pin */
#define EN PC2				/* Define Enable signal pin */


void LCD_Command(unsigned char cmnd)
{
	LCD_Data_Port= cmnd;
	LCD_Command_Port &= ~(1<<RS);
	LCD_Command_Port &= ~(1<<RW);
	LCD_Command_Port |= (1<<EN);
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(3);
}

void LCD_Char (unsigned char char_data)
{
	LCD_Data_Port= char_data;
	LCD_Command_Port |= (1<<RS);
	LCD_Command_Port &= ~(1<<RW);
	LCD_Command_Port |= (1<<EN);
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(1);
}

void LCD_Init (void)
{
	LCD_Command_Dir = 0xFF;
	LCD_Data_Dir = 0xFF;
	_delay_ms(2000);

	LCD_Command (0x38);
	LCD_Command (0x0C);
	LCD_Command (0x06);
	LCD_Command (0x01);
	LCD_Command (0x80);
}

void LCD_String (char *str)		/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)		/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);
	}
}

void LCD_String_xy (char row, char pos, char *str)/* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);
	LCD_String(str);
	LCD_Clear();
}

void LCD_Clear()
{
	LCD_Command (0x01);
	_delay_ms(2000);
	LCD_Command (0x80);
}

int main(void)
{

    LCD_Init();

	LCD_String("Hello!");
	LCD_Command(0xC0);/* Go to 2nd line*/
	LCD_String("PLease sit");
	_delay_ms(200);

  DDRD|=(1<<PD0);
 DDRD|=(1<<PD4);
 DDRD&=~(1<<PD7);
 PORTD|=(1<<PD7);
 /*Heater switch configuration*/

    DDRD&=~(1<<PD1);
    PORTD|=(1<<PD1);



    ADMUX=(1<<REFS0);
    ADCSRA|=(1<<ADEN);
    ADCSRA|=(7<<ADPS0);


    UBRR0L = 103;
    UBRR0H = (103>>8)&0x00ff;
    UCSR0C|=(1<<UMSEL00);
    UCSR0C|=(1<<UCSZ00)|(1<<UCSZ01);
    UCSR0B =(1<<TXEN0)|(1<<TXCIE0);
    while(1)
    {
   int gpio_activity( );
   int gpio_activity_2();
   int gpio_activity_3();
    }

    return 0;
}
