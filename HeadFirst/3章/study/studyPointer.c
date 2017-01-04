//
//  studyPointer.c
//  
//
//  Created by Futohashi on 10/23/16.
//
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void change(char** moji){
    char* c = (char*)malloc(sizeof(char)*7);
    c = "change";
    *moji = c;
    
    
    printf("*moji address: %p\n", *moji);
    printf("*moji: %s\n", *moji);
}




int main(int argc, char *argv[])
{
    
    char* mojis ="ABCDE";
    printf("mojis address: %p\n", &mojis);
    
    change(&mojis);
    
    
    
    char str[] = "kitty on your lap";
    //配列先頭アドレス   0x7fff541a0780
    char *str_p;
    //ポインタアドレス   0x7fff541a0768
    //保存する値        0x7fff541a0780
    char **str_pp;	/*ポインタのポインタ*/
    //ポインタアドレス   0x7fff52bda760
    //保持する値        0x7fff541a0768
    //保持する値が持つ値 0x7fff541a0780
    
    str_p = str;
    str_pp = &str_p;
    
    printf("文字型配列変数\n");
    printf("配列先頭アドレス = %p\n" , str);
    printf("保持する文字列 = %s\n\n" , str);
    
    printf("ポインタの示す値\n");
    printf("ポインタアドレス = %p\n" , &str_p);
    printf("保存する値 = %p\n" , str_p);
    printf("保持するアドレスが持つ内容 = %s\n\n" , str_p);
    
    printf("ポインタのポインタが示す値\n");
    printf("ポインタアドレス = %p\n" , &str_pp);
    printf("保持する値 = %p\n" , str_pp);
    printf("保持する値が持つ値のアドレス = %p\n" , &*str_pp);
    printf("保持する値が持つ値 = %p\n" , *str_pp);
    printf("保持する値が持つ値の内容 = %s\n", *str_pp);
    printf("保持する値が持つ値の内容 = %c\n\n", **str_pp);
    
    
    int a;
    int *p;
    
    a = 3;
    printf("aのアドレス: %p\n", &a);
    
    p = &a;
    printf("pのアドレス: %p\n", &p);
    printf("pの指しているアドレス: %p\n", p);
    printf("pの指している値: %d\n\n", *p);
    
    int b=2, c=3;
    int *pb, *pc;
    
    pb = &b;
    pc = &c;
    
    pb = pc;
    
    printf("pbの指している値: %d\n", *pb);
    printf("pcの指している値: %d\n", *pc);
}

