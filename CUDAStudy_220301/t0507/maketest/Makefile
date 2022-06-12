hello : hello.o
	gcc hello.o -o hello
hello.o	: gdbtest.c
	gcc gdbtest.c -c -o hello.o

clean:
	rm hello hello.o