FLAGS = -pedantic-errors -std=c++11
welcome.o: welcome.cpp functions.h
	g++ $(FLAGS) -c $<
newcharacter.o: newcharacter.cpp functions.h
	g++ $(FLAGS) -c $<
readsavefile.o: readsavefile.cpp functions.h
	g++ $(FLAGS) -c $<
savegame.o: savegame.cpp functions.h
	g++ $(FLAGS) -c $<
game.o: game.cpp functions.h
	g++ $(FLAGS) -c $<
game: game.o welcome.o newcharacter.o readsavefile.o savegame.o
	g++ $(FLAGS) $^ -o $@