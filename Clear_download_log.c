#include "black_box.h"
#include "uart.h"

extern unsigned char i;
extern char title;
unsigned char k = 0;

// Clearing logs
void clear_log()
{
    i = 0;
    CLEAR_DISP_SCREEN;
    clcd_print("CLEARING LOGS...",LINE1(0));
    __delay_ms(5000); // Display for 5 secs
    CLEAR_DISP_SCREEN;
    state = e_main_menu;
}

// Downloading logs
void download_log()
{
    unsigned char store_arr[10];
    puts("# TIME     EV SP");
    putch('\n');
    putch('\r');
    // If no logs present
    if(i == 0)
    {
        puts("NO LOGS FOUND   ");
        putch('\n');
        putch('\r');
        CLEAR_DISP_SCREEN;
        clcd_print("  NO LOGS!!     ",LINE1(0));
        __delay_ms(5000); // Display for 5 secs
        CLEAR_DISP_SCREEN;
        state = e_main_menu;
        return;
    }
    for(k ; k < i/10; k++)
    {
        store_arr[0] = k + '0';
        store_arr[1] = ' ';
        store_arr[2] = read_ext_EEPROM((k*10)+0);
        store_arr[3] = read_ext_EEPROM((k*10)+1);
        store_arr[4] = ';';
        store_arr[5] = read_ext_EEPROM((k*10)+2);
        store_arr[6] = read_ext_EEPROM((k*10)+3);
        store_arr[7] = ';';
        store_arr[8] = read_ext_EEPROM((k*10)+4);
        store_arr[9] = read_ext_EEPROM((k*10)+5);
        store_arr[10] = ' ';
        store_arr[11] = read_ext_EEPROM((k*10)+6);
        store_arr[12] = read_ext_EEPROM((k*10)+7);
        store_arr[13] = ' ';
        store_arr[14] = read_ext_EEPROM((k*10)+8);
        store_arr[15] = read_ext_EEPROM((k*10)+9);
        store_arr[16] = '\0';
        puts(store_arr);
        putch('\n');
        putch('\r');
    }
    
    CLEAR_DISP_SCREEN;
    clcd_print("DOWNLOADING LOGS",LINE1(0));
    __delay_ms(5000); // Display for 5 secs
    CLEAR_DISP_SCREEN;
    state = e_main_menu;
        
}