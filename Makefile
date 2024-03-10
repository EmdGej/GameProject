all: main
	./sfml-app

main: main.o Animation.o AnimationManager.o Player.o AnimationLoader.o
	g++ -L/lib main.o Animation.o AnimationManager.o Player.o AnimationLoader.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp AbstractEntity.hpp 
	g++ -c main.cpp -I /include

AnimationLoader.o: AnimationLoader.cpp AnimationLoader.hpp
	g++ -c AnimationLoader.cpp -I /include

Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp -I /include

AnimationManager.o: AnimationManager.cpp AnimationManager.hpp
	g++ -c AnimationManager.cpp -I /include

Animation.o: Animation.cpp Animation.hpp
	g++ -c Animation.cpp -I /include

clear:
	rm *.o
	rm sfml-app
	 

