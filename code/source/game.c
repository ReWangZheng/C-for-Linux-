#include <stdio.h>
#include <curses.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#define LEFT_MARGIN 0
#define RIGHT_MARGIN 5
#define TOP_MARGIN 0
#define BOTTOM_MARGIN 20
void wakeup(){
    printf("闹钟\n");
}
void set_ticker(){
    struct itimerval tims;
    tims.it_interval.tv_sec = 1; //间隔
    tims.it_interval.tv_usec = 0;
    tims.it_value.tv_sec = 1; //初始要等待的时间
    tims.it_value.tv_usec =0;
    setitimer(ITIMER_REAL,&tims,NULL); //设置时间
}

void game_start(){
    signal(SIGALRM,wakeup);
    set_ticker();
    while (1)
    {
        pause();
    }
}