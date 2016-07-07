#pragma once

#include "data.hpp"

class   Background
{
private:
    float                   initialX;
    sf::RectangleShape      *background;
    sf::RectangleShape      *ground;
    sf::Texture             backTex;
    sf::Texture             groundTex;

public:
    Background();
    Background(const std::string & back, const std::string & ground, sf::Vector2f sizeB, sf::Vector2f sizeG, float);
    sf::RectangleShape  &getBack();
    sf::RectangleShape  &getGround();
    void                update(sf::RenderWindow &);
};
