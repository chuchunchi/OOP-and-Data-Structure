#include <iostream>
#include <limits>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> intpair;
int inf = std::numeric_limits<int>::max();

class Graph{
	public:
	int v;//vertices
	vector<intpair> *myadj;//(node,cost)

		Graph(int v){
			this->v = v;
			myadj = new vector<intpair> [v];
			
		}
		void addedge(int start,int end,int cost){
			myadj[start].push_back(make_pair(end,cost));
			myadj[end].push_back(make_pair(start,cost));
		}
		void prim(){
			priority_queue<intpair/*(key,vertexindex)*/, vector<intpair>,greater<intpair> > Q;
			//minheap pririty queue (#include <bits/stdc++.h>)//priority base on the first element(key)
			vector<bool> isvisit(v,0);
			vector<int> parent(v);
			vector<int> key(v);
			for(int i=0;i<v;i++){
				if(i==0){//starting vertex
					key[i]=0;
					Q.push(make_pair(key[i],i));
				}
				else{
					key[i]=inf;
					Q.push(make_pair(key[i],i));
				}
			}
			while(!Q.empty()){
				int currentv = Q.top().second;
				Q.pop();
				if(isvisit[currentv]){
					continue;
				}
				
				vector<intpair>::iterator i;
				for(i=myadj[currentv].begin();i!=myadj[currentv].end();++i){
					//i=current adj of currentv
					int vertex = (*i).first; // i's vertex number
            		int weight = (*i).second; //weight between i and currentv
					if(isvisit[vertex]){
						continue;
					}
					if(key[vertex]>weight){
						key[vertex] = weight;
						parent[vertex] = currentv;
						Q.push(make_pair(key[vertex],vertex));
						
					}
				}
				isvisit[currentv] = 1;
				
			}
			int total=0;
			for(int i=0;i<v;i++){
				total += key[i];
			}
			cout << total;
		}
};

int main(){
	
	int m,n,i;
	cin >> m >> n; //m:#vertices,n:#edges
	Graph graph(m);
	for(i=0;i<n;i++){
		int startnode,endnode,cost;
		cin >> startnode >> endnode >> cost;
		graph.addedge(startnode,endnode,cost);
	}
	graph.prim();
	return 0;
}
