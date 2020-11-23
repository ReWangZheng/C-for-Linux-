#ifndef MYWHO
#define MYWHO
#include <fcntl.h> // open函数在该头中
#include <unistd.h> //read函数在该头中
#include <utmp.h> //user信息定义在该文件夹中
void who();
#endif