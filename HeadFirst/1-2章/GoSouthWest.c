//
//  GoSouthWest.c
//  
//
//  Created by Futohashi on 7/21/16.
//
//

#include "GoSouthWest.h"
#include <stdio.h>

void go_south_west(int *lat, int *lon){
    //lat = lat +1;
    *lat = *lat +1;
    *lon = *lon +1;
}

void go_south_west2(int lat, int lon){
    lat = lat +1;
    lon = lon +1;
}



//int main (){
//    int latitude = 32;
//    int longtude = -64;
//    
//    go_south_west(&latitude, &longtude);
//    //go_south_west2(latitude, longtude);
//    
//    printf("latitude %i longtude %i ", latitude, longtude);
//    return 0;
//}

/*
void fortune_cookie(char msg[]){
    printf("メッセージの読み込み: %s\n", msg);
    printf("msgは%luバイトを専有しています\n", sizeof(msg));
}

int main (){
    char quote[] = "fat";//"Cookies make you fat";
    printf("quoteは%luバイトを専有しています\n", sizeof(quote));
    fortune_cookie(quote);
}
*/

/*
void skip(char *msg){
    puts(msg+6);
 
    //printf(" %c\n", msg[6]);
    //printf(" %c\n", *(msg+6));
}

int main (){
    char msg_from_amy[] = "Don't call me";
    skip(msg_from_amy);
}
*/



/*
int main (){
    int contestants[] = {1,2,3};
    int *choice = contestants;
    contestants[0] = 2;
    contestants[1] = contestants[2];
    contestants[2] = *choice;
    printf(" %i\n", contestants[2]);
    
    printf("0 %i\n 1 %i\n 2 %i\n", contestants[0], contestants[1], contestants[2]);
    
    return 0;
}
*/

/*
int main (){
    int nums[] = {1,2,3};
    printf("numsの位置は%p\n", nums);
    printf("nums +1 の位置は%p\n", nums + 1);
    //printf("2[nums] の位置は%d\n", 2[nums]);
}
*/

/*
int main (){
//    int age;
//    printf("年齢を入力してください:");
//    scanf("%i", &age);
//    printf("年齢出力 %i\n", age);
    
    char first_name[30];
    char last_name[30];
    printf("名と姓を入力してください:");
    scanf("%29s %29s", first_name, last_name);
    //scanf("%29s", first_name);
    printf("名:%s 姓:%s\n", first_name, last_name);
    return 0;
}
*/

void skip(char msg[])
{
    //puts((msg + 6));
}

int main ()
{
    char msgFromArmy[] = "Don't call me";
    printf("msgFromArmy %lu\n", sizeof(msgFromArmy));
    skip(msgFromArmy);
    
    char food[5];
    printf("好きな食べ物を入力してください");
    scanf("%s\n",food);
    printf("好きな食べ物 入力結果 %s\n", food);
    return 0;
}


/*
int main (){
    char food[5];
    printf("好きな食べものを記入してください");
    fgets(food, sizeof(food), stdin);
    printf("好きな食べ物: %s\n", food);
}
*/