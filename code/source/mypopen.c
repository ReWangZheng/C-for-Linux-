#include "summary.h"
#include <unistd.h>
#include <string.h>
FILE * mypopen(const char * shell,const char * mode){
    int pipeid[2];
    int parent=0;
    int child=1;
    if(pipe(pipeid)!=0){
        perror("can't open the pipe!");
    }
    if(strcmp(mode,"w")==0){
        //if the mode is write
        parent = 1;
        child = 0;
    }else if(strcmp(mode,"r")){
        // if the mode is read
        parent = 0;
        child = 1;
    }
    int pid = fork();
    if(pid>0){
        FILE *res = fdopen(pipeid[parent],mode);  
        return res;
    }else{
        dup2(pipeid[child],child); //if the mode is read,this parent pipe descriptoer wiil be 0
        close(pipeid[child]);
        execlp(shell,"-",NULL);
    }
          
    
}
