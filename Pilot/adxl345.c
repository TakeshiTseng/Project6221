#include "adxl345.h"

bool read_adxl345(int& fd,short& x, short& y, short& z) {
	if(!i2c_select_device(fd,ADXL345,"ADXL345")) {
		return false;
	}

    char buf[7];
    buf[0] = 0x32; // This is the register we wish to read from

    if(!i2c_write(fd,buf,2)) {
        return false;
    }

    if (i2c_read(fd, buf, 6) != 6) { // Read back data into buf[]
        printf("Unable to read from slave\n");
        return false;
    } else {
        x = (buf[1]<<8) |  buf[0];
        y = (buf[3]<<8) |  buf[2];
        z = (buf[5]<<8) |  buf[4];
    }
    return true;
}