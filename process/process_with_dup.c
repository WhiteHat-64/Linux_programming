#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdio.h>

//pid_t fork(void);

char *argv[] = {NULL};
char *envp[] = {NULL};

int main() {
    pid_t pid1, pid2, pid3;
    pid_t outfd;

    outfd = open("./process_output.log", O_CREAT |  \
            O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    printf("Before fork: %d\n", getpid());

    pid1 = fork();

    // child
    if(pid1 == 0) {
        write(outfd, "writing from child\n", 20);
        if(STDOUT_FILENO != dup2(outfd, STDOUT_FILENO)) {
            printf("dup failed\n");
        }
        close(outfd);
        execve("./process_print", argv, envp);
    // parent
    } else if (pid1 > 0) {
        close(outfd);
        printf("After fork %d\n",getpid());
    } else {
        printf("perror\n");
    }
    while(1);
    return 0;
}
