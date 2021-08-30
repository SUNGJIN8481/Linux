#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *child_thread_main(void *argv)
{
	printf("child pthread id %lu \n", pthread_self());
	return NULL;
}

int main(int argc, char **argv)
{
	int ret;
	pthread_t child_threads[2];

	printf("main thread id %lu \n", pthread_self());
	ret = pthread_create(&child_threads[0], NULL, child_thread_main, NULL);
	if(ret){
		printf("pthread create() fail(%d)\n", ret);
		return -1;
	}
	ret = pthread_create(&child_threads[1], NULL, child_thread_main, NULL);
	if(ret){
		printf("pthread create() fail(%d)\n", ret);
		return -1;
	}
	if(pthread_join(child_threads[0], NULL)){
		printf("pthread_join(%lu) fail \n", child_threads[0]);
	}
	if(pthread_join(child_threads[1], NULL)){
		printf("pthread_join(%lu) fail \n", child_threads[1]);
	}
	return 0;
}
