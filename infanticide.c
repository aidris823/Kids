#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int process(){
  int child_one = fork();
  int child_two = fork();
  printf("Initial message: Hey, VSauce!  Michael here.  \n");
  //Child Instructions
  if (child_one){
    printf("Child PID: %d\n",getpid());
    sleep(rand() % 16 + 5 );//range: 5 - 20
    printf("Hello, I aam child one.  I am now AWAKE.\n");
  }
  if(child_two){
    printf("Child PID: %d\n",getpid());
    sleep(rand() % 16 + 5);
    printf("Greetings, child two is I.  I am 2woke4u.\n");
  }
  //Parent Instructions
  int x;
  //Find child's PID
  int child_pid = wait(&x);
  printf("Child of PID %d slept for %d seconds.\n",child_pid,WEXITSTATUS(x));
  printf("And, as always, thanks for watching.\n");
  return 0;
}
int main(){
  process();
  return 0;
}
