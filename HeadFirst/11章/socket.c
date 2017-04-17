#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <time.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 

void error(char *msg)
{
	fprintf(stderr, "%s:%s\n", msg, strerror(errno));
	exit(1);
}

int main(int argc, char *argv[])
{
	char *advice[] = 
	{
		"食べる量を減らしなさい\r\n",
		"タイトなジーンズにしなさい。太って見えることはありません。\r\n",
		"一言：不適切\r\n",
		"今日だけは正直になりなさい。「本当に」思っていることを上司に言いなさい\r\n",
		"そのヘアスタイルは考え直した方がいいでしょう\r\n",
	};

	int listen_d = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in name;
	name.sin_family      = PF_INET;
	name.sin_port        = (in_port_t)htons(30000);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	
	int reuse = 1;
	if(setsockopt(listen_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
	{
		error("ソケットに再利用オプションは設定できません");
	} 

	if(bind(listen_d, (struct sockaddr *) &name, sizeof(name)) == -1)
		error("ポートをバインドできません"); 

	listen(listen_d, 10);

	puts("接続を待っています");
	
	while(1)
	{
		struct sockaddr_storage client_addr;
		unsigned int address_size = sizeof(client_addr);
		int connect_d = accept(listen_d, (struct sockaddr *)&client_addr, &address_size);

		srand((unsigned int)time (NULL));	
		char *msg = advice[rand() % 5];
		send(connect_d, msg, strlen(msg), 0);
		close(connect_d);
	}
	return 0;	

}
