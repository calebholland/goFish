final: go_fish.o card.o deck.o player.o
	g++ -std=c++11 -o gofish go_fish.o card.o deck.o player.o
driver: go_fish.cpp card.h
	g++ -o go_fish.o -c -std=c++11 go_fish.cpp
card.o: card.cpp card.h
	g++ -o card.o -c -std=c++11 card.cpp
deck.o: deck.cpp deck.h
	g++ -o deck.o -c -std=c++11 deck.cpp
player.o: player.cpp player.h
	g++ -o player.o -c -std=c++11 player.cpp
