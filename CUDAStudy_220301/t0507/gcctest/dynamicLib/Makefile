	gcc -c *.c -o *.o
gcc -c add.c sub.c div1.c -o add.o sub.o div1.o
gcc -c add.c -o add.o
gcc -c sub.c -o sub.o
gcc -c div1.c -o div1.o
ar rcs libmymath.a *.o
file libmymath.a 
gcc test.c libmymath2.a -o test
gcc test.c libmymath.a -o test
clean:
	rm *.o