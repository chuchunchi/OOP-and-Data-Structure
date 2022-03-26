#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class BST;
class node{

    public:
        node *left;
        node *right;
        node *parent;
        int data;
        node(){
            left = 0;
            right = 0;
            parent = 0;
            data = 0;
        };
        node(int d){
            left = 0;
            right = 0;
            parent = 0;
            data = d;
        };
        friend class BST;
        
};

class BST{
    public:
        node *root;
        BST(){
            root = 0;
        };
        node* insert(node *root,int value){
            if(root==0){
                root = new node(value);
            }
            else if(value < root->data){
                root->left = insert(root->left,value);
            }
            else if(value > root->data){
                root->right = insert(root->right,value);
            }

            return root;
        };
        
        void postOrder(node *root){
            if(root==0){
                return;
            }

            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << endl;
        };
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    BST tree; 
    int data;
    cin >> data;
    tree.root = tree.insert(tree.root,data);
    while(cin >> data){
        tree.insert(tree.root,data);
    }
    //cout << "yes";
    tree.postOrder(tree.root);
 
    return 0;
}

