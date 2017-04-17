#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	char *w = getenv("EXTRA");

	if(!w)
	{
		w = getenv("FOOD");
		//printf("getenv FOOD %s\n", getenv("FOOD"));
	}
	if(!w)
	{
		w = argv[argc -1];
	}

	char *c = getenv("EXTRA");
	if(!c)
	{
		c = argv[argc -1];
	}
	
	printf("argc %i:\n", argc);
	for(int i=0; *(argv+i)!=NULL; i++)
	{
		printf("*(argv+%i) %s:\n", i, (char *)*(argv+i));
	}

	printf("%s:%s\n", c, w);
	return 0;
}
