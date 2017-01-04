//
//  MiniProgram2.c
//  
//
//  Created by Futohashi on 8/27/16.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int main()
{
    float latitude;
    float longitude;
    char info[80];
    int started = 0;
    
    puts ("data=[");
 
    //int result = scanf("%f,%f,%79[^\n]", &latitude, &longitude, info);
    //printf("result: %i\n", result);
 
    
    while(scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3){
        if(started)
            printf(",\n");
        else{
            started = 1;
        }
        
        if(latitude < -90 || latitude > 90){
            fprintf(stderr,"Invalid latitude: %f\n",latitude);
            return 2;
        }
        if(longitude < -180 || longitude > 180){
            fprintf(stderr,"Invalid longitude: %f\n",longitude);
            return 2;
        }
        
        printf("{latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info);
    }
    
    puts("\n]");
    
    
    return 0;
}
*/

int main(int argc, char *argv[])
{
    //ユーザー入力文字を変数に保存
    char line[80];
    if(argc != 6){
        fprintf(stderr, "五つの引数を指定してください\n");
        return 1;
    }
    FILE *in = fopen("spooky.csv", "r");
    FILE *file1 = fopen(argv[2], "w");
    FILE *file2 = fopen(argv[4], "w");
    FILE *file3 = fopen(argv[5], "w");
    
    /*
    //読み込みファイルを開く
    FILE *in = fopen("spooky.csv", "r");
    
    //書き込みファイルを開く
    FILE *fileUfos          = fopen("ufos.csv", "w");
    FILE *file2 = fopen("disappearance.csv", "w");
    FILE *fileOthers        = fopen("others.csv", "w");
    */
    int count =0;
    //ユーザー入力文字を取得
    while(fscanf(in, "%79[^\n]\n", line) == 1)
    {
        if(strstr(line, argv[1]))
        {
            fprintf(file1, "%s\n", line);
            //printf("write file1: %s loop: %i\n", line, count);
        }
        else if(strstr(line, argv[3]))
        {
            fprintf(file2, "%s\n", line);
            //printf("write file2: %s loop: %i\n", line, count);
        }
        else
        {
            fprintf(file3, "%s\n", line);
            //printf("write file3: %s loop: %i\n", line, count);
        }
        
        count ++;
    }
    
    //ファイル閉じる
    fclose(file1);
    fclose(file2);
    fclose(file3);
    
    return 0;
}

