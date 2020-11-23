vpath %.c ./source/
vpath %.o ./bin/
INCLUDEDIR=./head/
BIN=./bin/
GCC=gcc
OBJ=main.o more.o who.o
debug:$(OBJ) 
	$(GCC)  -I $(INCLUDEDIR) -g $^ -o $(BIN)$@
	@./bin/debug
%.o:%.c
	@$(GCC) -I $(INCLUDEDIR) -c -g $^ -o $(BIN)$@
clean:
