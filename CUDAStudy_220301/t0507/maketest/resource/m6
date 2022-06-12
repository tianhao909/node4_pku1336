# hello: *.o
# 	gcc *.o -o hello
# *.o : *.c
# 	gcc *.c -C -o *.o 
#ALL:hello

ALL=a.out
inc = -I /home/work/fth/CUDAStudy_220301/t0507/maketest/resource/inc
src = $(wildcard /home/work/fth/CUDAStudy_220301/t0507/maketest/resource/src/*.c)
obj = $(patsubst %.c, %.o, $(src))
#obj = $(patsubst ./src/%.c, ./obj/%.o, $(src))

myArgs = -Wall -g 

$(ALL):$(obj) 
	gcc $^ -o $@ $(myArgs) 
#	gcc $^ -o $@ $(myArgs) $(inc)

%.o:%.c 
	gcc -c $< -o $@ $(myArgs) $(inc)
#	gcc -c $< -o $@ $(myArgs) $(inc)

clean: 
	-rm $(obj) $(ALL) 

.PHONY: clean $(ALL) 


#	gcc -c $^ -o $@
#	 -rm *.o a.out

#$(obj):%.o:%.c 
# hello.o: hello.c
# 	gcc -c $< -o $@
# add.o : add.c
# 	gcc -c $< -o $@
# sub.o : sub.c 
# 	gcc -c $< -o $@
# div1.o : div1.c 
# 	gcc -c $< -o $@ 


#rm *.o hello
# src = $(wildcard *.c)
# obj = $(patsubst %.c, %.o, $(src))
#HELLO_O=hello.o add.o sub.o div1.o
#HELLO_C=hello.c add.c sub.c div1.c


#hello: hello.o add.o sub.o div1.o
# hello: $(HELLO_O)
# 	gcc $^ -o hello

# $(HELLO_O): $(HELLO_C)
# 	gcc -c $^ -o $@

# hello.o: hello.c
# 	gcc -c hello.c -o hello.o
# add.o : add.c
# 	gcc -c add.c -o add.o
# sub.o : sub.c 
# 	gcc -c sub.c -o sub.o 
# div1.o : div1.c 
# 	gcc -c div1.c -o div1.o 
