#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
  pid_t child_pid;

  child_pid = fork ();
  if (child_pid > 0) {
    // wait(NULL);
    sleep (10);
  }
  else {
    printf("zombieee");
    exit (0);
  }
  return 0;
}