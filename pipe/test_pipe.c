#include <unistd.h>
#include <stdio.h>

struct fd_pair {
           long fd[2];
       };




int main ()
{
    struct fd_pair pipefd;
    char buffer[30];
    
    pipefd = pipe();

    printf("%ld %ld\n", pipefd.fd[0], pipefd.fd[1]);

    write (pipefd.fd[1], "writing into pipe from pipe[1]\n", 10);
    read (pipefd.fd[0], buffer, 20);
    printf("%s\n",buffer);

    close(pipefd.fd[0]);
    close(pipefd.fd[1]);
}
