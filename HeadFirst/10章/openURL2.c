#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void open_url(char* url)
{
	char launch[255];
	sprintf(launch, "open '%s'", url);
	system(launch);
}

int main (int argc, char* argv[])
{
	char *phase  = argv[1];
	char *vars[] = {"RSS_FEED=http://news.kddi.com/kddi/corporate/newsrelease/rss/kddi_news_release.xml", NULL};

	//pipe
	int fd[2];
	if(pipe(fd) == -1)
	{
		printf("パイプ作成できません\n");
	}

	//create process
	pid_t pid = fork();	
    if(pid == -1)
    {
        printf("プロセスをフォークできません\n");
    }
    
	//child process
	if(!pid)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		if(execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", "-u", phase, NULL, vars) == -1)
		{
			printf("スクリプトを実行できません\n");
		}
	}	

	//parent process

	close(fd[1]);
	dup2(fd[0], 0);
	
	char line[255];
	while(fgets(line, 255, stdin))
	{
		if(line[0] == '\t')
		open_url(line +1);
	}	

	return 0;
}
