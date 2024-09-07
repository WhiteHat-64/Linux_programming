#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

//pid_t fork(void);

int main() {
    pid_t pid1, pid2, pid3;
    printf("Before fork: %d\n", getpid());
    pid1 = fork();
    printf("After fork %d\n",getpid());
    while(1);
    return 0;
}
