all: main
	./sfml-app

main: main.o Animation.o AnimationManager.o
	g++ main.o Animation.o AnimationManager.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp AbstractEntity.hpp
	g++ -c main.cpp -I /include

AnimationManager.o: AnimationManager.cpp AnimationManager.hpp
	g++ -c AnimationManager.cpp -I /include

Animation.o: Animation.cpp Animation.hpp
	g++ -c Animation.cpp -I /include

clear:
	rm sfml-app
	rm *.o

