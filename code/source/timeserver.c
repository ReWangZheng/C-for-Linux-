#include "summary.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
void start_server(){
    //首先建立一个套接字
    int sid = socket(PF_INET,SOCK_STREAM,0);
    if(sid==0){
        perror("open the socket err!");
        return;
    }
    //然后绑定套接字
    struct sockaddr_in saddr;
    saddr.sin_port = htons(12345);
    saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    saddr.sin_family = AF_INET;
    // 开始绑定
    
    int state = bind(sid,(struct sockaddr*)&saddr,sizeof(saddr));
    if(state != 0){
        return;
    }
    state = listen(sid,10);
    if(state == -1){
        perror("cant't use the socket to listen the host!");
        return;
    }
    struct sockaddr client;
    char buf[100];
    printf("监听中.......\n");
    int fd = accept(sid,NULL,NULL);
        if(fd==-1){
            close(fd);
            perror("");
            return;
        }
    while (1)
    {
        printf("有用户%s连接，您想说写什么：",client.sa_data);
        fgets(buf,100,stdin);
        int len = write(fd,buf,100);
        printf("发送%d字节",len);
    }
    
    close(sid);
}