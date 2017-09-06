TARGET =tests
BIN = bin
SRC = src
OBJ = obj
CC = g++
OBJS += test_test.o 
OBJS += ../coordinates.o

INC += ../include

$(BIN)/$(TARGET): $(OBJ)/$(OBJS)
	$(CC) -o $@ -Wall -I$(INC) $^ libs/libgtest.a 

$(OBJ)/%.o : %.cpp
	$(CC) -Wall -I $(INC) -c $< -o $@ 

.PHONY: clean
clean:
	rm -f $(OBJ)/*.o $(BIN)/*

.PHONY: init
init:
	mkdir bin obj include src

