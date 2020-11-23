#include "mywho.h"
#include <stdio.h>
int main(){
    int * addr = allocate();
    printf("%x",addr);
    return 0;
}