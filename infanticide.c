#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int process(){
  int child_one = fork();
  int child_two = fork();
  //Child Instructions
  if (child_one){
    printf("%d",getpid());
    sleep(5,20);
    printf("Hello, I am child one.  I am now ded.");
  }
  if (child_two){
    printf("%d",getpid());
    sleep(5,20);
    printf("Greetings, child two is I.  Soon, child two WAS I.");
  }
  //Parent Instructions
}
int main(){
  return 0;
}
