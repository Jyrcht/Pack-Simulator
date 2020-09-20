OBJS = main.cpp cards.cpp pack.cpp

CC = g++

COMPILER_FLAGS = -Wall -g

OBJ_NAME = cards.exe

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)	