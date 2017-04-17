#include <stdio.h>

void reverse_array(int *arrayV, int length)
{
	int first_half_range = length /2; 
	int tmp;

	for(int i = 0; i < first_half_range; i++)
	{
		tmp = *(arrayV +i);
		arrayV[i] = arrayV[(length - 1) - i];
		arrayV[(length - 1) - i] = tmp;
	}
}

void setArray(int arrayLength)
{
	int array[arrayLength];
	puts("配列の値を指定して下さい");

	for(int i = 0; i < arrayLength; i++)
	{
		scanf("%d: ", &array[i]);
	}

	for(int i = 0; i < arrayLength; i++)
	 printf("array[%d] = %d\n", i, array[i]);

	reverse_array(array, arrayLength);

	puts("配列の値を逆に設定");

	for(int i = 0; i < arrayLength; i++)
	{
		printf("array[%d] = %d\n", i, array[i]);
	}
}


int main(int argc, char *argv [])
{
	int arrayLength;
	//int array[arrayLength];

	puts("配列の要素数を指定してください");
	scanf("%d: ", &arrayLength);

	setArray(arrayLength);
}
