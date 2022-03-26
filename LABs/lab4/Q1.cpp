#include <iostream>
using namespace std;

class linkedlist;
class Room{
public:
    Room *left_room;
    Room *right_room;
    int index;
	Room(int n){
        index = n;
        left_room=0;
        right_room=0;
    }//instructor
    friend class LinkedList;
};


class linkedlist{
private:
    int size;
public:
    Room *current;
    Room *first;
    void Push_back(int x){
    	Room *newRoom = new Room(x); 

	    if (first == 0) {                      
	        first = newRoom;
	        return;
	    }
	
	    current = first;
	    while (current->right_room != 0) {          
	        current = current->right_room;
	    }
	    current->right_room = newRoom; 
	    newRoom->left_room=current;
	
	};
	int get_size(){
		return size;
	};
	void set_size(int thesize){
		size = thesize;
		first=0;
	};
	void right(){
		if(current->right_room == 0){
			cout << "-1 ";
		}
		else{
			current = current->right_room;
			cout << current->index << " ";
		}
	};
	void left(){
		if(current->left_room == 0){
			cout << "-1 ";
		}
		else{
			current = current->left_room;
			cout << current->index << " ";
		}
	};
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int size;
	cin >> size;
	linkedlist list;
	list.set_size(size);
	int i;
	for(i=0;i<list.get_size();i++){
		int val;
		cin >> val;
		list.Push_back(val);
	}
	int blocks;
	cin >> blocks;
	list.current=list.first;
	cout << list.current->index << " ";//print the first index
	for(i=0;i<blocks;i++){
		char order;
		getchar();
		cin >> order;
		if(order=='r'){
			list.right();
			continue;
		}
		if(order=='l'){
			list.left();
			continue;
		}
	} 
    return 0;
}
