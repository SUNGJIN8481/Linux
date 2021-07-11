#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person {
	char name[20];
	int age;
};

struct person student[2]={{"Kim", 17}, {"Lee", 19}};

static int write_to_file(void)
{
	FILE* fp;
	if((fp = fopen("datafile", "w")) == NULL)
	{
		printf("file open error! \n");
		return -1;
	}

	if(fwrite(&student[0], sizeof(struct person), 1, fp) != 1)
	{
		fclose(fp);
		printf("fwrite fail!(1) \n");
	}
	if(fwrite(&student[1], sizeof(struct person), 1, fp) != 1)
	{
		fclose(fp);
		printf("fwrite fail!(2) \n");
	}

	fclose(fp);
}

static int read_from_file(void)
{
	FILE* fp;
	int i;
	struct person persons[2];


	if((fp = fopen("datafile", "r")) == NULL)
	{
		printf("file open error! \n");
		return -1;
	}

	for(i=0 ; i<2 ; i++)
	{
		fread(&persons[i], sizeof(struct person), 1, fp);
		printf("name : %s, age : %d \n", persons[i].name, persons[i].age);
	}

	fclose(fp);
}


int main (int argc, char* argv[])
{
	write_to_file();
	read_from_file();
	return 0;
}
