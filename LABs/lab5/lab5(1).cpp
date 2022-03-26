#include <vector>
#include <iostream>
using namespace std;

class Object{
public:
    virtual void response() = 0;
    
    virtual ~Object() throw() = default;
};

class IceMonster : public Object{
    //add constructor or functions if you need
    public:
	    void response(){
	    	cout << "fire attack" << endl;
		};
		virtual ~IceMonster() throw(){
		}
};

class FireMonster : public Object{
    //add constructor or functions if you need
    public:
		void response(){
	    	cout << "ice attack" << endl;
		};
		virtual ~FireMonster() throw(){
		}
};

class Treasure : public Object{
    //add constructor or functions if you need
    public:
		void response(){
	    	cout << "ya" << endl;
		};
		virtual ~Treasure() throw(){
		}
};


class Room{
public:
    Room *up_room;
    Room *down_room;
    Room *left_room;
    Room *right_room;
    int index;
    Object *o;
    //add constructor or functions if you need
    Room(){
    	up_room = 0;
		down_room = 0;
    	left_room = 0;
		right_room = 0;
	}
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int roomnum,blocks;
    int i,u,d,l,r;
    char roomtype,command;
    
    cin >> roomnum >> blocks;
    Room room[roomnum];
    for(i=0;i<roomnum;i++){
    	room[i].index = i;
    	cin >> roomtype;
    	switch (roomtype){
    		case 'e':
    			room[i].o = 0;
    			break;
    		case 'i':
    			room[i].o = new IceMonster();
    			break;
    		case 'f':
    			room[i].o = new FireMonster();
    			break;
    		case 't':
    			room[i].o = new Treasure();
		
		
		}
    	cin >> u >> d >> l >> r;
    	if(u!=-1){
    		room[i].up_room = &room[u];
		}
		if(d!=-1){
    		room[i].down_room = &room[d];
		}
		if(l!=-1){
    		room[i].left_room = &room[l];
		}
		if(r!=-1){
    		room[i].right_room = &room[r];
		}
	}
	Room *current_room = &room[0];
	Room *next_room;
	for(i=0;i<blocks;i++){
		cin >> command;
		switch (command){
			case 'u':
				next_room = current_room->up_room;
				break;
			case 'd':
				next_room = current_room->down_room;
				break;
			case 'l':
				next_room = current_room->left_room;
				break;
			case 'r':
				next_room = current_room->right_room;
				break;
		}
		if(next_room==0){
			cout << -1 << endl;
		}
		else{
			if(current_room->o==0){
				cout << 0 <<endl;
			}
			cout << next_room->index << " ";
			if(next_room->index!=0){
			
				next_room->o->response();
				delete next_room->o;
				current_room = next_room;
			}
		}
		

	}
    return 0;
}






