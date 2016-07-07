#pragma once

#include "data.hpp"
#include "AObstacle.hpp"
#include <string>

class   PowerEvent{
private:
    sf::Shape*                  backBlock;
    std::list<int>              keys;
    std::vector<sf::Shape *>    PowerList;
    std::map<int, int>          CorrespKeys;
    std::map<int, int>  CurrentPower;
    int                         time;
    bool                        display;
    sf::Font                    font;
    sf::Text                    text;
    sf::Text                    textKeys;

    public:
    PowerEvent();
    int                newEvent(sf::RenderWindow &);
    int                 getTime() const;
    void                update(int time, sf::RenderWindow &);
    CHARTYPE       getBlockType(int key, sf::RenderWindow & win);
    void                killEvent();
    bool                getDisplay() const;
};
