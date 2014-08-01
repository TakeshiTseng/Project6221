int uart_open() {
    const char* device = "/dev/ttyACM0";
    int buad = 9600;

    struct termios options ;
    speed_t myBaud ;
    int     status, fd ;

    switch (baud)
    {
        case     50:	myBaud =     B50 ; break ;
        case     75:	myBaud =     B75 ; break ;
        case    110:	myBaud =    B110 ; break ;
        case    134:	myBaud =    B134 ; break ;
        case    150:	myBaud =    B150 ; break ;
        case    200:	myBaud =    B200 ; break ;
        case    300:	myBaud =    B300 ; break ;
        case    600:	myBaud =    B600 ; break ;
        case   1200:	myBaud =   B1200 ; break ;
        case   1800:	myBaud =   B1800 ; break ;
        case   2400:	myBaud =   B2400 ; break ;
        case   4800:	myBaud =   B4800 ; break ;
        case   9600:	myBaud =   B9600 ; break ;
        case  19200:	myBaud =  B19200 ; break ;
        case  38400:	myBaud =  B38400 ; break ;
        case  57600:	myBaud =  B57600 ; break ;
        case 115200:	myBaud = B115200 ; break ;
        case 230400:	myBaud = B230400 ; break ;

        default:    return -2 ;
    }

    if ((fd = open (device, O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK)) == -1) {
        return -1 ;        
    }

    fcntl (fd, F_SETFL, O_RDWR) ;

    // Get and modify current options:

    tcgetattr (fd, &options) ;

    cfmakeraw   (&options) ;
    cfsetispeed (&options, myBaud) ;
    cfsetospeed (&options, myBaud) ;

    options.c_cflag |= (CLOCAL | CREAD) ;
    options.c_cflag &= ~PARENB ;
    options.c_cflag &= ~CSTOPB ;
    options.c_cflag &= ~CSIZE ;
    options.c_cflag |= CS8 ;
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG) ;
    options.c_oflag &= ~OPOST ;

    options.c_cc [VMIN]  =   0 ;
    options.c_cc [VTIME] = 100 ;	// Ten seconds (100 deciseconds)

    tcsetattr (fd, TCSANOW | TCSAFLUSH, &options) ;

    ioctl (fd, TIOCMGET, &status);

    status |= TIOCM_DTR ;
    status |= TIOCM_RTS ;

    ioctl (fd, TIOCMSET, &status);

    usleep (10000) ;	// 10mS

    return fd ;
}

void uart_write_byte(const int uartId, uint8_t data) {
    write (fd, &data, 1) ;
    tcflush (uartId, TCIOFLUSH) ;
}

uint8_t uart_read_byte(const int uartId) {
    uint8_t data ;

    if (read (fd, &data, 1) != 1) {
        return -1 ;        
    }

    return ((int)data) & 0xFF ;
}

int uart_available(const int uartId) {
    int res ;

    if (ioctl (fd, FIONREAD, &result) == -1) {
        return -1 ;        
    }

    return res ;
}

void uart_close(int uartId) {
    close(uartId);
}
