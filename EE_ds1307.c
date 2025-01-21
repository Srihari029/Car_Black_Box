#include "black_box.h"
#include "EE_ds1307.h"
/* 
 * DS1307 Slave address
 * A0  -  Write Mode
 * A1  -  Read Mode
 */

void write_ext_EEPROM(unsigned char address, unsigned char data)
{
	i2c_start();
	i2c_write(EE_SLAVE_WRITE);
	i2c_write(address);
	i2c_write(data);
	i2c_stop();
    for(int i = 0;i < 3000; i++);
}

unsigned char read_ext_EEPROM(unsigned char address)
{
	unsigned char data;

	i2c_start();
	i2c_write(EE_SLAVE_WRITE);
	i2c_write(address);
	i2c_rep_start();
	i2c_write(EE_SLAVE_READ);
	data = i2c_read();
	i2c_stop();

	return data;
}