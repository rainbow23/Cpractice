//
//  fprint_test.c
//  
//
//  Created by Futohashi on 10/10/16.
//
//

#include "fprint_test.h"
#include <stdio.h>

int main()
{
    char word[10];
    int i = 0;
    while(scanf("%9s", word)==1)
    {
        i = i + 1;
        //printf("word1:%s\n",word);
        
        if(i%2){
            fprintf(stdout, "%s\n", word);
            //printf("word2:%s\n",word);
        }
        else{
            fprintf(stderr, "%s\n", word);
            //printf("word3:%s\n",word);
        }
    
    }
    return 0;
}
