#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdio.h>

//pid_t fork(void);

unsigned int var1 = 10;

char *argv[] = {NULL};
char *envp[] = {NULL};

int main() {
    pid_t pid1, pid2, pid3;
    printf("Before fork: %d\n", getpid());
    pid1 = fork();
    printf("%d: var1: %d\n", getpid(), var1);

    if(pid1 == 0) {
        var1 = 100;
        printf("%d: var1: %d\n", getpid(), var1);
        execve("./process_print", argv, envp);
    } else if (pid1 > 0) {
        printf("After fork %d\n",getpid());
        printf("%d: var1: %d\n", getpid(), var1);
    } else {
        printf("perror\n");
    }
    while(1);
    return 0;
}
