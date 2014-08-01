#ifndef __UART_H__
#define __UART_H__

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

int uartOpen();
void uartWriteByte(int uart_id, uint8_t data);
uint8_t uartReadByte(int uart_id);
int uartAvailable(int uart_fd);
void uartClose(int uart_id);
#endif