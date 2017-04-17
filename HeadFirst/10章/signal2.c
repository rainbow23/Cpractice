#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void diediedie(int sig)
{
	puts("残酷な世界よさようなら\n");
	exit(1);
}

int catch_signal(int sig, void (*handler)(int)) 
{
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(sig, &action, NULL);
}

void deleteSyutanmoji(char *name)
{
	int len = strlen(name);

	char n = '\n';

	if(len >= 0 && *(name + (len - 1)) == '\n' )
	{
		*(name + (len -1)) = '\0';
	}
	return;
}

int main(int agrc, char * argv[])
{
	if(catch_signal(SIGINT, diediedie) == -1)
	{
		fprintf(stderr, "ハンドラを設定できません\n");
	}

	char line[255];
	printf("名前を入力してください");
	if(fgets(line, 255, stdin))
	{
		deleteSyutanmoji(line);
		printf("こんにちは %sさん\n", line);
	}
	return 0;
}
