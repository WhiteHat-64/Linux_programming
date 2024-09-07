#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

char *argv[] = {NULL};
char *envp[] = {NULL};

int main()
{
    printf("Before exec\n");
    execve("./process_print", argv, envp);
    printf("After exec\n");
}
