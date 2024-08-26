#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    pid_t my_pid, parent_pid, child_pid;

    child_pid = fork();
    if(child_pid < 0){
        printf("Child not created, Fork Failed!..Exiting");
        exit(1);
    }

    if(child_pid == 0){
        my_pid = getpid();
        parent_pid = getppid();
        printf("[CHILD] My pid is: %d", my_pid);
        printf("[CHILD] My parent's pid is: %d", parent_pid);
        printf("[CHILD] I'm Exiting");
        exit(0);
    }else{
        my_pid = getpid();
        parent_pid = getppid();
        printf("[PARENT] My pid is: %d", my_pid);
        printf("[PARENT] My parents pid is: %d", parent_pid);
        printf("[PARENT] Sleeping for some time");
        sleep(10);
        printf("[PARENT] Child exiting, but its entry in process table, It is zombie process");
    }
 return 0;
}

