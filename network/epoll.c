// an example of epoll level trigger
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>

#define MAX_EVENTS 10

int
main(void)
{
  struct epoll_event ev, events[MAX_EVENTS];
  int nfds;
  int epollfd;
  int listen_sock = 0;

  int readNum;

  epollfd = epoll_create1(0);
  if (epollfd == -1) {
    perror("epoll_create1");
    exit(EXIT_FAILURE);
  }

  ev.events = EPOLLIN;
  // ev.events = EPOLLIN | EPOLLET;
  ev.data.fd = listen_sock;
  if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1) {
    perror("epoll_ctl: listen_sock");
    exit(EXIT_FAILURE);
  }

  for (;;) {
    nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
    if (nfds == -1) {
      perror("epoll_wait");
      exit(EXIT_FAILURE);
    }
    if (nfds > 0) {
      printf("Data is available now. events num = %d, event fd = %d\n", nfds, events[0].data.fd);
      fscanf(stdin, "%d", &readNum);
      printf("Read num for stdin: %d\n", readNum);
    }
  }

  exit(EXIT_SUCCESS);
}
