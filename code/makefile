# 首先进行判断等待编译的目标是否存在
#ifndef filename
#	filename=main
#endif
# 如果存在则将.c去掉
#object=$(patsubst %.c,%,$(filename))
#$(object): *.o
#	echo $^
#	gcc  -g $^ -o $@
vpath %.c ../code/source/
vpath %.h ../code/head/
cf=$(notdir $(wildcard ../code/source/*.c))
df=$(cf:.c=.d)
of=$(cf:.c=.o)
debug.bin:$(df)
	@make -f Makefile

$(df):%.d:%.c
	@gcc -MM $< > $@

clean:
	rm *.bin *.o