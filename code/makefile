INCLUDEDIR=./head/
BIN=./bin/
GCC=gcc -w
OBJ=main.o more.o who.o cp.o ls.o pwd.o
vpath %.c ./source/
vpath %.o ./bin/
debug:$(OBJ) 
	$(GCC)  -I $(INCLUDEDIR) -g $(addprefix $(BIN),$^) -o $(BIN)$@
$(OBJ):%.o:%.c
	@$(GCC) -I $(INCLUDEDIR) -c -g $^ -o $(BIN)$@
clean:
	rm ./bin/*

