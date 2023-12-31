// You can also use loop to create as many child processes as you need
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <unistd.h>
 
//main function begins
int main(void) {
  for(int i = 1; i <= 4; i++) {
    pid_t pid = fork();
 
    if(pid == 0) {
      printf("Child process => PPID=%d, PID=%d\n", getppid(), getpid());
      exit(0);
    }
    else  {
      printf("Parent process => PID=%d\n", getpid());
      printf("Waiting for child processes to finish...\n");
      wait(NULL);
      printf("the child process is finished.\n");
    }
  }
 
  return EXIT_SUCCESS;
}
// fork() is used 4 times in a for loop

