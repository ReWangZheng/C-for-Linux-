#include <stdio.h>
#include "cp.h"
int main(int size,char* args[]){
    printf("%d\n",size);
    if(size!=3){
        printf("参数数量太少");
        exit(1);
    }
    char * src = args[1];
    char * des = args[2];
    cp(src,des);
    return 0;
}