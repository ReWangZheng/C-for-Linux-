#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
void stty(){
    int fd = open("/dev/pts/1",O_WRONLY|O_NDELAY);
    if(fd==-1){
        perror("can't open file!");
    }
    int s;
    s = fcntl(fd,F_GETFL);
    s|=O_SYNC;
    int result = fcntl(fd,F_SETFL,s);
    if(result==1){
        perror("can't set!.....");
    }
    char buf[10];
    int len=0;
    while ((1))
    {   
        len=read(fd,buf,10);
        if(len>1){
            printf("有输入！");
            break;
        }
        printf("ok:%s",buf);
    }
    
}