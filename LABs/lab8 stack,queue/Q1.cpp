#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
	int n,i,j;
	char ch;
	cin >> n;

	
	for(i=0;i<n;i++){
		string s;
		stack <char> mystack;
		cin >> s;
		for(j=0;j<s.length();j++){
			
			if(s[j]=='(' || s[j]=='[' || s[j]=='{'){
				mystack.push((s[j]));
			}
			else if(mystack.empty()){
				mystack.push(s[j]);
				break;
			}
			else if(s[j]==')' || s[j]==']' || s[j]=='}'){
				if(s[j]==')'&&mystack.top()=='('){
					mystack.pop();
					continue;
				}
				if(s[j]==']'&&mystack.top()=='['){
					mystack.pop();
					continue;
				}
				if(s[j]=='}'&&mystack.top()=='{'){
					mystack.pop();
					continue;
				}
				else{
					mystack.push(s[j]);
				}
				
			}
		}
		if(mystack.empty()){
			cout << "yes" << endl;
		}
		else{
			cout << "no" << endl;
		}

	}  
    return 0;
}
