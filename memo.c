//
//  memo.c
//  
//
//  Created by Futohashi on 3/4/17.
//
//

#include <stdio.h>

int main ()
{
    int allStage  = 100;
    int rowNum    = 3;
    int ColumnNum = allStage/3;
    
    if(allStage%3)
    {
        ColumnNum += 1;
    }
    
    
    
    for(int ci = 0; ci < ColumnNum; ci++)
    {
        printf("id: ");
        for(int ri = 1; ri < rowNum+1; ri ++)
        {
            int id = (ci * rowNum) + ri;
            
            if(id > allStage){ break; }
            printf("%i ", id);
        }
        printf("\n");
    }

}
