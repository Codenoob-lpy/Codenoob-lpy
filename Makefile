FLAGS = -pedantic-errors -std=c++11
welcome.o: welcome.cpp functions.h
	g++ $(FLAGS) -c $<
newcharacter.o: newcharacter.cpp functions.h
	g++ $(FLAGS) -c $<
readsavefile.o: readsavefile.cpp functions.h
	g++ $(FLAGS) -c $<
savegame.o: savegame.cpp functions.h
	g++ $(FLAGS) -c $<
RNG.o: RNG.cpp functions.h
	g++ $(FLAGS) -c $<
monster_sponsor.o: monster_sponsor.cpp functions.h
	g++ $(FLAGS) -c $<
randomweapon.o: randomweapon.cpp functions.h
	g++ $(FLAGS) -c $<
randomarmor.o: randomarmor.cpp functions.h
	g++ $(FLAGS) -c $<
event.o: event.cpp functions.h
	g++ $(FLAGS) -c $<
genericinput.o: genericinput.cpp functions.h
	g++ $(FLAGS) -c $<
status.o: status.cpp functions.h
	g++ $(FLAGS) -c $<
game.o: game.cpp functions.h
	g++ $(FLAGS) -c $<
game: game.o welcome.o newcharacter.o readsavefile.o savegame.o RNG.o monster_sponsor.o randomweapon.o randomarmor.o event.o genericinput.o status.o
	g++ $(FLAGS) $^ -o $@