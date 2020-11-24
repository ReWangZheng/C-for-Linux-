INCLUDEDIR=./head/
BIN=./bin/
GCC=gcc
OBJ=main.o more.o who.o cp.o
vpath %.c ./source/
vpath %.o ./bin/
debug:$(OBJ) 
	$(GCC)  -I $(INCLUDEDIR) -g $(addprefix $(BIN),$^) -o $(BIN)$@
$(OBJ):%.o:%.c
	@$(GCC) -I $(INCLUDEDIR) -c -g $^ -o $(BIN)$@
clean:
	rm ./bin/*

