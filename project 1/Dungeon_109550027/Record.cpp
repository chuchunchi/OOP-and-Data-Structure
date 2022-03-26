#include "Record.h"

Record::Record(){

}

void  Record::savePlayer(Player* player, ofstream& aaa){
    aaa << player->getName() << endl;
    aaa << player->getCurrentRoom()->getIndex() << endl;
    aaa << player->getPreviousRoom()->getIndex() << endl;
    aaa << player->getCurrentHealth() << endl;
    aaa << player->getAttack() << endl;
    aaa << player->getDefense() << endl;

}


void Record::loadPlayer(Player* player, ifstream& aaa){
    string name;
    int curr,prevr,curh,attack,defense;
    aaa >> name >> curr >> prevr >> curh >> attack >> defense;
    player->setName(name);
    current = curr;
    previous = prevr;
    player->setCurrentHealth(curh);
    player->setAttack(attack);
    player->setDefense(defense);
}

void Record::saveRooms(Room* rooms, ofstream& orooms){
    for(int i=0;i<6;i++){
        orooms << rooms[i].getIndex() << endl;
        if(rooms[i].getUpRoom()!=NULL){
            orooms << rooms[i].getUpRoom()->getIndex() << endl;
        }
        else{
            orooms << "-1" << endl ;
        }
        if(rooms[i].getDownRoom()!=NULL){
            orooms << rooms[i].getDownRoom()->getIndex() << endl;
        }
        else{
            orooms << "-1" <<endl;
        }
        if(rooms[i].getLeftRoom()!=NULL){
            orooms << rooms[i].getLeftRoom()->getIndex() << endl;
        }
        else{
            orooms << "-1" << endl ;
        }
        if(rooms[i].getRightRoom()!=NULL){
            orooms << rooms[i].getRightRoom()->getIndex() << endl;
        }
        else{
            orooms << "-1" <<endl ;
        }
        orooms << rooms[i].getIsExit() << endl;

        orooms <<rooms[i].getObjects().size() << endl;
        for(int j=0;j<rooms[i].getObjects().size();j++){

            if(Item* item = dynamic_cast<Item*>(rooms[i].getObjects()[j])){
                orooms << item->getTag() << endl;
                orooms << item->getName() << endl;
                orooms << item->getHealth() << endl;
                orooms << item->getAttack() << endl;
                orooms << item->getDefense() << endl;
            }

            if(Monster* monster = dynamic_cast<Monster*>(rooms[i].getObjects()[j])){
                orooms << monster->getTag() << endl;
                orooms << monster->getName() << endl;
                orooms << monster->getCurrentHealth() << endl;
                orooms << monster->getAttack() << endl;
                orooms << monster->getDefense() << endl;
            }

            if(NPC* npc = dynamic_cast<NPC*>(rooms[i].getObjects()[j])){
                orooms << npc->getTag() << endl;
                orooms << npc->getName() << endl;
                orooms << npc->getScript() << endl;
                for(int k=0;k<npc->getCommodity().size();k++){
                    orooms << npc->getCommodity().size() << endl;
                    orooms << npc->getCommodity()[k].getName() << endl;
                    orooms << npc->getCommodity()[k].getHealth() << endl;
                    orooms << npc->getCommodity()[k].getAttack() << endl;
                    orooms << npc->getCommodity()[k].getDefense() << endl;
                }
            }
        }
    }
}

void Record::loadRooms(Room* rooms, ifstream& orooms){
    int ind,up,down,left,right,size_;
    bool exit;
    string name,tag,script;
    int health,attack,defense,inventory_num;

    for(int i=0;i<6;i++){
        vector<Object*> obj;
        orooms >> ind >> up >> down >> left >> right >> exit >> size_;
        rooms[i].setIndex(ind);
        if(up!=-1){
            rooms[i].setUpRoom(&rooms[up]);
        }
        else{
            rooms[i].setUpRoom(NULL);
        }
        if(down!=-1){
            rooms[i].setDownRoom(&rooms[down]);
        }
        else{
            rooms[i].setDownRoom(NULL);
        }
        if(left!=-1){
            rooms[i].setLeftRoom(&rooms[left]);
        }
        else{
            rooms[i].setLeftRoom(NULL);
        }
        if(right!=-1){
            rooms[i].setRightRoom(&rooms[right]);
        }
        else{
            rooms[i].setRightRoom(NULL);
        }
        rooms[i].setIsExit(exit);

        for(int j=0;j<size_;j++){
            orooms >> tag;
            if(tag == "Item"){
                orooms >> name >> health >> attack >> defense;
                Item* item = new Item(name,health,attack,defense);
                obj.push_back(item);
                rooms[i].setObjects(obj);
            }

            if(tag == "Monster"){
                orooms >> name >> health >> attack >> defense;
                Monster* monster = new Monster(name,health,attack,defense);
                obj.push_back(monster);
                rooms[i].setObjects(obj);
            }

            if(tag == "NPC"){
                orooms >> name >> script;
                orooms >> inventory_num;
                vector<Item> itemvector;
                for(int k=0;k<inventory_num;k++){
                    orooms >> name >> health >> attack >> defense;
                    Item* item = new Item(name,health,attack,defense);
                    itemvector.push_back(*item);
                }
                NPC* npc = new NPC(name,script,itemvector);
                obj.push_back(npc);
                rooms[i].setObjects(obj);
            }
        }
        obj.clear();
    }
}

void Record::saveToFile(Player* player, Room* rooms){
    ofstream aaa("p_record.txt");
    ofstream orooms("r_record.txt");
    savePlayer(player,aaa);
    saveRooms(rooms,orooms);
}

void Record::loadFromFile(Player* player, Room* rooms){
    ifstream aaa("p_record.txt");
    ifstream orooms("r_record.txt");
    loadPlayer(player,aaa);

    loadRooms(rooms,orooms);

    player->setCurrentRoom(&rooms[current]);

    player->setPreviousRoom(&rooms[previous]);

}
