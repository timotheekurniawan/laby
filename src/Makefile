main: main.o welcome.o play.o
	g++ $^ -o $@

main.o: main.cpp welcome.h play.h userStruct.h
	g++ -c $<

welcome.o: welcome.cpp levels.h userStruct.h
	g++ -c $<

play.o: play.cpp userStruct.h laby.h levels.h congrats.h
	g++ -c $<

levels.o: levels.cpp levels.h
	g++ -c $<


