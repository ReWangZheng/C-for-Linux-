#include <stdio.h>
#include <sys/types.h>
#include "mpwd.h"
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
ino_t getinode(char * filename){
    struct stat s;
    int flag = stat(filename,&s); 
    if(flag == -1){
        perror("");
        exit(1);
    }
    return s.st_ino;
}
void pwd(){
    ino_t init_inode = getinode(".");
    chdir("..");
    ino_t inode_p = getinode(".");
    if(init_inode == inode_p){
        return;
    }
    DIR * dir = opendir(".");
    if(dir==NULL){
        perror("");
        exit(1);
    }
    struct dirent *dir_entry;
    while ((dir_entry = readdir(dir))!=NULL)
    {
        if(dir_entry->d_ino == init_inode){
            break;
        }
    }
    if(dir_entry==NULL){
        perror("");
        exit(1);
    }
    pwd();
    printf("/%s",dir_entry->d_name);
    
}
