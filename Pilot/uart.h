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

int uart_open();
void uart_write_byte(int uart_id, uint8_t data);
uint8_t uart_read_byte(int uart_id);
int uart_available(int uart_fd);
void uart_close(int uart_id);
#endif