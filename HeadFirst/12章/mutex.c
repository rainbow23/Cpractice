#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void* do_stuff(void* param)
{
	long thread_no = (long)param;
	printf("スレッド番号%ld\n", thread_no);
	return (void*)(thread_no + 1);
}

pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;
int beers = 1000000;

void* drink_lots(void *a)
{
	int i;
	pthread_mutex_lock(&beers_lock);
	for(i=0; i<100000; i++)
	{
		beers = beers - 1;
	}
	pthread_mutex_unlock(&beers_lock);

	printf("beers = %i\n", beers);	
	return NULL;
}

void* drink_lots2(void *a)
{
	int i;
	for(i=0; i<100000; i++)
	{
		pthread_mutex_lock(&beers_lock);
		beers = beers - 1;
		pthread_mutex_unlock(&beers_lock);
	}

	printf("beers = %i\n", beers);
	return NULL;
}

int main()
{
	pthread_t threads[20];
	long t;

	for(t=0; t<3; t++)
	{
		//pthread_create(&threads[t], NULL, do_stuff, (void*)t);		
	}
	
	pthread_create(&threads[0], NULL, do_stuff, (void*)0);
	pthread_create(&threads[1], NULL, do_stuff, (void*)1);
	pthread_create(&threads[2], NULL, do_stuff, (void*)2);	
	
	void *result;
	for(t=0; t<3; t++)
	{
		pthread_join(threads[t], &result);
		printf("スレッド%ldは%ldを返しました\n", t, (long)result); 
	}

	int i;

	for(i=0; i<20; i++)
	{
		//pthread_create(&threads[i], NULL, drink_lots2, NULL);
	}

	for(i=0; i<20; i++)
	{
		//pthread_join(threads[i], &result);
	}
	printf("現在、壁にはビールが%i本あります\n", beers); 
}

