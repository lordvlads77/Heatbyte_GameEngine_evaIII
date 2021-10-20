#include "TileGroup.hh"
#include<iostream>

int size{4};

TileGroup::TileGroup(sf::RenderWindow*& window, int COLS, int ROWS, const char* filePath, float scale, float tileWidth, float tileHeight, 
const char* textureUrl)
{
  this->textureUrl = textureUrl;
  this->tileWidth = tileWidth;
  this->tileHeight = tileHeight;
  this->scale = scale;
  this->COLS = COLS;
  this->ROWS = ROWS;
  this->filePath = filePath;
  reader = new std::ifstream();
  this->window = window;
  tiles = new std::vector<Tile*>();
  //std::string line;

  /*while (std::getline(*reader, line))
  {
    std::cout << line << std::endl;
  }*/

  GenerateMap();
}

TileGroup::~TileGroup()
{

}

void TileGroup::GenerateMap()
{
  /*Tile* tile1{new Tile("../assets/tiles.png", 4.f, 16, 16, 0, 2, 0, 0, window)};
  Tile* tile2{new Tile("../assets/tiles.png", 4.f, 16, 16, 1, 2, 16 * 1 * 4.f, 0, window)};
  Tile* tile3{new Tile("../assets/tiles.png", 4.f, 16, 16, 2, 2, 16 * 2 * 4.f, 0, window)};
  Tile* tile4{new Tile("../assets/tiles.png", 4.f, 16, 16, 3, 2, 16 * 3 * 4.f, 0, window)};

  /*for(int i{}; i < size - 1; i++)
  {
    tiles->push_back(new Tile("../assets/tiles.png", 4.f, 16, 16, i, 2, 16 * i * 4.f, 0, window));
  }*/

  /*tiles->push_back(tile1);
  tiles->push_back(tile2);
  tiles->push_back(tile3);
  tiles->push_back(tile4);*/

  reader->open(filePath);

  for(int y{}; y < ROWS; y++)
  {
    for(int x{}; x < COLS; x++)
    {
      char currentTile{};

      reader->get(currentTile);
      int posX{atoi(&currentTile) * scale * tileWidth * x};
      reader->get(currentTile);
      int posY{atoi(&currentTile) * scale * tileWidth * y};

      tiles->push_back(new Tile(textureUrl, scale, tileWidth, tileHeight, x, y, posX, posY, window));
      reader->ignore();
    }
  }
  reader->close();
}

void TileGroup::Draw()
{

  for(auto& tile : *tiles)
  {
    tile->Draw();
  }
}