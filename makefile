all: main.o ExpertSystem.o
	g++ -std=c++11 main.o ExpertSystem.o

main.o: main.cpp ExpertSystem.h
	g++ -std=c++11 -c main.cpp

ExpertSystem.o: ExpertSystem.h ExpertSystem.cpp
	g++ -std=c++11 -c ExpertSystem.cpp
