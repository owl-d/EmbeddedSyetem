#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <signal.h>

static int dev_pid;
static int fd;
int mode=0;

void usrsignal(int sig)
{
    printf("\nGPIO button signal\n");
    mode=1;
    
}
void usrsignal2(int sig)
{
    close(fd);
    printf("device closed\n\r");
    exit(1);
}

int main(){

    struct timespec  begin, end;
    long time, total_time;
    long msec, sec;
    int fd, fd_lcd;
    char buf[40];
    char wbuf[30];
    
    (void)signal(SIGUSR1, usrsignal);
    (void)signal(SIGINT, usrsignal2);
    fd = open("/dev/gpio_signal", O_RDWR);
    if(fd < 0) {
	printf( "Device Open ERROR!\n");
	exit(1);
    }
    printf("Press the button to start the stopwatch:\n\r");
    
    fd_lcd=open("/dev/lcd1602",O_RDWR);
    if (fd_lcd < 0) {
        printf("Device open error : %s\n","/dev/lcd1602");
        exit(1);
    }
    
    dev_pid=getpid();
    printf("dev_pid=%d\n", dev_pid);
    buf[0] = 0xff & dev_pid;
    buf[1] = 0xff & (dev_pid >> 8);
    write(fd,buf,sizeof(dev_pid));

    while(1){ 
    	while(1){
    	    if (mode!=0) {mode=0;break;}
    	}
    	clock_gettime(CLOCK_MONOTONIC, &begin);
    	while(1){
    	    clock_gettime(CLOCK_MONOTONIC, &end);
    	    time = total_time + 1000*(end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec)/1000000; 		
    	    sec = time / 1000;
    	    msec = time % 1000;
    	    if (mode!=0) {mode=0;break;}
    	    
    	    ioctl(fd_lcd, 1, 0x01);
            sprintf(wbuf, " %02d : %02d : %02d \n", sec/60, sec%60 ,msec/10);
	    	write(fd_lcd, wbuf, strlen(wbuf)); //line1
    	    
    	    usleep(1);
    	}
    	total_time = time;
    }
    
    close(fd);
    close(fd_lcd);
    return 0;
}