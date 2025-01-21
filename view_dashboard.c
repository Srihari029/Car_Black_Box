#include "black_box.h"

extern char key;
char gearval[9][3] = {"ON","GN","G1","G2","G3","G4","G5","GR","C "};
int gear = 0;
extern unsigned char data[];
char title[] = "TIME     EV   SP";
 
void view_dashboard()
{
    get_time();
    // Speed using ADC
    unsigned short adc_val = read_adc(CHANNEL4);
    unsigned short speed = adc_val/10.24;
    
    if(gear && (gear != 8))
    {
        // Increase gear
        if(key == 1)
        {
            gear++;
            if(gear > 7)
                gear = 7;
            event_store();
        }
        // Decrease gear
        else if(key == 2)
        {
            gear--;
            if(gear < 1)
                gear = 1;
            event_store();
        }   
    }
    else if(gear == 0)
    {
        if(key == 1)
        {
            gear++;
            event_store();
        }
    }
    else
    {
        if(key == 1 || key == 2)
            gear = 1;
    }
    // Collision 
    if(key == 3)
    {
        gear = 8;
        event_store();
    }
    data[9] = gearval[gear][0];
    data[10] = gearval[gear][1];
    data[14] = (speed / 10)+'0';
    data[15] = (speed % 10)+'0';
    data[16] = '\0';
    // Print on CLCD
    clcd_print(data,LINE2(0));  // Time
    clcd_print(title,LINE1(0));
    
    
    // Enter main menu
    if(key == 11)
    {
        CLEAR_DISP_SCREEN;
        state = e_main_menu;
    }
}
