//
//  LookByteSize.c
//  
//
//  Created by Futohashi on 8/20/16.
//
//

#include "LookByteSize.h"
#include <string.h>
#include <stdlib.h>

void sizeCheck(){
    char *tChar = "1234567890";
    
    size_t tCharSize = strlen(tChar);
    
    printf("tCharSize %zu\n", tCharSize);
    size_t intSize = tCharSize * sizeof(int);
    
    printf("intSize %zu\n", intSize);
    
    printf("sizeof(int) %zu\n", sizeof(int));
    printf("sizeof(unsigned int) %zu\n", sizeof(unsigned int));
    printf("sizeof(char) %zu\n", sizeof(char));
    printf("sizeof(short) %zu\n", sizeof(short));
}

int main()
{
    char moji[] = "12";
    size_t mSize = strlen(moji) * sizeof(int);
    printf("mojiSize: %zu \n", mSize);
    printf("mojiSize + 1: %zu \n", mSize + 1);
    printf("mojiSize + (int)1: %zu \n", mSize + (int)1);
    printf("mojiSize + sizeof(int): %zu \n", mSize + sizeof(int));
    
    printf("\n");
    
    unsigned int retsu[] = {1,2,3,4,5};
    size_t retsuLength = sizeof(retsu) / sizeof(retsu[0]);//型が確定
    printf("sizeof(retsu): %zu \n", sizeof(retsu));
    printf("retsu[0]: %zu\n", sizeof(retsu[0]));
    printf("retsuLength: %zu \n", retsuLength);
    printf("retsuLength + 1: %zu \n", retsuLength + 1);
    printf("retsuLength + sizeof(unsigned int): %zu \n", retsuLength + sizeof(unsigned int));
    
    /* log
     sizeof(retsu): 20
     rSize: 5
     rSize + 1: 6
     rSize + sizeof(int): 9
     */
    
    
    char *check = malloc(mSize +1);
    //printf("check length: %zu\n", strlen(check));//取れない
    /*
    char *check2 = "abcd";
    printf("check2 length: %zu\n", strlen(check2));//取れる
    */
    return 0;
};

