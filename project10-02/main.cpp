//rpg_game
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Warrior.h"
#include "Priest.h"
#include "Mage.h"
using namespace std;
//vector
vector <Player*>players;
//functions
void add_new_player(string user_name,Race user_race, int type);
Race race_determine(int which);
void print_characters();
void print_race();
void printAll();
void doCleanup();
int main(){
    //vars 
    int character;
    string name;
    int race_select;
    Race race;
    cout<<"Welcome to sort of War Craft Game!"<<endl;
    //code:
    while (true)
    {
        print_characters();
        cin>>character;
        if (character == 0)
        {
            break;
        }
        cout<<endl;//==============
        cout<<"What would you like name your character?"<<endl;
        cin>>name;

        cout<<endl;//==============
        print_race();
        cin>>race_select;

        cout<<endl;//==============
        race = race_determine(race_select);
        add_new_player(name,race,character);
    }
    printAll();
    doCleanup();
    cout<<"Program is done!"<<endl;
    return 0;
}
void add_new_player(string user_name,Race user_race, int type){
    Player* player_ptr; 
    if (type == 1) {
        player_ptr =new Warrior(user_name, user_race);
        players.push_back(player_ptr);
    } else if (type == 2) {
        player_ptr = new Priest(user_name, user_race);
        players.push_back(player_ptr);
    } else if (type == 3) {
        player_ptr = new Mage(user_name, user_race);
        players.push_back(player_ptr);
    }
}
Race race_determine(int which){
    if (which == 1) {
       return HUMAN ;
    } else if (which == 2) {
        return ELF;
    } else if (which == 3) {
        return ORC;
    } else if (which == 4) {
        return TROLL;
    } else if (which == 5) {
        return DWARF;
    }
    return UNKNOWN;
}
void print_characters(){
    cout<<"Which of the following would you like?"<<endl;
    cout<<"\t"<<"1 - Create a Warrior"<<endl;
    cout<<"\t"<<"2 - Create a Priest"<<endl;
    cout<<"\t"<<"3 - Create a Mage"<<endl;
    cout<<"\t"<<"0 - Finish creating player characters"<<endl;
}
void print_race(){
    cout<<"Now which race do you want?"<<endl;
    cout<<"\t"<<"1 - Human"<<endl;
    cout<<"\t"<<"2 - An Elf"<<endl;
    cout<<"\t"<<"3 - Dwarf"<<endl;
    cout<<"\t"<<"4 - An Orc"<<endl;
    cout<<"\t"<<"5 - Troll"<<endl;
}
void printAll(){
    for (Player* aPlayer:players)
    {
        cout<<"I'm a " <<aPlayer->whatRace()<<" "<<aPlayer->getName() <<" and my attack is: ";
        cout<<aPlayer->attack()<<endl;
    }
}
void doCleanup(){
    for(Player* player : players){
        delete player;
    }
    players.clear();
}
