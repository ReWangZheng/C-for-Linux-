#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include "summary.h"
int main()
{
    FILE* fin = mypopen("who","r");
    char buf[30];
    fgets(buf,30,fin);
    printf("the res:%s",buf);
}
