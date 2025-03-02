#ifndef PRIEST_H
#define PRIEST_H
#include "Player.h"
#include <string>
class Priest : public Player
{
private:
    /* data */
public:
    Priest(string name, Race race, int hitPoints=100,int magicPoints=200):Player(name,race,hitPoints,magicPoints){};
    string attack() const {
        return "I will assault you with Holy Wrath!";
    }

};


#endif