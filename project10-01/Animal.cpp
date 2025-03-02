#include "Animal.h"
#include <iostream>

using namespace std;
string Animal::getName(){
    return name;
}
void Animal::setName(string name){
    this->name = name;
}   
double Animal::getWidth(){
    return width;
}
void Animal::setWidth(double width){
    this->width = width;
}
string Animal::makeNoise(){
    return "unknown";
}