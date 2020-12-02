#include "summary.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
void start_client(){
    //第一步，打开一个socket
    int sid = socket(PF_INET,SOCK_STREAM,0);
    struct sockaddr_in saddr;
    saddr.sin_port = htons(12345);
    saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    saddr.sin_family = AF_INET;
    //连接
    printf("正在连接中！");
    int state = connect(sid,(struct sockaddr *)(&saddr),sizeof(struct sockaddr_in));
    if(state==0){
        printf("连接成功!");
    }else{
        perror("连接失败");
        return;
    }
    char buf[30];
    while (1)
    {
        int len = read(sid,buf,30);
        if(len>0){
            printf("来自客户端的消息:%s",buf);
        }
        
    }
    

    close(sid);
}