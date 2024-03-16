#include "EnemyManager.hpp"

void EnemyManager::AddEnemy(AnimationManager& manager, double x_coord, double y_coord,
			double x_left, double x_right, double x_speed) {
	
	enemies_.push_back(Enemy(manager, x_coord, y_coord, x_left, x_right, x_speed));
}

	void EnemyManager::AddEnemy(const Enemy& enemy) {
			enemies_.push_back(enemy);
	}

void EnemyManager::UpdateEnemies(double time, std::list<Bullet*>* bullets) {
	for (size_t i = 0; i < enemies_.size(); ++i) {
		enemies_[i].UpdateEnemy(time, bullets);
	}
}

void EnemyManager::DrawEnemies(sf::RenderWindow& window, double offsetX, double offsetY) {
	for (size_t i = 0; i < enemies_.size(); ++i) {
		enemies_[i].DrawEnemy(window, offsetX, offsetY);
	}
}

