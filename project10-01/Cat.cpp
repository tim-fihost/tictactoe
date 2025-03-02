#include <iostream>
#include "Cat.h"
using namespace std;
Cat::Cat(string name, double width)  : Animal (name,width){
    
};
string Cat::eat() const{
    return "Tasty kitty food!";
}
string Cat::makeNoise(){
    return "Meow!";
}
void Cat::chaseMouse(){
    cout<<"I'm chasing a mouse!"<<endl;
}