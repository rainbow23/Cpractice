#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	char *my_env[] = {"FOOD=coffee", NULL};
	if(execle("./coffee", "./coffee", "donuts", NULL, my_env) == -1)
	{
		fprintf(stderr, "プロセス0を実行できません:%s\n", strerror(errno));
	}
	return 1;
}

