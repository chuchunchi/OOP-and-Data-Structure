#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
};

class LinkedList {
public:
    Node *root;
    int len;
    LinkedList() : root(nullptr), len(0) {}
    void push(int);
    void insert(int, int);
    int find(int);
    void remove(int);
    void print();
};

void LinkedList::push(int x){
	// your implementation
	Node *cur = root;
	Node *topush = new Node(x);
	if(len==0){
		root = topush;
		len++;
		return;
	}
	while(cur->next!=NULL){
		cur = cur->next;
	}
	cur->next = topush; 
	len ++;
}

void LinkedList::insert(int pos, int x){
	// your implementation
	if(pos>len){
		cout << "insert fail" << endl;
		return;
	}
	Node *n = new Node(x);
	if(pos==0){
		n->next = root;
		root = n;
		len++;
		return;
	}
	Node *cur = root;
	for(int i=0;i<pos-1;i++){
		cur = cur->next;
	}
	n->next = cur->next;
	cur->next = n;
	len ++;
	
}

int LinkedList::find(int x){
	// your implementation
	Node *cur = root;
	int i;
	for(i=0;i<len;i++){
		if(cur->val==x){
			return i;
		}
		cur = cur->next;
	}
	return -1;
}

void LinkedList::remove(int pos){
	// your implementation
	if(pos >= len){
		cout << "remove fail" << endl;
		return;
	}
	if(pos==0){
		root = root->next;
		len--;
		return;
	}
	Node *bef = root;
	for(int i=0;i<pos-1;i++){
		bef = bef->next;
	}
	Node *discard = bef->next;
	bef->next = discard->next;
	len--;
}

void LinkedList::print(){
    if(root == nullptr)
        return;

    Node *cur = root;
    while(cur->next != nullptr){
        cout << cur->val << ", ";
        cur = cur->next;
    }
    cout << cur->val << endl;
}

int main(){
    LinkedList mylist;
    
    int n, a, b;
    cin >> n;
    char c;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == 'p'){
            cin >> a;
            mylist.push(a);
        }else if(c == 'i'){
            cin >> a >> b;
            mylist.insert(a, b);
        }else if(c == 'r'){
            cin >> a;
            mylist.remove(a);
        }else if(c == 'f'){
            cin >> a;
            cout << mylist.find(a) << endl;
        }else if(c == '?'){
            mylist.print();
        }
    }
    return 0;
}
