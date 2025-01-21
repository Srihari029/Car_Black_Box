#include "black_box.h"
#include "uart.h"
State_t state;
unsigned char key;

// Initialize required peripherals
void init_config()
{
    init_adc();
    init_clcd();
    init_matrix_keypad();
    init_uart();
    init_i2c();
    init_ds1307();
    
    state = e_dashboard;
}

void main(void) 
{
    init_config();
    while(1)
    {
        // Detect key press
        key = read_switches(STATE_CHANGE);
        switch (state)
        {
            case e_dashboard:
                // Display dashboard
                view_dashboard();
                break;
            
            case e_main_menu:
                // Display main-menu
                display_main_menu();
                break;
            
            case e_view_log:
                // Display dashboard
                view_log();
                break;
                 
            case e_download_log:
                // Download logs
                download_log();
                break;
                
            case e_clear_log:
                // Clear logs
                clear_log();
                break;               
                      
            case e_set_time:
                // Set time
                set_time();
                break;
        }
    }
}
