#PROJETO EDB1

PROG = Driver
CC = g++
CPPFLAGS = -O0 -g -W -Wall -std=c++11 -pedantic
OBJS = Driver.o
HEADER = ./includes/list.h
SRC_DIR     = ./src/
BIN_DIR     = ./bin/

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o $(PROG) $(BIN_DIR)

Driver.o: $(HEADER)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)Driver.cpp
clean:
	rm -f $(PROG) 
