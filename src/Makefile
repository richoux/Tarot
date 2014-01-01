CXX = g++
CXXFLAGS = -std=c++11 -O3 -W -Wall -Wno-sign-compare -I../include -c 
CPP_FILES = main.cpp AI.cpp Card.cpp Deck.cpp\
 Game.cpp Human.cpp Player.cpp Team.cpp Trick.cpp\
 Beginner.cpp getInt.cpp getChar.cpp
OBJ = $(patsubst %.cpp,%.o,$(CPP_FILES))
EXEC = tarot

all: CXXFLAGS += -DNDEBUG
all: $(EXEC)

debug: CXXFLAGS += -g
debug: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $^ -o ../bin/$@
	rm -f *.o

main.o: ../include/Announcements.hpp ../include/AI.hpp ../include/Biddings.hpp\
 ../include/Card.hpp ../include/Suits.hpp ../include/Deck.hpp ../include/Game.hpp\
 ../include/Human.hpp ../include/Player.hpp ../include/StratLang.hpp\
 ../include/Team.hpp ../include/Trick.hpp ../include/getInt.hpp\
 ../include/getChar.hpp

Game.o: ../include/AI.hpp ../include/Biddings.hpp ../include/Card.hpp\
 ../include/Suits.hpp ../include/Deck.hpp ../include/Game.hpp\
 ../include/Human.hpp ../include/Player.hpp ../include/StratLang.hpp\
 ../include/Team.hpp ../include/Trick.hpp

AI.o: ../include/AI.hpp ../include/Card.hpp ../include/Suits.hpp\
 ../include/Deck.hpp ../include/Player.hpp ../include/StratDiff.hpp\
 ../include/Beginner.hpp ../include/Biddings.hpp

Beginner.o: ../include/Beginner.hpp ../include/Biddings.hpp\
 ../include/Card.hpp ../include/StratDiff.hpp

getInt.o: ../include/getInt.hpp
getChar.o: ../include/getChar.hpp
Card.o: ../include/Card.hpp ../include/Suits.hpp
Deck.o: ../include/Card.hpp ../include/Deck.hpp
Human.o: ../include/Card.hpp ../include/Suits.hpp\
 ../include/Human.hpp ../include/Player.hpp ../include/getInt.hpp\
 ../include/getChar.hpp

Player.o: ../include/Card.hpp ../include/Player.hpp\
 ../include/Announcements.hpp ../include/Suits.hpp ../include/Biddings.hpp 
StratLang.o: ../include/StratLang.hpp
StratDiff.o: ../include/StratDiff.hpp ../include/Card.hpp\
 ../include/Biddings.hpp 
Team.o: ../include/Player.hpp ../include/Team.hpp
Trick.o: ../include/Card.hpp ../include/Player.hpp ../include/Trick.hpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f *.o *~ core ../include/*~ ../bin/$(EXEC)
