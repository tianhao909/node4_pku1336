#C_SOURCE = max.h max.c main.c
C_SOURCE =  max.c main.c
C_TARGET = max
C_CLEAN = clean
C_OBJ = $(patsubst %c,%o,$(C_SOURCE))
#CC = arm-linux-gcc

#$(C_TARGET): $(C_SOURCE)
#max: max.h max.c main.c
#max : $(C_SOURCE)
#gcc $^ -o $@
#gcc $(C_SOURCE) -o $(C_TARGET)
#$(CC) $(C_SOURCE) -o $(C_TARGET)
$(C_TARGET): $(C_OBJ)
	gcc $^ -o $@

#clean:
.PHONY:$(C_CLEAN)
$(C_CLEAN):
#rm max
#$(RM) max
	$(RM) $(C_TARGET) $(C_OBJ)