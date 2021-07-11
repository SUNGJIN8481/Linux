#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int append_file(void)
{
	int fd;
	fd = open("datafile", O_WRONLY | O_APPEND);
	if(fd == -1)
	{
		printf("open error ! \n");
		return -1;
	}

	dprintf(fd, "hello again!!! \n");
	close(fd);
	return 0;
}
static int trunc_file(void)
{
	int fd;
	fd = open("datafile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd == -1)
	{
		printf("open error ! \n");
		return -1;
	}

	dprintf(fd, "byebye world!! \n");
	close(fd);
	return 0;
}

static int write_file(void)
{
	int fd;
	fd = open("datafile", O_WRONLY | O_CREAT, 0644);
	if(fd == -1)
	{
		printf("open error ! \n");
		return -1;
	}

	dprintf(fd, "Hello world open test!! \n");
	close(fd);
	return 0;
}

int main(int argc, char* argv[])
{
	if(write_file() != 0)
		printf("wrtie error!! \n");
	if(trunc_file() != 0)
		printf("trunc error!! \n");
	if(append_file() != 0)
		printf("append error!! \n");

	return 0;
}

