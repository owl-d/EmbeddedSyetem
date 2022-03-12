#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#define MSG_Q_NAME "/MSG_Q"
#define NO_MAX_MSG 10
#define MAX_MSG 1024
#define STOP_CMD "exit"

int main(int agrc, char *argv[]) {
  mqd_t msg_q;
  struct mq_attr attr;
  char message[MAX_MSG];
  int mq_len; 

  attr.mq_flags = 0;
  attr.mq_maxmsg = NO_MAX_MSG;
  attr.mq_msgsize = MAX_MSG;
  attr.mq_curmsgs = 0;

  msg_q = mq_open (MSG_Q_NAME,O_CREAT|O_RDONLY,S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, &attr);
  if ( -1 == msg_q) {
    perror("mq_open");
  _exit(-1);
  }

  do {
    bzero(message, MAX_MSG);
    mq_len = mq_receive(msg_q, message, MAX_MSG, NULL);
    if ( -1 == mq_len) {
    perror("mq_receive");
    mq_close(msg_q);
    mq_unlink(MSG_Q_NAME);
    _exit(-1);
 }

  printf("Received> %s\n", message);
  } while (!(0 == strcmp(message,STOP_CMD)));

  printf("mq_reader: Exit\n");
  mq_close(msg_q);
  mq_unlink(MSG_Q_NAME);
  return 0;
}
