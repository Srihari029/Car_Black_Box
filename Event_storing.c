#include "black_box.h"

extern char gearval[9][3];
extern char data[];
extern int gear;
unsigned char i = 0;

void event_store()
{
    unsigned char store_arr[10];
    unsigned short adc_val = read_adc(CHANNEL4);
    unsigned short speed = adc_val/10.24;
    
    store_arr[0] = data[0];
    store_arr[1] = data[1];
    store_arr[2] = data[3];
    store_arr[3] = data[4];
    store_arr[4] = data[6];
    store_arr[5] = data[7];
    store_arr[6] = gearval[gear][0];
    store_arr[7] = gearval[gear][1];
    store_arr[8] = speed/10 + '0';
    store_arr[9] = speed%10 + '0';
    
    if(i == 100)
    {
        unsigned char j; 
        for(j = 10; j < 100; j++)
        {
            unsigned char ch = read_ext_EEPROM(j);
            write_ext_EEPROM(j-10, ch);
        }
        i = 90;
    }
    // Write data in External EEPROM
    for(char j=0; j < 10; j++)
    {
        write_ext_EEPROM(i, store_arr[j]);
        i++;
    }
}

