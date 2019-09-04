#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

void error(char *msg)
{
	fprintf(stderr, "%s: %s", msg, strerror(errno));
	exit(1);
}

void* does_not( void *a)
{
	int i = 0;
	for(i = 0; i<5; i++)
	{
//		sleep(1);
		puts("Does not");
	}
	return NULL;
}

void* does_too( void *a)
{
	int i = 0;
	for(i = 0; i<5; i++)
	{
		//sleep(1);
		puts("Does too");
	}
	return NULL;
}

int beers = 2000000;
pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;
void* drint_lots(void *a)
{
	pthread_mutex_lock(&beers_lock);
	for(int i=0; i<100000; i++)
	{
		//pthread_mutex_lock(&beers_lock);
		beers = beers - 1;
		//pthread_mutex_unlock(&beers_lock);
	}
	pthread_mutex_unlock(&beers_lock);

	printf("beers = %d\n", beers);

	return NULL;
}

int main(int argc, char* argv[])
{
	pthread_t t0; 
	pthread_t t1; 
	pthread_t t3[20]; 
	
	/*
	if(pthread_create(&t0, NULL, does_not, NULL) == -1)
	{
		error("スレッドを作成できません\n");
	}

	if(pthread_create(&t1, NULL, does_too, NULL) == -1)
	{
		error("スレッドを作成できません\n");
	}
	*/
	char buff[100];
	buff[99] = '\0';
	for(int i=0; i<20; i++)
	{
		if(pthread_create(&t3[i], NULL, drint_lots, NULL) == -1)
		{
			sprintf(buff, "スレッド%dをジョインできません\n", i);
			error(buff);
		}
	}

	void* result;
	/*
	if(pthread_join(t0, &result) == -1)
	{
		error("スレッドt0をジョインできません");
	}
	if(pthread_join(t1, &result) == -1)
	{
		error("スレッドt1をジョインできません");
	}
	*/

	for(int i=0; i<20; i++)
	{
		if(pthread_join(t3[i], &result) == -1)
		{
			sprintf(buff, "スレッド%dをジョインできません\n", i);
			error(buff);
		}
	}

	printf("今のビール数: %i\n", beers);

	return 0;
}

