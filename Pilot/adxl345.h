#ifndef __ADXL345_H__
#define __ADXL345_H__
#include "i2c.h"

bool read_adxl345(int& fd,short & , short &, short &);

#endif