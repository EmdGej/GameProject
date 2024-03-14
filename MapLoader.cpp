#include "MapLoader.hpp"

void MapLoader::DownloadMap(const std::vector<std::string>& map,
                            const std::string& map_name,
                            const std::unordered_map<char, std::string>& tiles,
                            int32_t map_height, int32_t map_width,
                            int32_t tile_size) {
  std::unordered_map<char, sf::Texture> tiles_map;
  for (const auto& tile : tiles) {
    sf::Texture texture;
    texture.loadFromFile(tile.second);

    tiles_map[tile.first] = texture;
  }

  maps_[map_name] = MapParams{map,       map_name,  map_height,  map_width,
                              tile_size, tiles_map, sf::Sprite()};
  current_map_ = map_name;
}

void MapLoader::SetMap(const std::string& map_name) { current_map_ = map_name; }

void MapLoader::DrawMap(sf::RenderWindow& window, double offsetX,
                        double offsetY) {
  auto& draw_map = maps_[current_map_];

  for (int32_t i = 0; i < draw_map.height; ++i) {
    for (int32_t j = 0; j < draw_map.width; ++j) {
      if (draw_map.map[i][j] == ' ') {
        continue;
      }
      draw_map.rectangle.setTexture(draw_map.tiles[draw_map.map[i][j]]);

      draw_map.rectangle.setPosition(j * draw_map.tile_size - offsetX,
                                     i * draw_map.tile_size - offsetY);
      window.draw(draw_map.rectangle);
    }
  }
}