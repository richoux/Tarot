CC = g++
INCLUDE = -I./include
CFLAGS = -std=c++11 -O3 #-W -Wall
SRC = src/*.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = tarot

all: $(EXEC)
	rm -f src/*.o

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $< -o $@

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(INCLUDE) -c $^

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: clean

clean:
	rm -f *.o *~ src/*~ core include/*~
