all: main
	./sfml-app

main: main.o Animation/Animation.o AnimationManager/AnimationManager.o Player/Player.o AnimationLoader/AnimationLoader.o MapLoader/MapLoader.o Bullet/Bullet.o BulletManager/BulletManager.o Enemy/Enemy.o CollisionManager/CollisionManager.o  EnemyManager/EnemyManager.o
	g++ -L/lib main.o Animation/Animation.o AnimationManager/AnimationManager.o Player/Player.o AnimationLoader/AnimationLoader.o MapLoader/MapLoader.o Bullet/Bullet.o BulletManager/BulletManager.o Enemy/Enemy.o CollisionManager/CollisionManager.o  EnemyManager/EnemyManager.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp -I /SFML/include

EnemyManager.o: EnemyManager/EnemyManager.cpp EnemyManager/EnemyManager.hpp
	g++ -c EnemyManager/EnemyManager.cpp -I /SFML/include

CollisionManager.o: CollisionManager/CollisionManager.cpp CollisionManager/CollisionManager.hpp
	g++ -c CollisionManager/CollisionManager.cpp -I /SFML/include

Enemy.o: Enemy/Enemy.cpp Enemy/Enemy.hpp
	g++ -c Enemy/Enemy.cpp -I /SFML/include

BulletManager.o: BulletManager/BulletManager.cpp BulletManager/BulletManager.hpp
	g++ -c BulletManager/BulletManager.cpp -I /SFML/include

Bullet.o: Bullet/Bullet.cpp Bullet/Bullet.hpp
	g++ -c Bullet/Bullet.cpp -I /SFML/include

MapLoader.o: MapLoader/MapLoader.cpp MapLoader/MapLoader.hpp
	g++ -c MapLoader/MapLoader.cpp -I /SFML/include

Player.o: Player/Player.cpp Player/Player.hpp
	g++ -c Player/Player.cpp -I /SFML/include

AnimationLoader.o: AnimationLoader/AnimationLoader.cpp AnimationLoader/AnimationLoader.hpp
	g++ -c AnimationLoader/AnimationLoader.cpp -I /SFML/include

AnimationManager.o: AnimationManager/AnimationManager.cpp AnimationManager/AnimationManager.hpp
	g++ -c AnimationManager/AnimationManager.cpp -I /SFML/include

Animation.o: Animation/Animation.cpp Animation/Animation.hpp
	g++ -c Animation/Animation.cpp -I /SFML/include

clear:
	rm *.o
	rm sfml-app
	rm Animation/Animation.o AnimationManager/AnimationManager.o Player/Player.o AnimationLoader/AnimationLoader.o MapLoader/MapLoader.o Bullet/Bullet.o BulletManager/BulletManager.o Enemy/Enemy.o CollisionManager/CollisionManager.o  EnemyManager/EnemyManager.o