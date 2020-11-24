#include "cp.h"
#include <fcntl.h>
#include <stdio.h>
#include "unistd.h"
#define BUFSIZE 1024
void cp(char * src,char * des){
    int SRC_FD = open(src,O_RDONLY);
    if(SRC_FD==-1){
        perror("Can't open file!");
        return;

    }
    
    int DES_FD = creat(des,0664);
    if(DES_FD==-1){
        perror("Can't open file!");
        return;
    }
    lseek(SRC_FD,30,SEEK_SET);
    char buf[1024];
    int read_size = 0;
    while((read_size=read(SRC_FD,buf,BUFSIZE))!=0){
        write(DES_FD,buf,read_size);
    }
    close(SRC_FD);
    close(DES_FD);
}