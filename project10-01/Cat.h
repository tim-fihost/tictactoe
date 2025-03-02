#ifndef CAT_H
#define CAT_H
#include "Animal.h"
#include <string>
class Cat : public Animal
{
private:
    /* data */
public:
    Cat(string name, double width);
    string eat() const;
    string makeNoise();
    void chaseMouse();
};


#endif