#include "black_box.h"

unsigned char clock_reg[3];
unsigned char data[]= "                ";
extern char key;
int dly;

// Function to get time from RTC
void get_time(void)
{
	clock_reg[0] = read_RTC(HOUR_ADDR);
	clock_reg[1] = read_RTC(MIN_ADDR);
	clock_reg[2] = read_RTC(SEC_ADDR);

	if (clock_reg[0] & 0x40)
	{
		data[0] = '0' + ((clock_reg[0] >> 4) & 0x01);
		data[1] = '0' + (clock_reg[0] & 0x0F);
	}
	else
	{
		data[0] = '0' + ((clock_reg[0] >> 4) & 0x03);
		data[1] = '0' + (clock_reg[0] & 0x0F);
	}
	data[2] = ':';
	data[3] = '0' + ((clock_reg[1] >> 4) & 0x0F);
	data[4] = '0' + (clock_reg[1] & 0x0F);
	data[5] = ':';
	data[6] = '0' + ((clock_reg[2] >> 4) & 0x0F);
	data[7] = '0' + (clock_reg[2] & 0x0F);
	//data[8] = '\0';
}

void set_time()
{
    //CLEAR_DISP_SCREEN;
    static unsigned char field = 0,set = 1;
    static char hour,min,sec;
    
    if(set)
    {
        hour = ((data[0] - 48)*10) + (data[1] - 48);
        min = ((data[3] - 48)*10) + (data[4] - 48);
        sec = ((data[6] - 48)*10) + (data[7] - 48);
        set = 0;
    }
    // Increase hour,minute and second
    if(key == 1)
    {
        if(field == 0)
        {
            hour++;
            if(hour > 23)
                hour = 0;
        }
        else if(field == 1)
        {
            min++;
            if(min > 59)
                min = 0;
        }
        else if(field == 2)
        {
            sec++;
            if(sec > 59)
                sec = 0;
        }
    }
    // Change fields
    else if(key == 2)
    {
        field++;
        if(field > 2)
            field = 0;
    }
    // Save the time and exit
    else if(key == 11)
    {
        write_RTC(HOUR_ADDR,((hour/10) << 4 | hour % 10));  // Hour
        write_RTC(MIN_ADDR,((min/10) << 4 | min % 10));     // Minute
        write_RTC(SEC_ADDR,((sec/10) << 4 | sec % 10));     // Second
        clcd_print("SET TIME SUCCESS",LINE1(0));
        __delay_ms(800);
        CLEAR_DISP_SCREEN;
        state = e_main_menu;
        return;
    }
    // Exit
    else if(key == 12)
    {
        CLEAR_DISP_SCREEN;
        state = e_main_menu;
        return;
    }
    
    clcd_print("HH:MM:SS        ",LINE1(0));
    if(dly++ < 500)
    {
        clcd_putch((hour/10)+'0',LINE2(0));
        clcd_putch((hour%10)+'0',LINE2(1));
        clcd_putch(':',LINE2(2));
        clcd_putch((min/10) +'0',LINE2(3));
        clcd_putch((min%10) +'0',LINE2(4));
        clcd_putch(':',LINE2(5));
        clcd_putch((sec/10) +'0',LINE2(6));
        clcd_putch((sec%10) +'0',LINE2(7));
    }
    else if(dly < 1000)
    {
        if(field == 0)
        {
            clcd_print("  ",LINE2(0));       
        }
        else if(field == 1)
        {
            clcd_print("  ",LINE2(3));
        }
        else if(field == 2)
        {
            clcd_print("  ",LINE2(6));
        }
    }
    else 
        dly = 0;
}