#include "adc.h"
#include "clcd.h"
#include "matrix_keypad.h"
#include "i2c.h"
#include "eeprom.h"
#include "EE_ds1307.h"

#include <xc.h>

/* Enum for maintaining the app state */
typedef enum {
    e_dashboard, e_main_menu, e_view_log, e_set_time, e_download_log, e_clear_log
} State_t;

extern State_t state; 

#define XTAL_FREQ 20000000
//Function declarations

//Dashboard function declaration
void view_dashboard(void);

//Main menu display function declaration
void display_main_menu(void);

//Storing events function declaration
void event_store(void);

////Password function declaration
//void password(void);

//View log function declaration
void view_log(void);

////Reading events function declaration
//void event_reader(void);
//
////Change password function declaration
//void change_password(void);

//Set time function declaration
void set_time(void);

//Download log function declaration
void download_log(void);

//Clear log function declaration
void clear_log(void);