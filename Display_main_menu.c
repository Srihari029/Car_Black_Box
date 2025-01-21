#include "black_box.h"

int menu_no = 0,indicate_flag = 1;
char *main_menu[] = {"View Log        ","Clear Log       ","Set Time        ","Download Log    "};
extern char key;

void display_main_menu()
{
    // Scroll menu up
    if(key == 1)
    {
        if(menu_no > 0 && indicate_flag == 1)
        {
            menu_no-- ;
            //indicate_flag = 1;
        }
        else
            indicate_flag = 1;
    }
    // Scroll menu down
    else if(key == 2)
    {
        if(menu_no < 2 && indicate_flag == 0)
        {
            menu_no++ ;
            //indicate_flag = 0;
        }
        else
            indicate_flag = 0;
    }
    
    if(indicate_flag)
    {
        clcd_putch('*',LINE1(2));
        clcd_putch(' ',LINE2(2));
    }
    else
    {
        clcd_putch(' ',LINE1(2));
        clcd_putch('*',LINE2(2));
    }
    
    // Choose main menu
    if(key == 11)
    {
        if(menu_no == 0)
        {
            if(indicate_flag)
                state = e_view_log;
            else
                state = e_clear_log;
        }
        else if(menu_no == 1)
        {
            if(indicate_flag)
                state = e_clear_log;
            else
            {
                CLEAR_DISP_SCREEN;
                state = e_set_time;
                return;
            }
        }
        else if(menu_no == 2)
        {
            if(indicate_flag)
            {
                CLEAR_DISP_SCREEN;
                state = e_set_time;
                return;
            }
            else
                state = e_download_log;
        }  
    }
    // Exit back to previous state
    else if(key == 12)
    {
        CLEAR_DISP_SCREEN;
        state = e_dashboard;
        return;
    }  
    
    // Display in CLCD
    clcd_print(main_menu[menu_no],LINE1(3));
    clcd_print(main_menu[menu_no + 1],LINE2(3)); 
    
    
}
