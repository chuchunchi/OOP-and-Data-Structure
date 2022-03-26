#include "Room.h"

Room::Room(){
    upRoom = 0;
    downRoom = 0;
    leftRoom = 0;
    rightRoom = 0;
}

/*Room::Room(bool isexit, int index, vector<Object*> objects){
    this->isExit = isexit;
    this->index = index;
    this->objects = objects;
}*/

bool Room::popObject(Object* object){
    /*pop out the specific object, used when the interaction is done*/
    for(int i=0;i<objects.size();i++){
        if(object->getName()==objects[i]->getName()){
            objects.erase(objects.begin()+i);
        }
    }

}

/*set/get func*/
void Room::setUpRoom(Room* uproom){
    this->upRoom = uproom;
}

void Room::setDownRoom(Room* downroom){
    this->downRoom = downroom;
}

void Room::setLeftRoom(Room* leftroom){
    this->leftRoom = leftroom;
}

void Room::setRightRoom(Room* rightroom){
    this->rightRoom = rightroom;
}

void Room::setIsExit(bool isexit){
    this->isExit = isexit;
}

void Room::setIndex(int index){
    this->index = index;
}

void Room::setObjects(vector<Object*> objects){
    this->objects = objects;
}

bool Room::getIsExit(){
    return this->isExit;
}

int Room::getIndex(){
    return this->index;
}

vector<Object*> Room::getObjects(){
    return this->objects;
}

Room* Room::getUpRoom(){
    return this->upRoom;
}

Room* Room::getDownRoom(){
    return this->downRoom;
}

Room* Room::getLeftRoom(){
    return this->leftRoom;
}

Room* Room::getRightRoom(){
    return this->rightRoom;
}

