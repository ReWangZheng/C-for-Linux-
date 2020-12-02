#include "summary.h"
#include <unistd.h>
#include <wait.h>
void bc(){
    int pid, todc[2],fromdc[2];
    //创建两个管道
    if(pipe(todc)==-1||pipe(fromdc)==-1){
        perror("open the pipe fail!");
        return;
    }
    if((pid = fork())==-1){
        perror("open the process faild!");
    }
    
    if(pid==0){
        // child process
        //重定向，将管道复制到标准输入
        dup2(todc[0],0); //read //这里肯定是子进程,输出给服务器端，输入给服务器端
        //关闭原来的管道
        close(todc[0]);
        close(todc[1]);
        //重定向，将管道复制到标准输出
        dup2(fromdc[1],1); // write 将子进程的标准输出指向管道 
        //关闭原来的管道
        close(fromdc[0]);
        close(fromdc[1]);
        char buf[30];
        execlp("bc","-",NULL);
    }
    if(pid>0){
        int state;
        char buf[30];
        char inb[30];
        // 利用文件描述符打开得到Filsouttream
        FILE * fout = fdopen(todc[1],"w");
        
        if(fout==NULL){
            perror("error！ ");
            return;
        }
        FILE * fin = fdopen(fromdc[0],"r");
        if(fin==NULL){
            perror("error! ");
        }
        while (1)
        {
            printf("请输入表达式：");
            //从标准输入中得到表达式
            fgets(buf,30,stdin);
            //将其输入到进程中
            fprintf(fout,buf);
            //刷新一下缓冲区
            fflush(fout);
            //从通道中得到数据
            fgets(inb,30,fin);
            printf("结果->:%s",inb);
        }
        wait(&state); //等待子进程结束
    } 
}