# CXX = g++
CXXFLAGS = -std=c++11 -W -Wall -Wno-sign-compare -c -I.  
CPP_FILES = main-nogui.cpp AI.cpp Card.cpp Deck.cpp\
 Game.cpp Human.cpp Player.cpp Team.cpp Trick.cpp\
 Beginner.cpp getInt.cpp getChar.cpp
OBJ = $(patsubst %.cpp,%.o,$(CPP_FILES))
EXEC = tarot

all: CXXFLAGS += -O2 -DNDEBUG
all: $(EXEC)

debug: CXXFLAGS += -g -DDEBUG
debug: $(EXEC)

$(EXEC): $(OBJ)
	cd ../obj/ ; $(CXX) $^ -o ../bin/$@

main-nogui.o: Announcements.hpp AI.hpp Biddings.hpp\
 Card.hpp Suits.hpp Deck.hpp Game.hpp\
 Human.hpp Player.hpp StratLang.hpp\
 Team.hpp Trick.hpp getInt.hpp\
 getChar.hpp

Game.o: AI.hpp Biddings.hpp Card.hpp\
 Suits.hpp Deck.hpp Game.hpp\
 Human.hpp Player.hpp StratLang.hpp\
 Team.hpp Trick.hpp

AI.o: AI.hpp Card.hpp Suits.hpp\
 Deck.hpp Player.hpp StratDiff.hpp\
 Beginner.hpp Biddings.hpp

Beginner.o: Beginner.hpp Biddings.hpp\
 Card.hpp StratDiff.hpp

getInt.o: getInt.hpp
getChar.o: getChar.hpp
Card.o: Card.hpp Suits.hpp
Deck.o: Card.hpp Deck.hpp
Human.o: Card.hpp Suits.hpp\
 Human.hpp Player.hpp getInt.hpp\
 getChar.hpp

Player.o: Card.hpp Player.hpp\
 Announcements.hpp Suits.hpp Biddings.hpp 
StratLang.o: StratLang.hpp
StratDiff.o: StratDiff.hpp Card.hpp\
 Biddings.hpp 
Team.o: Player.hpp Team.hpp
Trick.o: Card.hpp Player.hpp Trick.hpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o ../obj/$@

.PHONY: clean

clean:
	rm -f ../obj/*.o *~ core ../bin/$(EXEC)
