INCLUDEDIR=./head/
BIN=./bin/
GCC=gcc
GCCFLAG=-w
OBJ=main.o more.o who.o cp.o ls.o pwd.o write.o screen.o\
sigdemo.o stty.o game.o shell.o usepipe.o mybc.o
vpath %.c ./source/
vpath %.o ./bin/
#
debug:$(OBJ) 
	$(GCC)  $(GCCFLAG) -I $(INCLUDEDIR) -g $(addprefix $(BIN),$^)   -o  $(BIN)$@ -lcurses

$(OBJ):%.o:%.c
	@$(GCC) $(GCCFLAG) -I $(INCLUDEDIR) -c -g $^ -o $(BIN)$@ 

clean:
	rm ./bin/*

