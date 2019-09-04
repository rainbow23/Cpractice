//
//  struct.c
//
//
//  Created by Futohashi on 2/7/17.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct island{
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

island* create(char *name)
{
    island *i = malloc(sizeof(island));
    i->name   = strdup(name);
    i->opens  = "9:00";
    i->closes = "17:00";
    i->next   = NULL;
    return i;
}

void display(island *i)
{
    printf("名前:%s 営業時間:%s-%s\n",i->name, i->opens, i->closes);
}

int main()
{
    char name[5];
    island *next = NULL;
    island *i    = NULL;
    island *start= NULL;

    for(; fgets(name,80,stdin) != NULL; i = next)
    {
        next = create(name);

        if(start == NULL)
        {
            start = next;
        }

        if(i != NULL)
        {
            i->next = next;
        }

    }

    display(start);
}
