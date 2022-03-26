#include "GameCharacter.h"

GameCharacter::GameCharacter(){

}

GameCharacter::GameCharacter(string name,string tag,int maxHealth,int attack,int defense):Object(name,tag){
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    this->attack = attack;
    this->defense = defense;
}

bool GameCharacter::checkIsDead(){
    if(this->currentHealth<=0){
        return true;
    }
    else return false;
}

int GameCharacter::takeDamage(int damage){
    this->currentHealth -= (damage - this->getDefense());
    return this->currentHealth;
}

    /* Set & Get function*/
void GameCharacter::setMaxHealth(int maxhealth){
    this->maxHealth = maxhealth;
}

void GameCharacter::setCurrentHealth(int currenthealth){
    this->currentHealth = currenthealth;
}

void GameCharacter::setAttack(int attack){
    this->attack = attack;
}

void GameCharacter::setDefense(int defense){
    this->defense = defense;
}

int GameCharacter::getMaxHealth(){
    return this->maxHealth;
}

int GameCharacter::getCurrentHealth(){
    return this->currentHealth;
}

int GameCharacter::getAttack(){
    return this->attack;
}

int GameCharacter::getDefense(){
    return this->defense;
}
