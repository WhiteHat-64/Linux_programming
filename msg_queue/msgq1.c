#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

int main()
{
	unsigned char message1[] = ""
	mqd_t mqd1;
	struct mq_attr attr1;
	
	attr1.mq_flags = 0644;
	attr1.mq_maxmsg = 100;
	attr1.mq_msgsize = 1000;
	attr1.mq_curmsgs = 0;

	mqd1 = mq_open("queue", O_CREAT | O_RDWR | O_EXCL, 0644, &attr);
	perror("mq_open : ");

	mq_send(mqd1, , size_t msg_len, unsigned int msg_prio);

}
