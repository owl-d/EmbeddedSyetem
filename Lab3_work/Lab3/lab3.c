#include <pthread.h>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int mode = 0;

void* button_state(void* data)
{
    char *str;
    str = (char*)data;

    printf("%s\n",str);

	int fd_button;
	char buf[30];
	char old_button_state, present_button_state;

	fd_button=open("/dev/gpio_button",O_RDWR);
	if (fd_button < 0) {
        printf("Device open error : %s\n","/dev/gpio_button");
        exit(1);
	}

    while(1)
    {   
		
		read(fd_button, buf, 1); //read button
		old_button_state = present_button_state;
		present_button_state = buf[0];

		if ((old_button_state==1) && (present_button_state==0)) { //if button is pushed, led state change
            
			if (mode == 0){
				mode = 1;
				printf("button mode : %d\n", mode);
			}
			else if (mode == 1){
				mode = 2;
				printf("buton mode : %d\n", mode);
			}
			else if (mode == 2){
				mode = 0;
				printf("button mode : %d\n", mode);
			}
        }
    }
	close(fd_button);
}

void* led_state(void* data)
{
    char *str;
    str = (char*)data;

    printf("%s\n",str);

	int fd_led;
	char buf[30];
	char wbuf[30];
	char led_state;

	fd_led=open("/dev/gpio_led",O_RDWR);
	if (fd_led < 0) {
		printf("Device open error : %s\n","/dev/gpio_led");
		exit(1);
	}

    while(1)
    {

        if (mode == 0){
            printf("led on\n");
			wbuf[0]=1;
			write(fd_led,wbuf,1);
        }

        else if (mode == 1){
            printf("led blink slow\n");
			if(wbuf[0]) { //if led_state=1, led on
				wbuf[0]=0;
				write(fd_led,wbuf,1);
			} else {        //if led_state=0, led off
				wbuf[0]=1;
				write(fd_led,wbuf,1);
			}
			sleep(2);
        }

        else if (mode == 2){
            printf("led blink fast\n");
			if(wbuf[0]) { //if led_state=1, led on
				wbuf[0]=0;
				write(fd_led,wbuf,1);
			} else {        //if led_state=0, led off
				wbuf[0]=1;
				write(fd_led,wbuf,1);
			}
			sleep(1);
        }
    }
	close(fd_led);
}
 
void main()
{
    pthread_t t_button,t_led;
     
    pthread_create(&t_button,NULL,button_state,"button thread on!");
    pthread_create(&t_led,NULL,led_state,"led thread on!");

    //wait for thread finishing
    pthread_join(t_button,NULL);
}
