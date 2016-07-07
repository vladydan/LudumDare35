#include "back.hpp"

Background::Background(const std::string & back, const std::string & ground, sf::Vector2f sizeB, sf::Vector2f sizeG, float initialX)
{
    this->initialX = initialX;
    this->background = new sf::RectangleShape(sizeB);


    if (!this->backTex.loadFromFile(back))
        std::cout << "Background texture loading error" << std::endl;
    this->background->setTexture(&this->backTex);
    this->background->setPosition(initialX, 0);
    this->ground = new sf::RectangleShape(sizeG);
    if (!this->groundTex.loadFromFile(ground))
        std::cout << "Ground texture loading error" << std::endl;
    this->ground->setTexture(&this->groundTex);
    //this->ground->setPosition(sf::Vector2f(0, 0));
    this->ground->setPosition(sf::Vector2f(initialX, HEIGHT-64));
}

sf::RectangleShape  & Background::getBack()
{
    return (*this->background);
}

sf::RectangleShape  & Background::getGround()
{
    return (*this->ground);
}

void                Background::update(sf::RenderWindow & win)
{
    sf::Vector2f    posTmp;


    posTmp = this->background->getPosition();
    posTmp.x -= SPEED;
    if (posTmp.x <= 0 - WIDTH)
        posTmp.x = WIDTH;
    this->background->setPosition(posTmp);
    posTmp = this->ground->getPosition();
    posTmp.x -= SPEED;
    if (posTmp.x <= 0 - WIDTH)
        posTmp.x = WIDTH;
    this->ground->setPosition(posTmp);
    win.draw(*this->background);
    win.draw(*this->ground);
}
