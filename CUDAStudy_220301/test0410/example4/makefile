CC = gcc
CFLAGS = -lm -Wall -g

main: main.c foo.o bar.o
	#gcc main.c foo.o bar.o -o main
	$(CC) $(CFLAGS) main.c foo.o bar.o -o main
foo.o: foo.c
	$(CC) $(CFLAGE) -c foo.c
	#gcc -c foo.c
bar.o: bar.c
	$(CC) $(CFLAGS) -c bar.c
	#gcc -c bar.c
clean:
	rm *.o main
