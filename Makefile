all: main
	./sfml-app

main: main.o
	g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp -I /include

clear:
	rm sfml-app
	rm main.o

