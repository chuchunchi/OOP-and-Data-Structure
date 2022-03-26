#include "Item.h"

Item::Item(){

}

Item::Item(string name,int health, int attack, int defense):Object(name, "Item"){
    this->health = health;
    this->attack = attack;
    this->defense = defense;
}

bool Item::triggerEvent(Object* object){
    //add item
    Player* player = dynamic_cast<Player*>(object);
    cout << "Do you want the " << getName() << "?" << endl;
    cout << "1. yes" << endl << "2. no way:(" << endl;
    int inputnum;
    cin >> inputnum;
    cout << endl;
    if(inputnum==1){
        cout << "Here's " << getName() << "(" << getHealth() << "," << getAttack() << "," << getDefense() << ")" << endl;
        player->addItem(*this);
        player->increaseStates(getHealth(),getAttack(),getDefense());
        return true;
    }
    else{
        return false;
    }
}

/*set/get func*/
void Item::setHealth(int health){
    this->health = health;
}

void Item::setAttack(int attack){
    this->attack = attack;
}

void Item::setDefense(int defense){
    this->defense = defense;
}

int Item::getHealth(){
    return this->health;
}

int Item::getAttack(){
    return this->attack;
}

int Item::getDefense(){
    return this->defense;
}
