#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
	int fd;
	char buf[30];

	fd=open("/dev/gpio_button",O_RDWR);
	if (fd < 0) {
        printf("Device open error : %s\n","/dev/gpio_button");
        exit(1);
	}
	while(1) {
		read(fd, buf, 1);
		printf("%d\n\r",buf[0]);
		usleep(100000);
	}
	close(fd);
}
