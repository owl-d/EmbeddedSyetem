#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
 
void* say_hello_1(void* data)
{
    char *str;
    str = (char*)data;
    while(1)
    {
        printf("%s\n",str);
        sleep(1);
    }
}

void* say_hello_2(void* data)
{
    char *str;
    str = (char*)data;
    while(1)
    {
        printf("%s\n",str);
        sleep(2);
    }
}
 
void main()
{
    pthread_t t1,t2;
     
    pthread_create(&t1,NULL,say_hello_1,"hello from 1");
    pthread_create(&t2,NULL,say_hello_2,"hello from 2");

    pthread_join(t1,NULL);
}
