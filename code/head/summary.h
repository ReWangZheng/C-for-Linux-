#pragma once
#include "cp.h"
#include "ls.h"
#include "more.h"
#include "mpwd.h"
#include "summary.h"
#include "who.h"
void cwrite(char * filename);
void show_screen_dimention();
void sigdemotest();
void stty();
void game_start();
void shell();
void usepipe();
void bc();
FILE* mypopen();
void start_server();
void start_client();