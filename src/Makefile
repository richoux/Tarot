CXX = g++
CXXFLAGS = -std=c++11 -O3 -W -Wall -I../include -c 
CPP_FILES = main.cpp AI.cpp Card.cpp Deck.cpp\
 Game.cpp Human.cpp Player.cpp Team.cpp Trick.cpp
OBJ = $(patsubst %.cpp,%.o,$(CPP_FILES))
EXEC = tarot

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $^ -o ../$@
	rm -f *.o

main.o: ../include/AI.hpp ../include/Biddings.hpp ../include/Card.hpp\
 ../include/Colors.hpp ../include/Deck.hpp ../include/Game.hpp\
 ../include/Human.hpp ../include/Player.hpp ../include/StratLang.hpp\
 ../include/Team.hpp ../include/Trick.hpp

Game.o: ../include/AI.hpp ../include/Biddings.hpp ../include/Card.hpp\
 ../include/Colors.hpp ../include/Deck.hpp ../include/Game.hpp\
 ../include/Human.hpp ../include/Player.hpp ../include/StratLang.hpp\
 ../include/Team.hpp ../include/Trick.hpp

AI.o: ../include/AI.hpp ../include/Card.hpp ../include/Colors.hpp\
 ../include/Deck.hpp ../include/Player.hpp

Card.o: ../include/Card.hpp ../include/Colors.hpp
Deck.o: ../include/Card.hpp ../include/Deck.hpp
Human.o: ../include/Card.hpp ../include/Colors.hpp\
 ../include/Human.hpp ../include/Player.hpp

Player.o: ../include/Card.hpp ../include/Player.hpp
StratLang.o: ../include/StratLang.hpp
Team.o: ../include/Player.hpp ../include/Team.hpp
Trick.o: ../include/Card.hpp ../include/Player.hpp ../include/Trick.hpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f *.o *~ core ../include/*~ ../$(EXEC)