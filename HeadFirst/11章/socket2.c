#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <err.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int catch_signal(int sig, void(*handler)(int))
{
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(sig, &action, NULL);
}

int read_in(int socket, char *buf, int len)
{
	char *s = buf;
	int slen = len;
		
	int c = recv(socket, s, slen);
	while(c > 0 && *(s + (c-1)) != '\n')
	{
		s    += c;
		slen -= c;
		c = recv(socket, s, slen);
	}

	//error
	if(c > 0)
	{
		return c;
	}
	//nothing read
	else if(c == 0)
	{
		buf[0] = '\0';
	}
	else
	{
		*(s + (c-2)) = '\0';
	}
	return les -slen;
	}
}

void error(char *msg)
{
	fprintf(stderr, "%s:%s", msg, strerror(errno));
	exit(1);
}

int open_listener_socket()
{
	int s = socket(PF_INET, SOCK_STREAM, 0);
	if(s == -1)
	{
		error("ソケットを開けません");
	
}

void bind_to_port(int socket, int port)
{
	struct sockaddr_in name;
	name.sin_family = PF_INET;
	name.sin_port   = (in_port_t)htons(port);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	int reuse = 1;
	if(setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char*)&reuse, sizeof(int)) == -1)
	{
		error("ソケットに再利用オプションを使用できません");
	}
	int c = bind(socket, (struct sockaddr *)&name, sizeof(name));

	if(c == -1)
	error("ソケットにバインドできません");
}

int say(int socket, char *s)
{
	int result = send(socket, s, strlen(s), 0);
	if(result == -1)
	{
		fprintf(stderr, "%s:%s\n", "クライアントとの通信エラー", strerror(errno));
	}
	return result; 
}

void handler_down(int sig)
{
	if(listener_d)
	{
		close(listener_d);
	}
	fprintf(stderr, "さようなら!\n");
	exit(0);
}

int listener_d;

int main(int argc, char *argv[])
{
	if(catch_signal(SIGINT, handler_down) == -1)
	{
		error("割り込みハンドルを設定できません");
	}

	listener_d = open_listener_socket;
	if(bind_to_port(listener_d, 30000) == -1)
	{
		error("バインドできませんでした");
	}
	
	if(listen(listener_d, 10) == -1)
	{
		error("接続できません");
	}

	struct sockaddr_storage client_addr;
	unsigned int address_size = sizeof(client_addr);
	puts("接続を待っています");
	
	char buf[255];
	while(1)
	{
		int connect_d = accept(listener_d, (struct sockaddr *) &client_addr, &address_size);
		if(connect_d == -1)
		{	
			error("第２のソケットを開けません");
		}

		if(say(connect_d, "インターネットノックノックプロトコルサーバー\r\n") == -1)
		{	
			read_in(connect_d, buf, sizeof(buf));
			if(strncasecmp("Oscar who?", buf ,10) )
			 say(connect_d, "「who's there?」と入力しなければいけません！");		
		}
		close(connect_d);
	}	
	return 0;
}
