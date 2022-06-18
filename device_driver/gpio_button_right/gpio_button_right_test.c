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

	fd=open("/dev/gpio_button_right",O_RDWR);
	if (fd < 0) {
        printf("Device open error : %s\n","/dev/gpio_button_right");
        exit(1);
	}
	while(1) {
		read(fd, buf, 2);
		printf("%d %d\n\r",buf[0], buf[1]);
		usleep(100000);
	}
	close(fd);
}
