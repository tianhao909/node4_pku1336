	gcc -c *.c -o *.o
gcc -c add.c sub.c div1.c -o add.o sub.o div1.o
gcc -c add.c -o add.o
gcc -c sub.c -o sub.o
gcc -c div1.c -o div1.o
ar rcs libmymath.a *.o
file libmymath.a 
gcc test.c libmymath2.a -o test
gcc test.c libmymath.a -o test

gcc -c add.c -o add.o -fPIC
gcc -c sub.c -o sub.o -fPIC
gcc -c div1.c -o div1.o -fPIC

/home/work/fth/CUDAStudy_220301/test0501/test0503/addsf/t0507/gcctest/dynamicLib/lib
gcc -shared -o libmymath3.so *.o 
 gcc test.c -o test -l mymath3 -L ./resource/ -I ./inc/ 
export LD_LIBRARY_PATH=./resource
clean:
	rm *.o