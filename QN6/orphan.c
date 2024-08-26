#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t my_pid, parent_pid, child_pid;

    child_pid = fork();
    if (child_pid < 0)
    {
        printf("Child not created, Fork Failed!..Exiting");
        exit(1);
    }

    if (child_pid == 0)
    {
        my_pid = getpid();
        parent_pid = getppid();
        printf("[CHILD] My pid is: %d\n", my_pid);
        printf("[CHILD] My parent's pid is: %d\n", parent_pid);
        printf("[CHILD] I'm sleeping for some time\n");
        sleep(10);
        printf("[CHILD] Parent exited, i'm orphan now which is taken by init process\n");
    }
    else
    {
        my_pid = getpid();
        parent_pid = getppid();
        printf("[PARENT] My pid is: %d\n", my_pid);
        printf("[PARENT] My parents pid is: %d\n", parent_pid);
        printf("[PARENT] Exiting\n");
        exit(0);
    }
    return 0;
}
