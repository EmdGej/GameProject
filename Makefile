all: main
	./sfml-app

main: main.o Animation.o AnimationManager.o Player.o AnimationLoader.o MapLoader.o Bullet.o
	g++ -L/lib main.o Animation.o AnimationManager.o Player.o AnimationLoader.o MapLoader.o Bullet.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp -I /include

Bullet.o: Bullet.cpp Bullet.hpp
	g++ -c Bullet.cpp -I /include

MapLoader.o: MapLoader.cpp MapLoader.hpp
	g++ -c MapLoader.cpp -I /include

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

