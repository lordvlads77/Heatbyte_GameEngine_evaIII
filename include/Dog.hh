#pragma once
#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>
#include "Rigidbody.hh"
#include "GameObject.hh"

class Dog : public GameObject
{
private:

public:
  Dog(std::string textureUrl, float scale, int width, int height, int column, int row, float posX, float posY, b2BodyType bodyType, b2World*& world, sf::RenderWindow*& window);
  ~Dog();

  void Update(float& deltaTime) override;
  void Draw() override;
};
