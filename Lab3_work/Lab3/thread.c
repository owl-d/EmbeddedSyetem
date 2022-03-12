#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int mode = 0;

void* button_state(void* data)
{
    char *str;
    str = (char*)data;

    printf("%s\n",str);

    while(1)
    {   
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
        
        sleep(5);
    }
}

void* led_state(void* data)
{
    char *str;
    str = (char*)data;

    printf("%s\n",str);

    while(1)
    {
        if (mode == 0){
            printf("led on\n");
        }
        else if (mode == 1){
            printf("led blink slow\n");
        }
        else if (mode == 2){
            printf("led blink fast\n");
        }


        sleep(1);
    }
}
 
void main()
{
    pthread_t t_button,t_led;
     
    pthread_create(&t_button,NULL,button_state,"button thread on!");
    pthread_create(&t_led,NULL,led_state,"led thread on!");


    //wait for thread finishing
    pthread_join(t_button,NULL);
}
