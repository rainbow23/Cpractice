#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

int score = 0;

void end_game(int sig)
{
	printf("\n最終得点:%i\n", score);
	//exit(0);
	EXIT_SUCCESS;
}

void times_up(int sig)
{
	printf("\n時間切れです！");
	raise(SIGINT);
}

int catch_signal(int sig, void (*handler)(int))
{
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(sig, &action, NULL);
}

int main (int argc, char *argv[])
{
	catch_signal(SIGINT,   end_game);
	catch_signal(SIGALRM, times_up);
	
	srandom(time(0));
	while(1)
	{
		int a = random() % 11;
		int b = random() % 11;
		
		alarm(5);
		char txt[4];
		
		printf("%iかける%iはいくつですか？ ", a, b);
		fgets(txt,4,stdin);
		{
			int answer = atoi(txt);
			if(answer == a*b)
			{
				score++;	
			}
			else
			{
				printf("\n間違いです！得点:%i\n", score);
				break;
			}
		}
	}
	return 0;
	
}
