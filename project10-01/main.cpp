#include <iostream>
#include <string>
#include "Animal.h"
#include "Cat.h"

using namespace std;

int main(){
    Cat cat("Timmy", 12);
    Animal *catptr = new Cat("Booby",14);
    cout<<"Welcome!!!"<<endl;
    cout<<"Make noise? "<< catptr->makeNoise() << endl;
    cout<<"Eating? "<<catptr->eat()<<endl;
    //((Cat*)catptr)->chaseMouse();
    (reinterpret_cast<Cat*>(catptr))->chaseMouse();//safer and newer method!
    delete catptr;
    catptr = nullptr;
    return 0;
}