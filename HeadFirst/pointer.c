#include <stdio.h>

int main() {
	char str[] = "kitty on your lap";
    char *str_p;
    char **str_pp;

    str_p  = &str[0];
    str_pp = &str_p;

    /*
    printf("******************\n");

    printf("&str:        %p\n", str);//&str 0x7fff59f2e7a0
    printf("str:         %s\n" , str);//str kitty on your lap

    printf("******************\n");

    printf("*str_p:      %c\n", *str_p);      // *str_p k
    printf("&(*str_p):   %p\n", &(*str_p));//&(*str_p) 0x7fff59f2e7a0
    printf("str_p:       %s\n", str_p);        //str_p kitty on your lap
    printf("str_p:       %p\n", str_p);        //str_p 0x7fff59f2e7a0

    printf("******************\n");

    printf("*str_pp:     %s\n", *str_pp);
    printf("**str_pp:    %c\n", **str_pp);

    printf("&(*str_pp):  %p\n", &(*str_pp));
    printf("&(**str_pp): %p\n", &(**str_pp));
    */

    /*
    printf("str_pp: %p\n", str_pp);
    printf("&str_p: %p\n", &str_p);

    printf("*str_p: %s\n", *str_pp);
    printf("str   : %s\n", str);
    */

    /*
    printf("str_pp %p\n", str_pp);
    printf("&str_pp %p\n", &str_pp);
    //printf("str_p %s\n", *str_p);
    */

    typedef struct island{
        char *name;
        char *opens;
        char *closes;
        struct island *next;
    } island;

    island amity = {"アミティ", "09:00", "17:00", NULL};
    island craggy = {"クラッギー", "09:00", "17:00", NULL};
    island isla_nublar = {"イスラヌブラル", "09:00", "17:00", NULL};
    island shutter = {"シャッター", "09:00", "17:00", NULL};
    amity.next = &craggy;
    craggy.next = &isla_nublar;
    isla_nublar.next = &shutter;

    island *i = &amity;

    printf("%lu",&i);

    for(; i!= NULL; i = (*i).next){//i->next){
        //printf("%lu",&i);
        //printf("名前：%s 営業時間：%s-%s \n", i->name, i->opens, i->closes);
    }

	return 0;
}
