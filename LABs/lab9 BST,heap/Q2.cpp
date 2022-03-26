#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    while(cin>>N){
    	if(N==0){
    		break;
		}
		vector<int> minheap;
		int i,n;
		for(i=0;i<N;i++){
			cin >> n;
			minheap.push_back(n);
		}
		int sum=0;
		while(!minheap.empty()){
			make_heap(minheap.begin(),minheap.end());
			sort_heap(minheap.begin(),minheap.end());
			int cost=0;
			cost += minheap.front();
			pop_heap(minheap.begin(),minheap.end());
			minheap.pop_back();
			sort_heap(minheap.begin(),minheap.end());
			cost += minheap.front();
			sum += cost;
			pop_heap(minheap.begin(),minheap.end());
			minheap.pop_back();
			if(minheap.empty()){
				break;
			}
			minheap.push_back(cost);
		}
		for(int i=0;i<N;i++){
			cout << minheap[i] << ' ';
		}
		cout << endl;
		cout << sum <<endl;
	}
    return 0;
}

