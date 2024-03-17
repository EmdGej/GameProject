all: main
	./sfml-app

main: main.o Animation/Animation.o AnimationManager/AnimationManager.o Player/Player.o AnimationLoader/AnimationLoader.o MapLoader/MapLoader.o Bullet/Bullet.o BulletManager/BulletManager.o Enemy/Enemy.o CollisionManager/CollisionManager.o  EnemyManager/EnemyManager.o ControlManager/ControlManager.o Map.o Game/Game.o 
	g++ -std=c++17 -L/lib main.o Animation/Animation.o AnimationManager/AnimationManager.o Player/Player.o AnimationLoader/AnimationLoader.o MapLoader/MapLoader.o Bullet/Bullet.o BulletManager/BulletManager.o Enemy/Enemy.o CollisionManager/CollisionManager.o  EnemyManager/EnemyManager.o ControlManager/ControlManager.o Map.o Game/Game.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -std=c++17 -c main.cpp -I /SFML/include

Game.o: Game/Game.cpp Game/Game.hpp
	g++ -std=c++17 -c Game/Game.cpp -I /SFML/include

Map.o: Map/Map.cpp Map/Map.hpp
	g++ -std=c++17 -c Map/Map.cpp -I /SFML/include

ControlManager.o: ControlManager/ControlManager.cpp ControlManager/ControlManager.hpp
	g++ -std=c++17 -c ControlManager/ControlManager.cpp -I /SFML/include

EnemyManager.o: EnemyManager/EnemyManager.cpp EnemyManager/EnemyManager.hpp
	g++ -std=c++17 -c EnemyManager/EnemyManager.cpp -I /SFML/include

CollisionManager.o: CollisionManager/CollisionManager.cpp CollisionManager/CollisionManager.hpp
	g++ -std=c++17 -c CollisionManager/CollisionManager.cpp -I /SFML/include

Enemy.o: Enemy/Enemy.cpp Enemy/Enemy.hpp
	g++ -std=c++17 -c Enemy/Enemy.cpp -I /SFML/include

BulletManager.o: BulletManager/BulletManager.cpp BulletManager/BulletManager.hpp
	g++ -std=c++17 -c BulletManager/BulletManager.cpp -I /SFML/include

Bullet.o: Bullet/Bullet.cpp Bullet/Bullet.hpp
	g++ -std=c++17 -c Bullet/Bullet.cpp -I /SFML/include

MapLoader.o: MapLoader/MapLoader.cpp MapLoader/MapLoader.hpp
	g++ -std=c++17 -c MapLoader/MapLoader.cpp -I /SFML/include

Player.o: Player/Player.cpp Player/Player.hpp
	g++ -std=c++17 -c Player/Player.cpp -I /SFML/include

AnimationLoader.o: AnimationLoader/AnimationLoader.cpp AnimationLoader/AnimationLoader.hpp
	g++ -std=c++17 -c AnimationLoader/AnimationLoader.cpp -I /SFML/include

AnimationManager.o: AnimationManager/AnimationManager.cpp AnimationManager/AnimationManager.hpp
	g++ -std=c++17 -c AnimationManager/AnimationManager.cpp -I /SFML/include

Animation.o: Animation/Animation.cpp Animation/Animation.hpp
	g++ -std=c++17 -c Animation/Animation.cpp -I /SFML/include

clear:
	rm main.o Animation/Animation.o AnimationManager/AnimationManager.o Player/Player.o AnimationLoader/AnimationLoader.o MapLoader/MapLoader.o Bullet/Bullet.o BulletManager/BulletManager.o Enemy/Enemy.o CollisionManager/CollisionManager.o  EnemyManager/EnemyManager.o ControlManager/ControlManager.o Game/Game.o
	rm *.o
	rm sfml-app