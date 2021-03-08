CFLAGS=-O3 -std=c++11

expertsystem: main.o ExpertSystem.o
g++ $(CFLAGS) main.o ExpertSystem.o -o expertsystem

main.o: ExpertSystem.h main.cpp
	g++ $(CFLAGS) -c main main.cpp

ExpertSystem.o: ExpertSystem.h ExpertSystem.cpp
	g++ $(CFLAGS) -c expertsystem ExpertSystem.cpp
