#include "test1.h"

char string1[] = "this is sample";
char file_name[] = "file1";

int main(int argc, char** argv)
{
    int fd1;
    int err=0;
    ssize_t bytes_written;

    fd1 = open(file_name, O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH );
    if(0 > fd1) {
        perror(file_name);
        return errno;
    }
    bytes_written = write(fd1, string1, strlen(string1)+1);
    if(bytes_written < 0) {
        perror(file_name);
        printlog("writing %s failed",file_name);
        err = errno;
        goto cleanup1;
    } else {
        printlog("%lu bytes written", bytes_written);
    }

    err=0;
cleanup1:
    close(fd1);
    return err;
}
