#ifndef MAP_LOADER
#define MAP_LOADER

#include <unordered_map>
#include <vector>

#include <SFML/Graphics.hpp>

struct MapParams {
  std::vector<std::string> map;

  std::string name;
  int32_t height;
  int32_t width;

  int32_t tile_size;

  std::unordered_map<char, sf::Texture> tiles;
  sf::Sprite rectangle;
};

class MapLoader {
 public:
  void DownloadMap(const std::vector<std::string>& map,
                   const std::string& map_name,
                   const std::unordered_map<char, std::string>& tiles,
                   int32_t map_height, int32_t map_width, int32_t tile_size);

  void SetMap(const std::string& map_name);

  void DrawMap(sf::RenderWindow& window, double offsetX, double offsetY);

 private:
  std::unordered_map<std::string, MapParams> maps_;
  std::string current_map_;
};

#endif