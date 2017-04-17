#include <string.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 

void error(char * msg)
{
	fprintf(stderr, "%s %s\n", msg, strerror(errno));
	exit(1);
}

void open_url(char *url)
{
	char launch[255];
	sprintf(launch, "open '%s'", url);
	system(launch);
}

int main(int argc, char * argv[])
{
	char *phrase = argv[1];
	char *vars[] = {"RSS_FEED=http://news.kddi.com/kddi/corporate/newsrelease/rss/kddi_news_release.xml", NULL};
	int fd[2];

	if(pipe(fd) == -1)
	{	
		error("パイプ作成できませんでした");
	}

	printf("fd[0] %i\n", fd[0]);
	printf("fd[1] %i\n", fd[1]);

	pid_t pid = fork();
	if(pid == -1)
	{	
		error("プロセスをフォークできません");
	}
	else if (!pid)
	{	
		close(fd[0]);
		dup2(fd[1],1);
		if(execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", "-u", phrase, NULL, vars) == -1)
		{
			error("スクリプトを実行できません");
		}
	}
	
	close(fd[1]);
	dup2(fd[0],0);

	char line[255];
	while(fgets(line, 255, stdin))
	{	
		if(line[0] == '\t')
		{		
			open_url(line + 1);
		}
	}
}
