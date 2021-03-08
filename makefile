all: Project1-ID-main.o Project1-ID-ExpertSystem.o
	g++ -std=c++11 Project1-ID-main.o Project1-ID-ExpertSystem.o

Project1-ID-main.o: Project1-ID-main.cpp ExpertSystem.h
	g++ -std=c++11 -c Project1-ID-main.cpp

Project1-<ID>-ExpertSystem.o: ExpertSystem.h Project1-ID-ExpertSystem.cpp
	g++ -std=c++11 -c Project1-ID-ExpertSystem.cpp
