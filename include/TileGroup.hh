#pragma once
#include "Tile.hh"
#include<fstream>

class TileGroup
{
private:
  sf::RenderWindow* window;
  std::vector<Tile*>* tiles;
  int COLS{}, ROWS{};
  std:: ifstream* reader{};
public:
  TileGroup(sf::RenderWindow*& window, int COLS, int ROWS, const char* filePath);
  ~TileGroup();

  void GenerateMap();  
  void Draw();
};