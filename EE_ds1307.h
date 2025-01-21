#ifndef Ds1307_H
#define Ds1307_H

#define EE_SLAVE_READ		0xA1
#define EE_SLAVE_WRITE		0xA0
#define RTC_SLAVE_READ		0xD1
#define RTC_SLAVE_WRITE		0xD0

#define SEC_ADDR		0x00
#define MIN_ADDR		0x01
#define HOUR_ADDR		0x02
//#define DAY_ADDR		0x03
//#define DATE_ADDR		0x04
//#define MONTH_ADDR		0x05
//#define YEAR_ADDR		0x06
#define CNTL_ADDR		0x07


void init_ds1307(void);
// RTC Time functions
void get_time(void);

// For Ext_EEPROM
void write_ext_EEPROM(unsigned char address1,  unsigned char data);
unsigned char read_ext_EEPROM(unsigned char address1);
// For RTC
void write_RTC(unsigned char address1,  unsigned char data);
unsigned char read_RTC(unsigned char address1);

#endif