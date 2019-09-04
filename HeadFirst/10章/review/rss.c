#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void error(char * msg)
{
	fprintf(stderr, "%s:%s\n", msg, strerror(errno));
	exit(1);
}

void open_url(char *url)
{
	char launch[255];
	sprintf(launch, "open '%s'", url);
	system(launch);
}

int main(int argc, char *argv[])
{
	char *phrase = argv[1];
	char *vars[] ={"RSS_FEED=http://news.kddi.com/kddi/corporate/newsrelease/rss/kddi_news_release.xml", NULL};
	int fd[2]; //descriptor


	if(pipe(fd) == -1)
	{
		error("パイプを作成できません");
	}

	pid_t pid = fork();
	if(!pid)// child process
	{
		close(fd[0]);
		dup2(fd[1], 1);
		if(execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", "-u", phrase, NULL, vars) == -1)
		{
			error("スクリプトを実行できません");
		}
	}

	close(fd[1]);
	dup2(fd[0], 0);

	char line[255];
	//while(fgets(line, 255, fd[0]))
	while(fgets(line, 255, stdin))
	{
		printf("line: %s\n", line);
		if(line[0] == '\t')
//		if(line[0] == '/t')
		{
			open_url(line + 1);
		}
	}
	return 0;
}
