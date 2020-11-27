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

void newhandle(int c){
    printf("the interrupt has occur!");
}

void newsigdemo(){
    struct sigaction nh;
    char buf[10];
    sigset_t blocked; //这是信号集合
    nh.sa_flags = SA_RESETHAND|SA_RESTART;
    nh.sa_handler=newhandle;
    sigemptyset(&blocked);
    sigaddset(&blocked,SIGQUIT);
    nh.sa_mask = blocked;
    if(sigaction(SIGINT,&nh,NULL)==-1){
        perror("no sigaction!");
    }else{
        while (1)
        {
            fgets(buf,10,stdin);
            printf("input:%s",buf);
        }
    }
}