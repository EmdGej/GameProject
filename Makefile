all: main
	./sfml-app

main: main.o Animation.o AnimationManager.o Player.o AnimationLoader.o MapLoader.o Bullet.o BulletManager.o Enemy.o CollisionManager.o EnemyManager.o ControlManager.o Map.o Game.o 
	g++ -std=c++17 -L $(pwd)/SFML/lib main.o Animation.o AnimationManager.o Player.o AnimationLoader.o MapLoader.o Bullet.o BulletManager.o Enemy.o CollisionManager.o EnemyManager.o ControlManager.o Map.o Game.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -std=c++17 -c main.cpp -I $(pwd)/SFML/include

Game.o: Game/Game.cpp Game/Game.hpp
	g++ -std=c++17 -c Game/Game.cpp -I $(pwd)/SFML/include

Map.o: Map/Map.cpp Map/Map.hpp
	g++ -std=c++17 -c Map/Map.cpp -I $(pwd)/SFML/include

ControlManager.o: ControlManager/ControlManager.cpp ControlManager/ControlManager.hpp
	g++ -std=c++17 -c ControlManager/ControlManager.cpp -I $(pwd)/SFML/include

EnemyManager.o: EnemyManager/EnemyManager.cpp EnemyManager/EnemyManager.hpp
	g++ -std=c++17 -c EnemyManager/EnemyManager.cpp -I $(pwd)/SFML/include

CollisionManager.o: CollisionManager/CollisionManager.cpp CollisionManager/CollisionManager.hpp
	g++ -std=c++17 -c CollisionManager/CollisionManager.cpp -I $(pwd)/SFML/include

Enemy.o: Enemy/Enemy.cpp Enemy/Enemy.hpp
	g++ -std=c++17 -c Enemy/Enemy.cpp -I $(pwd)/SFML/include

BulletManager.o: BulletManager/BulletManager.cpp BulletManager/BulletManager.hpp
	g++ -std=c++17 -c BulletManager/BulletManager.cpp -I $(pwd)/SFML/include

Bullet.o: Bullet/Bullet.cpp Bullet/Bullet.hpp
	g++ -std=c++17 -c Bullet/Bullet.cpp -I $(pwd)/SFML/include

MapLoader.o: MapLoader/MapLoader.cpp MapLoader/MapLoader.hpp
	g++ -std=c++17 -c MapLoader/MapLoader.cpp -I $(pwd)/SFML/include

Player.o: Player/Player.cpp Player/Player.hpp
	g++ -std=c++17 -c Player/Player.cpp -I $(pwd)/SFML/include

AnimationLoader.o: AnimationLoader/AnimationLoader.cpp AnimationLoader/AnimationLoader.hpp
	g++ -std=c++17 -c AnimationLoader/AnimationLoader.cpp -I $(pwd)/SFML/include

AnimationManager.o: AnimationManager/AnimationManager.cpp AnimationManager/AnimationManager.hpp
	g++ -std=c++17 -c AnimationManager/AnimationManager.cpp -I $(pwd)/SFML/include

Animation.o: Animation/Animation.cpp Animation/Animation.hpp
	g++ -std=c++17 -c Animation/Animation.cpp -I $(pwd)/SFML/include

clear:
	rm main.o Animation.o AnimationManager.o Player.o AnimationLoader.o MapLoader.o Bullet.o BulletManager.o Enemy.o CollisionManager.o EnemyManager.o ControlManager.o Game.o
	rm *.o
	rm sfml-app