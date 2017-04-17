#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
	if(execl("/sbin/ifconfig", "/sbin/ifconfig", NULL)== -1)
	{
		if(execlp("ipconfig", "ipconfig", NULL) == -1)
		{
			fprintf(stderr, "ipconfigを実行できません；%s", strerror(errno));
			return 1;
		}
	}
	return 0;
}
