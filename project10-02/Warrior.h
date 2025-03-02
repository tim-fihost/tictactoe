#ifndef WARRIOR_H
#define WARRIOR_H
#include "Player.h"
#include <string>
class Warrior : public Player
{
private:
    /* data */
public:
    Warrior(string name, Race race, int hitPoints=200,int magicPoints=0):Player(name,race,hitPoints,magicPoints){};
    string attack() const {
        return "I will destroy you with my sword, foul demon!";
    }

};


#endif