#include <stdio.h>

int main()
{
	char *moji = "ABCDEDF\n";
	FILE *fp;

	if((fp = fopen("sample.txt", "w")) == NULL)
	{	
		printf("file open error!!\n");	
	}

	for(int i=0; i<1000; i++)
	{
		fprintf(fp, "%s", moji);
	}	
	
	printf(" moji %p\n", (void *)moji);	
	//printf("*moji %c\n", *moji);	
	printf("&(*moji) %p\n", (void *)&(*moji));	
	printf("&moji %p\n", (void *)&moji);	

	int array[] = {0,1,2,3};
	int* pArray = &array[0];
	pArray[0] = 100;
	printf("pArray[0] %i\n", pArray[0]);
	
	*(pArray + 1) = 200;
	printf("pArray[1] %i\n", pArray[1]);

	*(array + 2) = 300;
	printf("array[2] %i\n", array[2]);
	printf("pArray[2] %i\n", pArray[2]);
		
	printf("\n");

	printf("(void *)&array %p\n", (void *)&array);
	printf("*array %i\n", *array);
	
	printf("(void *)&pArray %p\n", (void *)&pArray);
	printf("(void *) pArray %p\n", (void *)pArray);
	printf("*pArray %i\n", *pArray);
	
	return 0;
}
