//my qsort() function
#include <stdio.h>
#include <stdlib.h>
#define ARRLEN 10
void arrFilling(double*,int);
void showArr(double*,int);
int cmp(const void*p1,const void*p2);
int main(void){
    double randomVal[ARRLEN];
    arrFilling(randomVal,ARRLEN);
    printf("Unsorted array :\n");
    showArr(randomVal,ARRLEN);
    qsort(randomVal,ARRLEN,sizeof(double),cmp);
    printf("Sorted array :\n");
    showArr(randomVal,ARRLEN);
}
/***************************************/
void arrFilling(double*arr,int n){
    int index=0;
    while(index<n){
        *(arr+index)=(double)rand()/(double)rand()+0.001;
        index++;
}
}
/***************************************/
void showArr(double*arr,int n){
    int index=0;
    while(index<n){
        printf("%9.6lf",*(arr+index));
        index++;
        if(index%5==0)
        printf("\n");
    }
}
/***************************************/
int cmp(const void*p1,const void*p2){
    const double *ptr1=(const double*)p1;
    const double *ptr2=(const double*)p2;
    if(*ptr1<*ptr2)
        return 1;
    else if (*ptr1>*ptr2)
        return -1;
    else
        return 0;        
}
