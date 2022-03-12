#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#define MSG_Q_NAME  "/MSG_Q"
#define NO_MAX_MSG  10
#define STOP_CMD    "exit"

int main(int agrc, char *argv[]) {
  mqd_t msg_q;
  struct mq_attr attr;
  int mq_len;

  attr.mq_flags = 0;
  attr.mq_maxmsg = NO_MAX_MSG;
  attr.mq_curmsgs = 0;

  msg_q = mq_open (MSG_Q_NAME,O_WRONLY,S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, &attr);
  if ( -1 == msg_q) {
    perror("mq_open");
    _exit(-1);
  }

  printf("Send> Hellow World\n");
  mq_send(msg_q, "Hello World", 12, 0);
  sleep(1);

  printf("Send> Hellow World\n");
  mq_send(msg_q, "Hello World", 12, 0);
  sleep(1);

  printf("Send> Hellow World\n");
  mq_send(msg_q, "Hello World", 12, 0);
  sleep(1);

  printf("Send> Hellow World\n");
  mq_send(msg_q, "Hello World", 12, 0);
  sleep(1);

  printf("Send> Hellow World\n");
  mq_send(msg_q, "Hello World", 12, 0);
  sleep(1);

  printf("Send> exit\n");
  mq_send(msg_q, "exit", 12, 0);

  printf("mq_writer: Exit\n");
  mq_close(msg_q);
  mq_unlink(MSG_Q_NAME);
  return 0;
}

