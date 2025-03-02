#ifndef MAGE_H
#define MAGE_H
#include "Player.h"
#include <string>
class Mage : public Player
{
private:
    /* data */
public:
    Mage(string name, Race race, int hitPoints=150,int magicPoints=150):Player(name,race,hitPoints,magicPoints){};
    string attack()const {
        return "I will crush you with the power of my arcane missiles!";
    }

};


#endif