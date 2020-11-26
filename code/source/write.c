#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
void cwrite(char * filename){
    int fd;
    fd = open(filename,O_RDONLY);
    if(fd < 1){
        perror("can't open");
    }
    char buf[1024];
    int size = 0;
    while((size = fgets(buf,1024,stdin))!=-1){
        if(write(fd,buf,1024)==-1){
            break;
        }
    }
}