#include "i2c.h"

int i2c_open() {
    char *fileName = "/dev/i2c-1";
    int fd;
    if ((fd = open(fileName, O_RDWR)) < 0) { // Open port for reading and writing
        printf("Failed to open i2c port\n");
    }
    
    return fd;
}

bool i2c_select_device(int i2c, int addr, char * name) {
	if (ioctl(i2c, I2C_SLAVE, addr) < 0) {
        fprintf(stderr, "%s not present\n", name);
        return false;
    }

    return true;
}

bool i2c_write(int i2c, char *buf, int len) {
	if (write(i2c, buf, len) != len) {
        fprintf(stderr, "Can't write to device\n");
        return false;
    }

    return true;
}

bool i2c_read(int i2c, char *buf, int len) {
    if (read(fd, buf, len) != len) {
        printf("Unable to read from slave\n");
        return false;
    }
    return true;
}