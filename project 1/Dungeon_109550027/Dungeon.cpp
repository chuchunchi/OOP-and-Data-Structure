#include "Dungeon.h"

Dungeon::Dungeon(){

}

/* Create a new player, and give him/her basic status */
void Dungeon::createPlayer(){
    string my_name;
    cout << "Enter your name: ";
    cin >> my_name;
    cout << endl;
    player = Player(my_name,300,0,0);
    cout << "choose a game character: " << endl << "1.Gina Lee" << endl \
    << "2. Rose flower" << endl << "3. Jenny sun" << endl;
    int ans;
    cin >> ans;
    cout << endl;
    switch(ans){
        case 1:
            player.setAttack(300);
            player.setDefense(0);
            break;
        case 2:
            player.setAttack(100);
            player.setDefense(100);
            break;
        case 3:
            player.setAttack(0);
            player.setDefense(200);
            break;
    }

}

/* Create a map, which include several different rooms */
void Dungeon::createMap(){
    for(int i=0;i<6;i++){
        rooms[i] = Room();
        rooms[i].setIndex(i);
        if(i!=5){
            rooms[i].setIsExit(false);
        }
        else rooms[i].setIsExit(true);
    }

    rooms[0].setUpRoom(&rooms[1]);
    rooms[1].setDownRoom(&rooms[0]);
    rooms[1].setRightRoom(&rooms[2]);
    rooms[1].setUpRoom(&rooms[4]);
    rooms[2].setLeftRoom(&rooms[1]);
    rooms[2].setRightRoom(&rooms[3]);
    rooms[3].setLeftRoom(&rooms[2]);
    rooms[3].setUpRoom(&rooms[5]);
    rooms[4].setDownRoom(&rooms[1]);
    rooms[5].setDownRoom(&rooms[3]);

    vector<Object*> objects,obj;
    vector<Item> items;//NPC's item;
    Item* sword = new Item("sword",0,50,0);
    objects.push_back(sword);
    rooms[0].setObjects(objects);
    objects.clear();
    Item* glasses = new Item("glasses",0,0,300);
    obj.push_back(glasses);
    Item* pill_1 = new Item("crazy_pill",-70,0,0);
    obj.push_back(pill_1);
    Item* pill_2 = new Item("happy_pill",100,100,0);
    obj.push_back(pill_2);
    rooms[1].setObjects(obj);
    objects.clear();
    Item* helmet = new Item("helmet",200,0,160);
    objects.push_back(helmet);
    Monster* monster_1 = new Monster("SHOES Monster",200,80,50);
    objects.push_back(monster_1);
    rooms[2].setObjects(objects);
    objects.clear();
    Item* potion_kill = new Item("crazy_potion",-200,-100,0);
    items.push_back(*potion_kill);
    NPC* liar_merchant = new NPC("crazy_merchant","HEHEHE, you fool,\
don't trust stranger easily.",items);
    objects.push_back(liar_merchant);
    rooms[3].setObjects(objects);
    objects.clear();
    items.clear();
    Item* potion_good = new Item("potion_wahaha",500,0,0);
    items.push_back(*potion_good);
    Item* armor = new Item("armor",0,90,150);
    items.push_back(*armor);
    NPC* merchant = new NPC("merchant_wahaha","WaHaHa, lucky chicken,\
enjoy your present!",items);
    objects.push_back(merchant);
    Monster* monster_2 = new Monster("COFFEE monster",200,100,50);
    objects.push_back(monster_2);
    rooms[4].setObjects(objects);
    objects.clear();
    Monster* boss_monster = new Monster("TISSUE BOSS MONSTER",1000,700,100);
    objects.push_back(boss_monster);
    rooms[5].setObjects(objects);
    objects.clear();

}

