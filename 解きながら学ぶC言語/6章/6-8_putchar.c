#include <stdio.h>

void put_ast(int no)
{

	while(no > 0)
	{
		printf("*");
		no--;
	}
}
int main(int argc, char *argv[])
{
	int no;
//	scanf("%d\n", &no);

	int width;
	int height;

	puts("長方形を作りましょう\n");

	printf("横幅；"); scanf("%d", &width);
	printf("高さ；"); scanf("%d", &height);

	for(int i = 0; i < height; i++)
	{
		put_ast(width);
		printf("\n");
	}

	return 0;
} 
