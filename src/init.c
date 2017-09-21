#include <stdio.h>
#include <stdlib.h>


int ADS_init(int *fd, const int *button){


    wiringPiSetup();
    pinMode(SDA,OUTPUT);
    pinMode(SCL,OUTPUT);

int slave_address=0x07;
int fd;
char bus[]="/dev/i2c-1";
int errnum;
openlog(NULL,LOG_PID,LOG_LOCAL1);
fd=open(bus,O_RDWR);
	if(fd<0)
	{
		syslog(LOG_INFO,"Failed to open device.\n");
		return -1;
    }

    if((errnum=ioctl(fd,I2C_SLAVE,slave_address))<0)
    {
        syslog(LOG_INFO,"%s\n",strerror(errnum));
        return -1;
    }

int readRegister=0x01;
int writeRegister=0x00;



	if(write(fd,ADS_register,3)!=3){
		perror("Failed to write to config registers\n");
		return 1;
}

	if (write(fd,ADS_register, 1)!= 1) {		// to change first register
	perror("Write conversion register is failed");
	return 1;
  }
return 0;
}
