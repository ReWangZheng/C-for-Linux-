#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int f(int sig){
    printf("interrupt has occur!");
}
void sigdemotest(){
    signal(SIGINT,f);
    while (1)
    {
        
        sleep(1);
        printf("hello\n");
    }
    
}