#include <stdio.h>
#include <stdlib.h>


int ADS_init(int *fd, const int *button){


    wiringPiSetup();
    pinMode(SDA,OUTPUT);
    pinMode(SCL,OUTPUT);

int ADS_address=0x48;
int fd;
char bus[]="/dev/i2c-1";


fd=open(bus,O_RDWR);
	if(fd<0)
	{
		printf("Failed to open device.\n");
		return 1;
    }

int ADS_register[3]={0};
    ADS_register[0]=0x01;		//	if 0 then master read from conversion registers of slave, with 0x01 write the config registers
    ADS_register[1]=0x84;		//	if 0x84 continous conversion , 0x85 is single-shot conversion
    ADS_register[2]=0xE3;		//	0xE3 E is about data rate (860S/s)



	if(write(fd,ADS_register,3)!=3){
		perror("Failed to write to config registers\n");
		return 1;
}
    ADS_register[0]=0x00;
 // read conversion register

	if (write(fd,ADS_register, 1)!= 1) {		// to change first register
	perror("Write conversion register is failed");
	return 1;
  }

	char i=0;
	char on=0;
	char ismetles=0;
	int risingEdge=0;

	data=(int*)malloc(2*sizeof(int));
/**
*/
	while(1){
	if(!digitalRead(*button))
	{

	risingEdge++;
	delay(TIME);

	while(risingEdge%2)
{

	read(fd,data,2);
		if (read(fd,data,2) !=2)
		{
		perror("Read conversion");
		return 1;
		}
	printf("Read data the follow:%d\t YOLO \n",*data);
	if(!digitalRead(*button))
	{
	risingEdge++;
	delay(TIME);
	}
		delay(TIME/10);
}
}
	else
	{
	if(ismetles==LIMIT+1)
	    on=0;
	if(i==LIMIT)
	{
	i=0;
	on=1;
	ismetles++;
	    if(!(ismetles%2))
		on=0;
	}
	digitalWrite(led[i++],!(on));
	delay(TIME);
	}
}
    close(fd);
return 0;
}
