

CC = g++

C++FLAG = -g -std=c++11

MATH_LIBS = -lm

EXEC_DIR=.

.cc.o:
	$(CC) $(C++FLAG) $(INCLUDES) -c $< -o $@

INCLUDES= -I.

LIBS_ALL = -L/usr/lib -L/usr/local/lib




Cpp_OBJ = simulator.o cpu.o process.o readyQueue.o memoryMangement.o

PROGRAM_NAME = start

$(PROGRAM_NAME): $(Cpp_OBJ)
	$(CC) $(C++FLAG) -o $(EXEC_DIR)/$@ $(Cpp_OBJ) $(INCLUDES) $(LIBS_ALL)

all:
	make $(PROGRAM_NAME)

clean:
	(rm -f *.o; rm start)

(:
