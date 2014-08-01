#ifndef __L3G42000D_H__
#define __L3G42000D_H__
#include "i2c.h"
bool read_l3g4200d(int& fd,short& x, short& y, short& z);

#endif
