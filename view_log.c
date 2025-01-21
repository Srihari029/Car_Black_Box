#include "black_box.h"

extern unsigned char i,key;
unsigned char count = 0;

void view_log()
{
    char title[] = "# TIME     EV SP";
    unsigned char log_disp[] = "    :  :        ";
    
    log_disp[0]  = (count/10) + '0';
    log_disp[2]  = read_ext_EEPROM(count+0);
    log_disp[3]  = read_ext_EEPROM(count+1);
    log_disp[5]  = read_ext_EEPROM(count+2);
    log_disp[6]  = read_ext_EEPROM(count+3);
    log_disp[8]  = read_ext_EEPROM(count+4);
    log_disp[9]  = read_ext_EEPROM(count+5);
    log_disp[11] = read_ext_EEPROM(count+6);
    log_disp[12] = read_ext_EEPROM(count+7);
    log_disp[14] = read_ext_EEPROM(count+8);
    log_disp[15] = read_ext_EEPROM(count+9);
    
    clcd_print(title,LINE1(0));
    clcd_print(log_disp,LINE2(0));
    // If no logs
    if(i == 0)
    {
        CLEAR_DISP_SCREEN;
        clcd_print("  NO LOGS!!     ",LINE1(0));
        __delay_ms(5000); // Display for 5 secs
        state = e_main_menu;
    }
    
    if(key == 1 && count > 0)
        count -= 10;
    else if(key == 2 && count < i-10)
        count += 10;
    // Return to main menu
    else if(key == 12)
    {
        CLEAR_DISP_SCREEN;
        state = e_main_menu;
    }
    
}