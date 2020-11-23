#include "who.h"
#include <stdio.h>
#include <time.h>
typedef struct utmp utmp;
void who(){
    utmp user;
    int fd = 0;
    if(( fd = open(UTMP_FILE,O_RDONLY))==-1){
        perror(UTMP_FILE);
        exit(1);
    }
    int utmp_size = sizeof(user);
    while(read(fd,&user,utmp_size)==utmp_size){
        show(&user);
    }

    close(fd);
}

void show(utmp *user){
    printf("%-8.8s",user->ut_user);
    printf("%-8.8s",user->ut_line);
    printf("%-12s",ctime(&user->ut_tv));
}