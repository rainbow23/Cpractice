//
//  tracks.c
//  SampleDelegate
//
//  Created by Futohashi on 8/14/16.
//  Copyright © 2016 FUTOHASHI MITSUHIRO. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
char tracks[][80] = {
    "I left my heart in Harvard Med School",
    "Newark, Newark - a wonderful town",
    "Dancing with a Dork",
    "From here to maternity",
    "The girl from Iwo Jiwa"
};

void find_track(char word[]){
    for(int i=0; i<5; i++){
        if(strstr(tracks[i],word)){
            printf("見つかりました　曲番:%i 曲名:%s\n", i, tracks[i]);
        }
    }
}

int main(){
    
    char searchKeyword[80];
    
    printf("検索単語を入力してください");
    
    fgets(searchKeyword, 80, stdin);
    
    searchKeyword[strlen(searchKeyword) -1] = '\0';
    
    
    
    printf("searchKeyword length %lu\n", strlen(searchKeyword));
    printf("searchKeyword %s\n", searchKeyword);
    find_track(searchKeyword);
    return 0;
}
*/

typedef struct{
    char *name;
}island;


void reverse(){
    printf("逆さ表示したい文字を入力してください\n");
    char moji[10];
    fgets(moji, 10, stdin);
    
    size_t len = strlen(moji);
    printf("len %lu\n", len);
    
    char* startPos = (moji + len) -1; //番兵文字を含めないようにする為 -1する
    //printf("%c\n", *startPos);
    
    //bufに詰める
    char buff[len + 1];
    buff[len] = '\0';
    int buffCount=0;
    while(startPos >= moji){
        printf("%c", *startPos);
        
        buff[buffCount] = *startPos;
        startPos = startPos - 1;
        buffCount +=1;
    }
    puts("\n");
    
    printf("buff %s\n", buff);
}

int main ()
{
    reverse();
}