#ifndef ANIMAL_H
#define ANIMAL_H

#include <string> 

using namespace std;

class Animal
{
    private:
        string name;
        double width;

    public:
        Animal(string name, double width) : name(name), width(width) {}
        string getName();
        void setName(string name);
        double getWidth();
        void setWidth(double width);
        virtual string makeNoise();
        virtual string eat() const = 0;
};

#endif
