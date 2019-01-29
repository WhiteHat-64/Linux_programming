#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int retval;
	int fd;
	char buffer[]="This is the srting sent through FIFO\n";
	ssize_t ret_write;
	fd = open("my_fifo",O_WRONLY);
	ret_write = write(fd,buffer,strlen(buffer));
	close(fd);
}
