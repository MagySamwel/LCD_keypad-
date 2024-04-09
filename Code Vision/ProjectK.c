#include <mega16.h>
#include <alcd.h>
char keypad();
void main(void)
{
    unsigned int counter=0; //to clear the lcd when the 2 lines is full (reading 32 numbers)
    char number;
    DDRC=0b00000111;  //1 unused pin, 4 rows (input), 3 columns (output)
    PORTC=0b11111000; // enable pull up resistance for input pins     
    lcd_init(16);
       
    while(1)
    {       
     number=keypad();
          
     if (counter == 32)
     {
     lcd_clear(); // if the lcd display is full
     counter = 0;
     } 
     
    counter++;
    lcd_printf("%c", number);
    }
}
char keypad()
{
    while (1)
    {
        PORTC.0 = 0; PORTC.1 = 1; PORTC.2 = 1;
        //Only C1 is activated    (first column)
        switch (PINC)
        {
        case 0b11110110:       // first row is activated (be set with 0)  (col:1 , row 1)
            while (PINC.3 == 0);
            return '1';
            break;

        case 0b11101110:       // second row is activated (be set with 0)  (col:1 , row 2)
            while (PINC.4 == 0);
            return '4';
            break;

        case 0b11011110:       // third row is activated (be set with 0)   (col:1 , row 3)
            while (PINC.5 == 0);
            return '7';
            break;


        }


        PORTC.0 = 1; PORTC.1 = 0; PORTC.2 = 1;
        //Only C2 is activated       (second column)
        switch (PINC)
        {
        case 0b11110101:           // first row is activated (be set with 0)  (col:2 , row 1)
            while (PINC.3 == 0);
            return '2';
            break;

        case 0b11101101:           // second row is activated (be set with 0)  (col: , row 2)
            while (PINC.4 == 0);
            return '5';
            break;

        case 0b11011101:           // third row is activated (be set with 0)  (col:1 , row 3)
            while (PINC.5 == 0);
            return '8';
            break;

        case 0b10111101:           // fourth row is activated (be set with 0)  (col:1 , row 4)
            while (PINC.6 == 0);
            return '0';
            break;

        }


        PORTC.0 = 1; PORTC.1 = 1; PORTC.2 = 0;
        //Only C3 is activated       (third column)
        switch (PINC)
        {
        case 0b11110011:           // first row is activated (be set with 0)  (col:1 , row 1)
            while (PINC.3 == 0);
            return '3';
            break;

        case 0b11101011:           // second row is activated (be set with 0)  (col:1 , row 2)
            while (PINC.4 == 0);
            return '6';
            break;

        case 0b11011011:           // third row is activated (be set with 0)  (col:1 , row 3)
            while (PINC.5 == 0);
            return '9';
            break;

        }

    }
}

