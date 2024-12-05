TARGET = server 
OBJ = main.o
CC := gcc
CFLAGS = -g -ggdb -llua5.1 -ldl -lm -Wall


# 格式：
# 目标文件 : 依赖文件
#   指令
#
# 说明：第一个目标文件就我的最终目标。递归执行子目标
# $(TARGET):$(OBJ)
# # $^: 表示依赖项;   $@：表示目标项
# 	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

mylib.so:
	gcc -O2 -shared -lm -fPIC mylib.c -o mylib.so

server: main.o
	$(CC) -o $@ $^ $(CFLAGS)

# 伪目标: .PHONY: 只没有依赖文件的目标
.PHONY:
	make mylib.so
clean:
	rm -rf $(TARGET) $(OBJ)  *.o *.so
