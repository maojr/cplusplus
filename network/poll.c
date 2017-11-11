#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <poll.h>

int
main(void)
{
  int retval;
  struct pollfd pfd;

  /* Watch stdin (fd 0) to see when it has input. */
  pfd.fd = 0;
  pfd.events = POLLIN|POLLRDNORM;

  retval = poll(&pfd, 1, 5000);
  /* Don't rely on the value of tv now! */

  if (retval == -1)
    perror("an error occurred");
  else if (retval == 0)
    printf("No data within five seconds.\n");
  else
    printf("Data is available now. retval == %d\n", retval);

  exit(EXIT_SUCCESS);
}