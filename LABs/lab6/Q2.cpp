#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  	vector<int> v;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int blocks;
    cin >> blocks;
    for(int i=0;i<blocks;i++){
    	char order;
    	cin >> order;
    	switch(order){
    		case 'a':
    			int n;
				cin >> n;
    			v.push_back(n);
    			break;
    		case 'e':
    			int m;
				cin >> m;
    			v.erase(find(v.begin(),v.end(),m));
    			break;
    		case 'r':
    			std::reverse(v.begin(),v.end());
    			break;
    		case 'd':
    			v.erase(v.end()-1);
    			break;
    		case 's':
    			cout << v.size() << " ";
    			break;
    		case 'p':
    			for(int j=0;j<v.size();j++){
    				cout << v[j] << " ";
				}
				break;
		}
	}
    return 0;
}
