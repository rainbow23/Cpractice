#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_scores(const void* score_a, const void* score_b)
{
	int sa = *(int*)score_a;
	int sb = *(int*)score_b;
	
	return sa - sb;
}

int main ()
{
	int array[] = {2727, 28, 4958, 506, 938, 34};
	qsort(array, 6, sizeof(int), compare_scores);
	puts("順番に並べた数");
	for(int i=0; i<6; i++)
	{
		printf("%d\n", array[i]);
	}
}
