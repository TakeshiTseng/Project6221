#ifndef __I2C_H__
#defined __I2C_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define I2C_SLAVE	0x0703

int i2c_open();
bool i2c_select_device(int i2c, int addr, char * name);
bool i2c_write(int i2c, unit8_t *buf, int len);
bool i2c_read(int i2c, unit8_t *buf, int len);

#endif