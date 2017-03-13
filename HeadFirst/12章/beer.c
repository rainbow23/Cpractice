#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

int beers = 2000000;

void error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
}

void* drink_lots(void *a)
{
	int i;
	for(i=0; i<beers; i++)
	{
		beers = beers - 1;
	}
	return NULL;
}

int main()
{
	pthread_t threads[20];
	int t;
	printf("壁にはビールが%i本\n%i本のビール\n", beers, beers);

	for(t=0; t<20; t++)
	{
		if(pthread_create(&threads[t], NULL, drink_lots, NULL) == -1)
		error("スレッドを作成できません");		
	}
	
	void* result;
	for(t=0; t<20; t++)
	{
		if(pthread_join(threads[t], &result) == -1)
		{
			printf("スレッド%iが作成できません", t);
		}
	}
	
	printf("現在、壁にはビールが%i本あります\n", beers);
	return 0;
}
