CXX = g++
CXXFLAGS = -std=c++17 -g -Wall

SRC = '.'
EXEC = main

OBJ = Card.cpp PointCard.cpp ActionCard.cpp Deck.cpp Hand.cpp Player.cpp main.cpp

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(SRC)/$@ $(OBJ)


clean:
	rm -rf $(EXEC)

rebuild: clean all