FLAGS = -pedantic-errors -std=c++11
newcharacter.o: newcharacter.cpp functions.h
	g++ $(FLAGS) -c $<
readsavefile.o: readsavefile.cpp functions.h
	g++ $(FLAGS) -c $<
game.o: game.cpp functions.h
	g++ $(FLAGS) -c $<
game: game.o newcharacter.o readsavefile.o 
	g++ $(FLAGS) $^ -o $@