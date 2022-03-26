#include "Player.h"

Player::Player(){

}

Player::Player(string name,int maxHealth,int attack,int defense):GameCharacter(name,"Player", maxHealth, attack, defense){

}

void Player::addItem(Item item){
    this->inventory.push_back(item);
}

void Player::increaseStates(int currentHealth, int attack, int defense){
    setCurrentHealth(getCurrentHealth()+currentHealth);
    setAttack(getAttack()+attack);
    setDefense(getDefense()+defense);
}

void Player::changeRoom(Room* room){
    Room* temp = room;
    this->previousRoom = this->currentRoom;
    this->currentRoom = temp;

}

bool Player::triggerEvent(Object* object){
    //show the status
    Player* player = dynamic_cast<Player*>(object);
    cout << "Hi, " << this->getName() << ": This is your current status." << endl;
    cout << "Your current health is " << this->getCurrentHealth() << endl;
    cout << "Your attack is " << this->getAttack() << endl;
    cout << "Your defense is " << this->getDefense() << endl;
    cout << "Your current room is " << this->getCurrentRoom()->getIndex() << endl << endl;

}

/*set/get func*/
void Player::setCurrentRoom(Room* currentRoom){
    this->currentRoom = currentRoom;
}

void Player::setPreviousRoom(Room* previousRoom){
    this->previousRoom = previousRoom;
}

void Player::setInventory(vector<Item> inventory){
    this->inventory = inventory;
}

Room* Player::getCurrentRoom(){
    return this->currentRoom;
}

Room* Player::getPreviousRoom(){
    return this->previousRoom;
}

vector<Item> Player::getInventory(){
    return this->inventory;
}
