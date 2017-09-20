#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED
#include <inttypes.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <syslog.h>
#include <errno.h>
#include <wiringPi.h>
#define LIMIT 3
#define TIME 170
#define SDA 8
#define SCL 9
int ADS_init(int *fd, const int *button);

#endif // INIT_H_INCLUDED
