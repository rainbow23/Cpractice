#include<stdarg.h>
#include<stdio.h>
#include<string.h>

unsigned short getDigit(int num)
{
    unsigned short digit=0;
    int n=num;
    while(n!=0)
    {
        n = n/10;
        digit++;
    }
    return digit;
}

void total (int totalnum, ...)
{
	va_list vList;
	va_start(vList, totalnum);
	unsigned int total;
    
    char cBuff[1024]= "total: ";
    char vBuff[100];
    
	for(int i=0; i<totalnum; i++)
	{
        char vb[10];
		int value  = va_arg(vList,int);
        total += value;
        
        sprintf(vb, "%d: ",value);
        strcat(vBuff,vb);
	}
    //引数をプリント
    strcat(cBuff, vBuff);
	printf("%s\n", cBuff);
    
	printf("total:%u \n", total);
    
	va_end(vList);
}

int main()
{
	//total(7,2,4,6,8,10,12,13);
	total  (5,2,4,6,8,100);
    
}
	
