FLAGS = -pedantic-errors -std=c++11

main: main.o welcome.o play.o levels.o laby.o congrats.o invalidSelection.o
		g++ $(FLAGS) $^ -o $@

main.o: main.cpp welcome.h play.h userStruct.h
		g++ $(FLAGS) -c $<

welcome.o: welcome.cpp welcome.h levels.h userStruct.h invalidSelection.h
		g++ $(FLAGS) -c $<

play.o: play.cpp play.h userStruct.h laby.h levels.h congrats.h invalidSelection.h
		g++ $(FLAGS) -c $<

laby.o: laby.cpp laby.h userStruct.h levels.h invalidSelection.h
		g++ $(FLAGS) -c $<

levels.o: levels.cpp levels.h
		g++ $(FLAGS) -c $<

congrats.o: congrats.cpp congrats.h userStruct.h levels.h play.h invalidSelection.h
		g++ $(FLAGS) -c $<

invalidSelection.o: invalidSelection.cpp invalidSelection.h
		g++ $(FLAGS) -c $<

clean:
		rm -f *.o

.PHONY: clean 