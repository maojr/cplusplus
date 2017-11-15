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
    int stdin_fd = 0;

    /* Your input length should less than 20 */
    char input[20];

    epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }

    ev.events = EPOLLIN;
    // ev.events = EPOLLIN | EPOLLET;
    ev.data.fd = stdin_fd;

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, stdin_fd, &ev) == -1) {
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }
        if (nfds > 0) {
            fgets(input, 20, stdin);
            printf("Your input is: %s", input);
        }
    }

  exit(EXIT_SUCCESS);
}
