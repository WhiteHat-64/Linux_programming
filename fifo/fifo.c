#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int ret_val;
	int fd;
	char buffer[100];
	ssize_t ret_read;
	ret_val = mknod("my_fifo",0644 | S_IFIFO,0);
	fd = open("my_fifo",O_RDONLY);
	ret_read = read(fd,buffer,99);
	printf("%s \n",buffer);
	close(fd);
}
