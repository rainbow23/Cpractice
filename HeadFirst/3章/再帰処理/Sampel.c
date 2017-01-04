//
//  Sampel.c
//  
//
//  Created by Futohashi on 9/12/16.
//
//

#include "Sampel.h"
#include <stdio.h>
#include <stdint.h>

unsigned long calc(int num){
    if(num < 1){
        return 1;
    }
    
    
    int64_t mm = calc(num -1);
    printf("num %i result %lld \n",num, mm);
    return 2 * mm;

}

int main(){
    int64_t result = calc(64);
    printf("result %lld\n",result);

}
