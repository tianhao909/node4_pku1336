C_SRC = $(wildcard ./src/*.c)
C_OBJ = $(patsubst %c, %o, $(C_SRC))
I_DIR = -I ./include 
L_DIR = -L ./lib 
C_BIN = ./bin/main
C_CLEAN = clean

#$(C_BIN)  : $(C_SRC)
$(C_BIN)  : $(C_SRC)
	$(CC) $(C_SRC) -o $(C_BIN) $(I_DIR) $(L_DIR) -lm
#	$(CC) $^ -o $@ $(I_DIR) $(L_DIR) -lm
# cc  -o bin/main -I ./include  -L ./lib  -lm
# $(C_BIN)  : $(C_OBJ)
# 	$(CC) $(C_OBJ) -o $(C_BIN) $(I_DIR) $(L_DIR) -lm
#	$(CC) $^ -o $@ $(I_DIR) $(L_DIR) -lm
#	$(CC) $(C_SRC) -o $(C_OBJ) $(I_DIR) $(L_DIR) -lm

#$(C_OBJ) : $(C_SRC)
#	$(CC) $(C_SRC) -c $(C_OBJ) $(I_DIR) $(L_DIR) -lm
#$(C_BIN) : $(C_SRC) 
#	$(CC) $^ -o $@ $(I_DIR) $(L_DIR) -lm

.PHONY:$(C_CLEAN)
$(C_CLEAN):
	$(RM) $(C_BIN) $(C_OBJ)