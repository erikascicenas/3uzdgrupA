main.out: main.cpp resources.cpp resources.h
	@g++ -g -o main.out main.cpp resources.cpp -lpthread -Wall -Wpedantic && ./main.out
