#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
	int fd_button, fd_led;
	char buf[30];
	char wbuf[30];
	char led_state, old_button_state, present_button_state;

	fd_button=open("/dev/gpio_button",O_RDWR);
	if (fd_button < 0) {
        printf("Device open error : %s\n","/dev/gpio_button");
        exit(1);
	}
	fd_led=open("/dev/gpio_led",O_RDWR);
	if (fd_led < 0) {
		printf("Device open error : %s\n","/dev/gpio_led");
        exit(1);
	}

	led_state=0;            //led state
    present_button_state=1; //button state

	while(1) {

		read(fd_button, buf, 1); //read button
		old_button_state = present_button_state;
		present_button_state = buf[0];
		
		if ((old_button_state==1) && (present_button_state==0)) { //if button is pushed, led state change
            led_state = !led_state;
        }

		if(led_state) { //if led_state=1, led on
			wbuf[0]=1;
            write(fd_led,wbuf,1);
		} else {        //if led_state=0, led off
			wbuf[0]=0;
            write(fd_led,wbuf,1);
		}

	}
	close(fd_led);close(fd_button);
}
