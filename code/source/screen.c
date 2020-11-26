#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
void show_screen_dimention(){
    struct winsize wbuf;
    if(ioctl(0,TIOCGWINSZ,&wbuf)!=-1){
        printf("%d rows\n",wbuf.ws_row);
        printf("%d cols\n",wbuf.ws_col);
    }
    

}
