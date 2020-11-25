#include "ls.h"
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
typedef struct dirent dirent;
char * getFilePermission(char * str,mode_t mode){
    if(S_ISDIR(mode)){
        str[0] = 'd';
    }else if(S_ISREG(mode)){
        str[0] = '-';
    }
    if(S_IRUSR&mode) str[1] = 'r';
    if(S_IWUSR&mode) str[2] = 'w';
    if(S_IXUSR&mode) str[3] = 'x';
    if(S_IRGRP&mode) str[4] = 'r';
    if(S_IWGRP&mode) str[5] = 'w';
    if(S_IXGRP&mode) str[6] = 'x';
    if(S_IROTH&mode) str[7] = 'r';
    if(S_IWOTH&mode) str[8] = 'w';
    if(S_IXOTH&mode) str[9] = 'x';
    str[10] = 0;
}
void ls(char * dir_name){
    DIR * dir = opendir(dir_name);
    dirent* dir_mes;
    while ((dir_mes=readdir(dir))!=NULL)
    {
        struct stat s;
        char mode[30];
        stat(dir_mes->d_name,&s);
        struct passwd *p  = getpwuid(s.st_uid);
        struct group * g = getgrgid(p->pw_gid);
        getFilePermission(mode,s.st_mode);
        printf("%12s",mode);
        printf("%-8s %-8s",p->pw_name,g->gr_name);
        printf("%-8.5s",dir_mes->d_name);
        printf("%-8d",s.st_size);
        printf("%-8.16s \n",ctime(&s.st_ctim));
    }
    closedir(dir);
}

