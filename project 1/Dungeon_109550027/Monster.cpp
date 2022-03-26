#include "Monster.h"

Monster::Monster(){

}

Monster::Monster(string name,int maxHealth,int attack,int defense):GameCharacter(name,"Monster", maxHealth, attack, defense){

}

bool Monster::triggerEvent(Object* object){
    //combat system
    Player* player = dynamic_cast<Player*>(object);
    while(true){
        cout << "Do you want to fight with " << this->getName() << "(" << getCurrentHealth() << "," << getAttack() \
        << "," << getDefense() << ")?" << endl;
        cout << "1. yes" << endl << "2. no, retreat, back to previous room" << endl \
        << "3. check my status" << endl;
        int answer;
        cin >> answer;
        cout << endl;
        if(answer==1){
            while(true){
                this->takeDamage(player->getAttack());
                if(this->checkIsDead()){
                    if(getName()!="TISSUE BOSS MONSTER"){
                        cout << "you defeat " << this->getName() << endl;
                        return true;
                    }
                    else{
                        cout << "Y O U    W I N N N N N N    T H I S    G A M E  !!!!!!!!!!!!!!!!" << endl;
                        Sleep(10000);
                        exit(1);
                    }
                }
                else{
                    player->takeDamage(this->getAttack());
                    if(player->checkIsDead()){
                        cout << "YOU ARE DEFEATED BY " << this->getName() << endl;
                        cout << "GAMEOVER!"<< endl;
                        Sleep(10000);
                        exit(1);
                    }
                }
            }
        }

        if(answer==2){
            return false;
        }

        if(answer==3){
            player->triggerEvent(player);
            continue;
        }
    }


}
