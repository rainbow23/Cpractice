//
//  functionPointer.c
//  
//
//  Created by Futohashi on 2/15/17.
//
//

:#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int NUM = 2;
char *lists [] =
{
    "sports bieber",
    "sports workout"
};

int sports_no_bieber(char *s)
{
    //printf("%s\n",s);
    //return strstr(s,"sports") && !strstr(s,"bieber");
    if(strstr(s,"sports") && !strstr(s,"bieber"))
    {
        return 1;
    }
    return 0;
}

int sports_or_workout(char* s)
{
	if(strstr(s, "sports") || strstr(s, "workout"))
	{
		return 1;
	}
	return 0;
}

int ns_theater(char* s)
{
	return 0;
}

int art_theater_dining(char* s)
{
	return 0;
}

void find(int(*match)(char*))
{
    for (int i=0; i<NUM; i++) {
        if(match(lists[i]) ==1)
        {
            printf("%s\n",lists[i]);
        }
        else
        {
            //printf("%s\n","else");
        }
    }
}

int main ()
{
    find(sports_no_bieber);
	find(sports_or_workout);
    return 0;
}
