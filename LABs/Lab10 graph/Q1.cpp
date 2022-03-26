#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

/*void add_edge(vector<int> v[],int a,int b){
	v[a].push_back(b);
}*/
/*bool notallvisited(int i,int n,bool* visited){
	for(i=0;i<n;i++){
		if(visited[i]==false){
			return true;
		}
	}
	return false;
}*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	int n,i,j;
	cin >> n;
	int matrix[n][n];
	vector<int> edge[n];
	bool visited[n]={false};
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin >> matrix[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(matrix[i][j]==1){
				edge[i].push_back(j);
			}
		}
	}
	stack <int> s;

	for(i=0;i<n;i++){
		if(visited[i]==1){
			continue;
		}
		else{
			s.push(i);
			while(!s.empty()){
				int p = s.top();
				s.pop();
				if(!visited[p]){
					cout << p << ' ';
					visited[p] = true;
					for(int g=edge[p].size()-1;g>=0;g--){
						s.push(edge[p][g]);
					}
				}
			}
			cout << endl;
		}
	}

    return 0;
}

