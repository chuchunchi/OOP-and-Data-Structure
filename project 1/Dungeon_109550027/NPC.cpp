#include "NPC.h"

NPC::NPC(){

}

NPC::NPC(string name,string script, vector<Item> commodity):GameCharacter(name,"NPC",100,100,100){
    this->script = script;
    this->commodity = commodity;
}

void NPC::listCommodity(){
    for(int i=0;i<this->commodity.size();i++){
        cout << this->commodity[i].getName() << "(" << this->commodity[i].getHealth() << "," << this->commodity[i].getAttack() \
        << "," << this->commodity[i].getDefense() << ")" << endl;
    }
    cout << endl;
}

bool NPC::triggerEvent(Object* object){
    //transaction in easy implementation
    Player* player = dynamic_cast<Player*>(object);
    cout << "Do you want to meet " << getName() << "?" <<endl;
    cout << "(Note: There are decent and liar merchant in this game.\
    Do you want to believe him?)" << endl;
    cout << "1. yes pleasssssse" << endl << "2. no, good luck and good bye " << getName() << endl;
    int ans;
    cin >> ans;
    cout << endl;
    if(ans==1){
        cout << getScript() << endl;
        cout << "Here's my item, ";
        listCommodity();
        cout <<"you have to take them." << endl << "1.OK" << endl ;
        int okay;
        cin >> okay;

        for(int i=0;i<this->commodity.size();i++){
            player->addItem(this->commodity[i]);
            player->increaseStates(this->commodity[i].getHealth(),this->commodity[i].getAttack(),this->commodity[i].getDefense());
        }
        player->triggerEvent(player);
        return true;
    }
    else{
        return false;
    }

}

/*set/get func*/
void NPC::setScript(string script){
    this->script = script;
}

void NPC::setCommodity(vector<Item> commodity){
    this->commodity = commodity;
}

string NPC::getScript(){
    return this->script;
}

vector<Item> NPC::getCommodity(){
    return this->commodity;
}
