#include "summary.h"
#include <unistd.h>
void usepipe(){
    int pipe_id[2];
    int s = pipe(pipe_id);
    if(s==-1){
        perror("创建管道失败!");
        _exit(1);
    }
    char read_buf[10];
    char buf[10];

    int pid = fork();
    switch (pid){
    case 0:
        //child process read port
        while (1)
        {
            read(pipe_id[0],read_buf,10);
            printf("\nchild-read:%s",read_buf);
        }
        
        break;
    default:
        //parent process write port
        while (1)
        {
            printf("parent-input:");
            fgets(buf,10,stdin);
            write(pipe_id[1],buf,10);
        }
        
        break;
    }
}