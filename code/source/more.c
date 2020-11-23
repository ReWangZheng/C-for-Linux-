#define LINE_LENTH 512
#define ROW_LENGTH 5
#include "more.h"
void do_more(FILE *f){
    char line[LINE_LENTH];
    int row = 0;
    int reply=0;
    while (fgets(line,LINE_LENTH,f))
    {
        if(row==ROW_LENGTH){
            reply = see_more();
            if(reply==0){
                break;
            }
            row-=reply;
        }else{
            printf("%s\n",line);
            row++;
        }
        
    }

}
int see_more(){
    int res;
    int c;
    printf("quit or more?[q or m]:");
    while ((c=getchar())!=EOF)
    {
        if(c=='q'){
            return 0;
        }else if (c=='m'){
            return ROW_LENGTH;
        }else if(c=='j'){
            return 1;
        }
    }
    return 0;
}