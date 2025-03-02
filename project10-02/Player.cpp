#include "Player.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

Player::Player(string name, Race race, int hitPoints, int magicPoints)
    : name(name), race(race), hitPoints(hitPoints), magicPoints(magicPoints) {}

string Player::getName() {
    return name;
}

Race Player::getRace() {
    return race;
}

string Player::whatRace(){
    try {
        if (race == HUMAN) {
            return "Human";
        } else if (race == ELF) {
            return "Elf";
        } else if (race == ORC) {
            return "Orc";
        } else if (race == TROLL) {
            return "Troll";
        } else if (race == DWARF) {
            return "Dwarf";
        } else {
            throw runtime_error("An error occurred!");
        }
    } catch (exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
        return "Unknown Race";  // Ensure function always returns a value
    }
}


int Player::getHitPoints() {
    return hitPoints;
}

int Player::getMagicPoints() {
    return magicPoints;
}

void Player::setName(string name) {
    this->name = name;
}

void Player::setRace(Race race) {
    this->race = race;
}

void Player::setHitPoints(int hitPoints) {
    this->hitPoints = hitPoints;
}

void Player::setMagicPoints(int magicPoints) {
    this->magicPoints = magicPoints;
}