/* Deal with player's moveing action */
void Dungeon::handleMovement(){
    int current_index;
    int inputnum;
    current_index = player.getCurrentRoom()->getIndex();
    cout << "your moving choice: " << endl;
    switch(current_index){
        case 0:
            cout << "1. go up" << endl;
            cin >> inputnum;
            cout << endl;
            switch(inputnum){
                case 1:
                    player.changeRoom(player.getCurrentRoom()->getUpRoom());
                    break;
                default:
                    cout << "invalid input!! You stupid!" <<endl;
                    player.changeRoom(player.getCurrentRoom());
                    break;
            }
            break;
        case 1:
            cout << "1. go up" << endl << "2. go right" << endl << "3. go down" <<endl;
            cin >> inputnum;
            cout << endl;
            switch(inputnum){
                case 1:
                    player.changeRoom(player.getCurrentRoom()->getUpRoom());
                    break;
                case 2:
                    player.changeRoom(player.getCurrentRoom()->getRightRoom());
                    break;
                case 3:
                    player.changeRoom(player.getCurrentRoom()->getDownRoom());
                    break;
                default:
                    cout << "invalid input!! You stupid!" <<endl;
                    player.changeRoom(player.getCurrentRoom());
                    break;
            }
            break;
        case 2:
            cout << "1. go left" << endl << "2. go right" <<endl;
            cin >> inputnum;
            cout <<endl;
            switch(inputnum){
                case 1:
                    player.changeRoom(player.getCurrentRoom()->getLeftRoom());
                    break;
                case 2:
                    player.changeRoom(player.getCurrentRoom()->getRightRoom());
                    break;
                default:
                    cout << "invalid input!! You stupid!" <<endl;
                    player.changeRoom(player.getCurrentRoom());
                    break;
            }
            break;
        case 3:
            cout << "1. go left" << endl << "2. go up" <<endl;
            cin >> inputnum;
            cout << endl;
            switch(inputnum){
                case 1:
                    player.changeRoom(player.getCurrentRoom()->getLeftRoom());
                    break;
                case 2:
                    player.changeRoom(player.getCurrentRoom()->getUpRoom());
                    break;
                default:
                    cout << "invalid input!! You stupid!" <<endl;
                    player.changeRoom(player.getCurrentRoom());
                    break;
            }
            break;
        case 4:
            cout << "1. go down" << endl;
            cin >> inputnum;
            cout << endl;
            switch(inputnum){
                case 1:
                    player.changeRoom(player.getCurrentRoom()->getDownRoom());
                    break;
                default:
                    cout << "invalid input!! You stupid!" <<endl;
                    player.changeRoom(player.getCurrentRoom());
                    break;
            }
            break;
    }

}

/* Deal with player's iteraction with objects(item, NPC, monster) in that room */
void Dungeon::handleEvent(Object* object){
    if(Item* item = dynamic_cast<Item*>(object)){
        if(item->triggerEvent(&player)){
            player.getCurrentRoom()->popObject(item);//delete
        }
    }
    if(Monster* monster = dynamic_cast<Monster*>(object)){
        if(monster->triggerEvent(&player)){
            if(checkGameLogic()){
                player.getCurrentRoom()->popObject(monster);//delete
            }
            else{
                Sleep(10000);
                exit(1);
            }
        }
        else{
            //retreat
            player.setCurrentRoom(player.getPreviousRoom());
        }
    }
    if(NPC* npc = dynamic_cast<NPC*>(object)){
        if(npc->triggerEvent(&player)){
            player.getCurrentRoom()->popObject(npc);//delete
        }
    }

}


/* Deal with the player's action     */
/* showing the action list */
/* that player can do at that room   */
/* and dealing with player's input   */
void Dungeon::chooseAction(vector<Object*> objects){
    if(!objects.empty()){
        for(int i=0;i<objects.size();i++){
            if(Monster* monster = dynamic_cast<Monster*>(objects[i])){
                handleEvent(objects[i]);
            }
        }
        cout << "choose your action: " << endl;
        cout << "1. move to another room." << endl << "2. show your status." << endl \
        << "3. save game and logout" << endl;
        for(int i=0;i<objects.size();i++){
            if(Item* item = dynamic_cast<Item*>(objects[i])){
                cout << i+4 << ". pick up " << item->getName() << endl;
            }
            if(NPC* npc = dynamic_cast<NPC*>(objects[i])){
                cout << i+4 << ". interact with NPC." << endl;
            }
        }
        int action;
        cin >> action;
        cout << endl;
        switch(action){
            case 1:{
                handleMovement();
            }
                break;
            case 2:{
                player.triggerEvent(&player);
            }
                break;
            case 3:{
                Record record;
                record.saveToFile(&player,rooms);
                exit(1);
            }

            case 4: case 5: case 6:{
                handleEvent(objects[action-4]);
            }
                break;
        }
    }

    if(objects.empty()){
        cout << "this room is empty, just move!" << endl;
        handleMovement();
    }

}

/* Deal with all game initial setting       */
/* Including create player, create map etc  */
void Dungeon::startGame(){
    cout << "1. start a new game" << endl << "2. load previous data" << endl;
    int ans;
    cin >> ans;
    cout << endl;
    if(ans==1){
        createPlayer();
        createMap();
        player.setCurrentRoom(&rooms[0]);
    }
    else{
        Record record;
        record.loadFromFile(&player,rooms);
    }
}

/* Check whether the game should end or not */
/* Including player victory, or he/she dead */
bool Dungeon::checkGameLogic(){
    if(player.checkIsDead()){
        return false;
    }
    else{
        return true;

    }
}

/* Deal with the whole game process */
void Dungeon::runDungeon(){
    startGame();
    while(checkGameLogic()){
        chooseAction(player.getCurrentRoom()->getObjects());
    }
    if(!checkGameLogic()){
        exit(1);
    }
}
