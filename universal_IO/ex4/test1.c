#include "test1.h"

char string1[] = "this is sample added";
char string2[] = "second line added";
char file_name[] = "file1";

int main(int argc, char** argv)
{
    int fd1;
    int fd2;
    int err=0;
    ssize_t bytes_written;
    ssize_t bytes_read;
    char data_buff[101] = {0};
    off_t offset = 0;

    fd1 = open(file_name, O_RDWR  | O_CREAT , S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH );
    if(0 > fd1) {
        perror("open");
        return errno;
    }

    fd2 = dup(fd1);
    if(0 > fd2) {
        perror("dup");
        return errno;
    }
    printf("fd1 %d, fd2 %d\n", fd1, fd2);
    bytes_written = write(fd1, string1, strlen(string1));
    if(bytes_written < 0) {
        perror("write");
        printlog("writing %s failed, changing the mode to O_RDWR",file_name);
    } else {
        printlog("%lu bytes written", bytes_written);
    }

    bytes_written = write(fd2, string2, strlen(string2)+1);
    if(bytes_written < 0) {
        perror("write");
        printlog("writing %s failed, changing the mode to O_RDWR",file_name);
    } else {
        printlog("%lu bytes written", bytes_written);
    }

    offset = lseek(fd1, 0, SEEK_SET);
    if(offset < 0) {
        perror(file_name);
        printlog("lseek %s failed",file_name);
        err = errno;
        goto cleanup1;
    } else {
        printlog("file position moved to byte: %ld", offset);
    }

    bytes_read = read(fd1, data_buff, 100);
    if(bytes_read < 0) {
        perror(file_name);
        printlog("reading %s failed",file_name);
        err = errno;
        goto cleanup1;
    } else {
        printlog("%lu bytes read", bytes_read);
        data_buff[bytes_read] = '\0';
        printlog("%s",data_buff);
    }

    err=0;
cleanup1:
    close(fd1);
    return err;
}
