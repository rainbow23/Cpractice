#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void diediedie(int sig)
{
	puts("残酷な世界よさようなら...\n");
	exit(1);
}

int catch_signal(int sig, void(*handler)(int))
{
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(sig, &action, NULL);
}


int main (int argc, char * argv[])
{
	if(catch_signal(SIGINT, diediedie)== -1)
	{	
		fprintf(stderr, "ハンドルを設定できません");
	}
	
	char name[30];
	printf("名前を入力してください");
	fgets(name, 30, stdin);
	printf("こんにちは%sさん\n", name);
	return 0;
}
