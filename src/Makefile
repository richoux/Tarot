CXX = g++
CXXFLAGS = -std=c++11 -O3 -W -Wall -I../include -c 
CPP_FILES = main.cpp AI.cpp Card.cpp Deck.cpp\
 Game.cpp Human.cpp Player.cpp Team.cpp Trick.cpp\
 Beginner.cpp getInt.cpp 
OBJ = $(patsubst %.cpp,%.o,$(CPP_FILES))
EXEC = tarot

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $^ -o ../$@
	rm -f *.o

main.o: ../include/AI.hpp ../include/Biddings.hpp ../include/Card.hpp\
 ../include/Suits.hpp ../include/Deck.hpp ../include/Game.hpp\
 ../include/Human.hpp ../include/Player.hpp ../include/StratLang.hpp\
 ../include/Team.hpp ../include/Trick.hpp ../include/getInt.hpp

Game.o: ../include/AI.hpp ../include/Biddings.hpp ../include/Card.hpp\
 ../include/Suits.hpp ../include/Deck.hpp ../include/Game.hpp\
 ../include/Human.hpp ../include/Player.hpp ../include/StratLang.hpp\
 ../include/Team.hpp ../include/Trick.hpp

AI.o: ../include/AI.hpp ../include/Card.hpp ../include/Suits.hpp\
 ../include/Deck.hpp ../include/Player.hpp ../include/StratDiff.hpp\
 ../include/Beginner.hpp

Beginner.o: ../include/Beginner.hpp ../include/Card.hpp\
 ../include/StratDiff.hpp

getInt.o: ../include/getInt.hpp
Card.o: ../include/Card.hpp ../include/Suits.hpp
Deck.o: ../include/Card.hpp ../include/Deck.hpp
Human.o: ../include/Card.hpp ../include/Suits.hpp\
 ../include/Human.hpp ../include/Player.hpp ../include/getInt.hpp

Player.o: ../include/Card.hpp ../include/Player.hpp
StratLang.o: ../include/StratLang.hpp
Team.o: ../include/Player.hpp ../include/Team.hpp
Trick.o: ../include/Card.hpp ../include/Player.hpp ../include/Trick.hpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f *.o *~ core ../include/*~ ../$(EXEC)
