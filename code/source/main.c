#include <stdio.h>
#include "summary.h"
typedef char u8;
int main(int size,char* args[]){
    char cn[10]="æÕ»’øÏ¿÷";
    u8 low = cn[0] - 0xa0; //Âå∫Á†Å
    u8 high = cn[1] - 0xa0; //‰ΩçÁ†Å
    int offset =  (94*(low-1)+high-1)*32;
    int fd = open("HZK16",O_RDONLY);
    if(fd==-1){
        perror("can't open file");
        return;
    }
    lseek(fd,offset,SEEK_SET);
    u8 buf[32];
    int len = read(fd,buf,32);
    if(len!=0){
        printf("read success %d! \n",len);
        for(int i =0;i<32;i++){
            if(i%2==0&&i!=0){
                printf("\n");
            }
            u8 w = buf[i];
            for(int j =0;j<8;j++){
                int k = (w)&(0x80>>j);
                if(k==0){
                    printf("  ",k);
                }else{
                    printf("* ",k);
                }
            }
        }
    }
    printf("\nres: %x %x",cn[0],cn[1]);
}