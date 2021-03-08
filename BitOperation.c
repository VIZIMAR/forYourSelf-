//remember bitch 
/*
~ (1=0 ; 0=1) 
& (0 & 0 = 0)
  (0 & 1 = 0)
  (1 & 0 = 0)
  (1 & 1 = 1)
| (0 | 0 = 0)
  (0 | 1 = 1)
  (1 | 0 = 1)
  (1 | 1 = 1)
^ (0 ^ 0 = 0)
  (0 ^ 1 = 1)
  (1 ^ 0 = 1)
  (1 ^ 1 = 1)  
*/
#include <stdio.h>
int main(void){
    int num1,mask=0x1;
    while(scanf(" %d",&num1))
        if((num1&mask))
            printf("odd\n");
        else puts("even");
        
}
