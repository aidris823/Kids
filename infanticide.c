#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int process(){
  int child = fork();
  int child_two = fork();
  printf("Initial message: Why was Pavlov's hair so soft?  Classical conditioning.");
  //Child Instructions
  if (child_one){
    printf("Child PID: %d",getpid());
    sleep(rand() % 15 + 5 );//range: 5 - 20
    printf("Hello, I am child one.  I am now AWAKE.");
  }
  if (child_two){
    printf("Child PID: %d",getpid());
    sleep(rand() % 15 + 5);
    printf("Greetings, child two is I.  I am 2woke4u.");
  }
  //Parent Instructions
  int x;
  //Find child's PID
  int child_pid = wait(&x);
  printf("Child of PID %d slept for %d seconds.",child_pid,WEXITSTATUS(x));
  return 0;
}
int main(){
  process();
  return 0;
}
