#include <stdio.h>
#include <string.h>

static int create_file(void)
{
	FILE* fp;
	if((fp = fopen("data_file", "w")) == NULL)
	{
		printf("fopen error! \n");
	}

	printf("before file offset : [%ld] \n", ftell(fp));
	fputs("Hello world\n", fp);
	fputs("Hello world!!\n", fp);
	fputs("Hello world!!!\n", fp);
	fputs("Hello world!!!!\n", fp);
	printf("after file offset : [%ld] \n", ftell(fp));

	fclose(fp);
	return 0;
}


static int read_file(void)
{
	FILE* fp;
	char buff[1024];

	if((fp = fopen("data_file", "r+")) == NULL)
	{
		printf("fopen error! \n");
	}

	printf("before file offset : [%ld] \n", ftell(fp));
	memset(buff, 0, sizeof(buff));
	fgets(buff, sizeof(buff), fp);
	printf("after file offset : [%ld] \n", ftell(fp));
	fseek(fp, 0, SEEK_END);	
	printf("after fssek file offset : [%ld] \n", ftell(fp));
	fputs("final \n", fp);
	printf("last file offset : [%ld] \n", ftell(fp));
	
	fclose(fp);
	return 0;
}


int main(int argc, char* argv[])
{
	create_file();
	read_file();
	return 0;
}
