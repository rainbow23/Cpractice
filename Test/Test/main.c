//
//  main.c
//  Test
//
//  Created by Futohashi on 6/14/15.
//  Copyright (c) 2015 FUTOHASHI MITSUHIRO. All rights reserved.
//
//
#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a, b;
    
    int *p;
    p  = &a;
    
    b  = *p;
    
    *p = 3;

    printf("%d %d\n", *p, p);
    return 0;

}


