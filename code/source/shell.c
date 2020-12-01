#include "summary.h"
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
extern char** __environ;
void shell(){
    char *args[10];
    printf("welecome to my shell!:\n");
    int arg=0;
    while (1)
    {
        printf("arg[%d]:",arg);
        args[arg]= (char*)malloc(10);
        fgets(args[arg],10,stdin);
        if(args[arg][0]=='\n'){
            args[arg]=NULL;
            break;
        }else{
            args[arg][strlen(args[arg])-1]=0;
        }
        arg++;
    }
    if(args[0][0]!=0){
        int pid = fork();
        if(pid==0){
            execvp(args[0],args);
            exit(0);
        }else{
            int state = 0;
            int p = wait(&state);
            shell();
        }
    }
}