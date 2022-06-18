#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/ioctl.h>

int mode=0;
char state[30];

struct timespec  begin, end;
long total_time;
long msec, sec;

void* button_state(void* data) {

    char *str;
    str = (char*)data;

    printf("%s\n",str);

    int fd_button;
    char buf[30];
    char left_old_button_state, left_present_button_state;
    char right_old_button_state, right_present_button_state;

    fd_button=open("/dev/gpio_button_right",O_RDWR);
    if (fd_button < 0) {
        printf("Device open error : %s\n","/dev/gpio_button_right");
        exit(1);
    }

    while(1) {
        read(fd_button, buf, 2); //read button
        left_old_button_state = left_present_button_state;
        right_old_button_state = right_present_button_state;
        left_present_button_state = buf[0];
        right_present_button_state = buf[1];

        if ((left_old_button_state==1) && (left_present_button_state==0)) { //if left button is pushed, led state change

            if ((mode == 0) || (mode == 1)) {
                mode=2;
                printf("Left button Pushed : Running         \n");
                sprintf(state, "Running \n");

                clock_gettime(CLOCK_MONOTONIC, &begin);
            }

            else if (mode == 2) {
                mode=1;
                printf("Left button Pushed : Stopped         \n");
                sprintf(state, "Stopped \n");
            }
            
        }
        
        if ((right_old_button_state==1) && (right_present_button_state==0)) { //if right button is pushed, led state change
            
            sprintf(state, "Cleared         \n");
            
            if ((mode == 0) || (mode == 1)) {
                mode=0;
                printf("Right button Pushed : Stop-Cleared\n");

                clock_gettime(CLOCK_MONOTONIC, &begin);
            }

            else if (mode == 2) {
                mode=2;
                printf("Right button Pushed : Run-Cleared\n");
                
                clock_gettime(CLOCK_MONOTONIC, &begin);
                total_time=0;
            }
        
        }
    }

    close(fd_button);
}

void* lcd_state(void* data) {

    char *str;
    str = (char*)data;

    printf("%s\n", str);
    
    int fd_lcd;
	char wbuf[30];

	fd_lcd=open("/dev/lcd1602",O_RDWR);
	if (fd_lcd < 0) {
        printf("Device open error : %s\n","/dev/lcd1602");
        exit(1);
	}
	
	ioctl(fd_lcd, 1, 0x01);

    while(1){

        if (mode == 0) { //Cleared
        
        	sec=0;
            msec=0;
            total_time=0;
            
            clock_gettime(CLOCK_MONOTONIC, &begin);
            usleep(1);
        }

        else if (mode == 1) { //Stopped
        
            clock_gettime(CLOCK_MONOTONIC, &begin);
            usleep(1);
        }

        else if (mode == 2) { //Running
            clock_gettime(CLOCK_MONOTONIC, &end);
            total_time += 1000*(end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec)/1000000;
            sec = total_time / 1000;
            msec = total_time % 1000;
            usleep(1);

            begin = end;
        }
        
        printf("Time : %02d min : %02d sec : %02d \n", sec/60, sec%60 ,msec/10);
        
        sprintf(wbuf, " %02d : %02d : %02d \n", sec/60, sec%60 ,msec/10);
	    write(fd_lcd, wbuf, strlen(wbuf));
	    write(fd_lcd, state, strlen(state));
	    
        sleep(1);
    }
    
    close(fd_lcd);
}

void main(){ printf("Press the button to start the stopwatch:\n\r");
   
    pthread_t t_button, t_lcd;
   
    pthread_create(&t_button,NULL,button_state,"button thread on!");
    pthread_create(&t_lcd,NULL,lcd_state,"lcd thread on!");
    
    //wait for thread finishing
    pthread_join(t_lcd,NULL);
}
