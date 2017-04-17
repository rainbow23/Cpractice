#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void error(char *msg)
{
	fprintf(stderr, "%s:%s\n", msg, strerror(errno));
	exit(1);
}

int main (int argc, char *argv[])
{
	char *phrase = argv[1];
	char *vars[]  = {"RSS_FEED=http://news.kddi.com/kddi/corporate/newsrelease/rss/kddi_news_release.xml", NULL};

	printf("1 check\n");

	FILE *f = fopen("stories.txt", "w");
	if(!f)
	{
		error("stories.txtを開けません");
	}

	pid_t pid = fork();
	if(pid == -1)
	{
		error("プロセスをフォークできません");
	}
	
	if(!pid)
	{
		if(dup2(fileno(f), 1) == -1)
		{
			error("標準出力をリダイレクトできません");
		}
 
		printf("2 pid %i\n", pid);

		if(execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1)
		{
			error("スクリプトを実行できません");
		}
	}

	int pid_status;
	if(waitpid(pid, &pid_status, 0) == -1)
	{
		error("子プロセスの待機エラー");
	}
	
	printf("pid_status %i\n", pid_status);
	
	return 0;
}
