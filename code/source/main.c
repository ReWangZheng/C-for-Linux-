#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include "summary.h"
#include <time.h>
int main()
{
    int pid = fork();
    if(pid==0){
         start_server();
    }else{
        sleep(1);
        start_client();
   }
    
}
