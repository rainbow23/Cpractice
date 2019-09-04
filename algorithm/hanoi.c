#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void hanoi(int n, int from, int to, int work);
void initialize(int num);
int count;

typedef struct link
{
	int number;
	struct link *next;
} link;

link* createLink(int num)
{
	link *i = malloc(sizeof(link));
	i->number = num;
	i->next = NULL;
	return i;
}

link *piles[3];

void printPiles()
{
	printf("--------------------\n");
	printf("count %d\n", count);
	for(int i=0; i<3; i++)
	{
		printf("%d:", piles[i]->number);
		for(link *l = piles[i]->next; l != NULL; l = l->next)
		{
			printf(" %d", l->number);
		}
		printf("\n");
	}
}

void moveOne(int from, int to)
{
	count++;
	//printf("piles[%d]->number %d\n", from, piles[from]->number);
	link *fromRoot = piles[from];
	link *fromLast = NULL;
	link *fromPre = NULL;
	link *addLink = NULL;
	for(fromLast = fromRoot->next; fromLast != NULL; fromLast = fromLast->next)
	{
		/*
		if(fromLast != NULL)
			printf("last %d\n", fromLast->number);
		else
			printf("last NULL\n");

		if(fromPre != NULL)
			printf("pre  %d\n", fromPre->number);
		else
			printf("pre NULL\n");
		*/
		if(fromLast->next == NULL && fromPre == NULL)//要素が一つ
		{
			//printf("fromLast %d\n", fromLast->number);
			addLink = fromLast;
			fromRoot->next = NULL;
		}
		else if(fromLast->next == NULL && fromPre != NULL)//一つ以上要素がある場合
		{
			//printf("fromPre %d fromLast %d\n", fromPre->number, fromLast->number);
			addLink = fromLast;
			fromPre->next = NULL;
		}
		fromPre = fromLast;
	};

	//printf("addLink->number %d\n", addLink->number);

	//toの一番最後に追加
	link *toRoot = piles[to];
	link *toLast = NULL;
	link *toPre = NULL;
	//printf("toRoot->number %d:\n", toRoot->number);
	for(toLast = toRoot->next; toLast != NULL; toLast = toLast->next){
	//	printf("lto %d\n", lto->number);
		toPre = toLast;
	};

	if(toRoot->next == NULL)//一番最初の要素になる
	{
		toRoot->next = addLink;
		//printf("toRoot->next->number %d\n", toRoot->next->number);
	}
	else//一つ以上要素がある場合
	{
		toPre->next = addLink; 
		//printf("toPre->next->number %d\n", toPre->next->number);
	}
}

void initialize(int num)
{
 	count = 0;
	for(int i=0; i<3; i++)
	{
		piles[i] = createLink(i);
		piles[i]->number = i;
	}

	link *start = NULL;
	link *pre   = NULL;
	link *next  = NULL;
	for(int i=num; i>0; i--, pre = next)
	{
		next = createLink(i);
		if(start == NULL)
		{
			start = next;
		}
		if(pre != NULL)
		{
			pre->next = next;
		}
	}
	piles[0]->next = start;
}

int main(int argc, char *args[])
{
	char line[100];
	fgets(line, sizeof(line), stdin);
	//printf("line %s\n", line);
	int num = atoi(line);
	//printf("num %d\n", num);

	initialize(num);
	printPiles();

	hanoi(num, 0, 2, 1);
	return 0;
}

void hanoi(int n, int from, int to, int work)
{
	if(n == 0) return;
	hanoi(n-1, from, work, to);
	moveOne(from, to);
	printPiles();
	hanoi(n-1, work, to, from);
}
