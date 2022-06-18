#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define MAXLINE 64
#define HOST "xxx.xxx.xxx.x"
#define PORT xxxx

struct sockaddr_in serveraddr;
int client_len;
int key_fd, door_fd;		// read fd
int lcd_fd, lock_fd, led_fd;	// write fd

void init_client(){
	serveraddr.sin_family = PF_INET;
	serveraddr.sin_addr.s_addr=inet_addr(HOST);
	serveraddr.sin_port = htons(PORT);
	client_len = sizeof(serveraddr);
}
// create sockets
void c_con(int *fd){
	if((*fd=socket(AF_INET,SOCK_STREAM,0))==-1){
		perror("error: ");
	}
	if(connect(*fd, (struct sockaddr*)&serveraddr, client_len)==-1){
		perror("connect error: ");
	}
}
// read socket buffer from server in 1byte not used
unsigned char c_read(int fd){
	char buf[1];
	if(read(fd, buf, sizeof(buf))<=0){
		perror("read error: ");
		return -1;
	}
	return buf[0];
}

// read socket buffer from server in 1byte with timeout
unsigned char c_read_t(int fd, int to_ms){
	struct timeval timeout;
	fd_set readFds;
	char buf[1];
	timeout.tv_sec = 0;
	timeout.tv_usec = to_ms*1000;
	
	FD_ZERO(&readFds);
	FD_SET(fd,&readFds);
	select(fd+1, &readFds, NULL, NULL, &timeout);
	if(FD_ISSET(fd, &readFds)){
		read(fd, buf, sizeof(buf));
	}
	return buf[0];
}

// write soket buffer to server
void c_write(int fd, char* str){
	char buf[MAXLINE];
	strncpy(buf, str, sizeof(buf));
	if(write(fd, buf, sizeof(buf))<=0){
		perror("write error: ");
	}
}

// initalize hw component as file descriptor
void init_key(){
	c_con(&key_fd);
}
void init_door(){
	c_con(&door_fd);
}
void init_lcd(){
	c_con(&lcd_fd);
}
void init_lock(){
	c_con(&lock_fd);
}
void init_led(){
	c_con(&led_fd);
}

// read keypad inputs
unsigned char readKey(){
	return c_read(key_fd);
}
// read door opend/closed
unsigned char readDoor(){
	unsigned char buf=c_read(door_fd);
	do{
		buf = c_read(door_fd);
	} while(buf!='O'&&buf!='K'&&buf!='N');
	return buf+('a'-'A');
}
// wrie lcd to message
void writeLCD(char* msg){
	char buf[MAXLINE] = {0,};
	sprintf(buf, "LCD|%s|", msg);
	c_write(lcd_fd, buf);
}
void writeLED(char* msg){
	char buf[MAXLINE] = {0,};
	sprintf(buf, "led|%s|", msg);
	c_write(led_fd, buf);
}
void writeLock(char* msg){
	char buf[MAXLINE] = {0,};
	sprintf(buf, "lock|%s|", msg);
	c_write(lock_fd, buf);
}

int readStr(){
	char buf[64];
	if(read(key_fd, buf, sizeof(buf))<=0){
		perror("read error: ");
		return -1;
	}
	return atoi(buf);
}
