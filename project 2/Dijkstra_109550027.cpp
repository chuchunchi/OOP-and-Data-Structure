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
		}
		void dijkstra(int s,int t){
			priority_queue<intpair/*(key,vertexindex)*/, vector<intpair>,greater<intpair> > Q;
			vector<bool> isvisit(v,0);
			vector<int> distant(v);
			vector<int> parent(v);
			for(int i=0;i<v;i++){
				if(i==s){//starting vertex
					distant[i]=0;
					Q.push(make_pair(distant[i],i));
				}
				else{
					distant[i]=inf;
					Q.push(make_pair(distant[i],i));
				}
			}
			
			while(!Q.empty()){
				int cv = Q.top().second;
				Q.pop();
				if(isvisit[cv]){
					continue;
				}
				isvisit[cv] = 1;
				vector<intpair>::iterator i;
				for(i=myadj[cv].begin();i!=myadj[cv].end();++i){
					
					int vertex = (*i).first; // i's vertex number
            		int weight = (*i).second; //weight between i and currentv
					
					if(distant[cv]!=inf &&distant[cv]+weight<distant[vertex]){
						distant[vertex] = distant[cv]+weight;
						parent[vertex] = cv;
						Q.push(make_pair(distant[vertex],vertex));
					}
				}
			}
			cout << distant[t];
		}
};

int main(){
	
	int m,n,i,start,target;
	cin >> m >> n; //m:#vertices,n:#edges
	cin >> start >> target;
	Graph graph(m);
	for(i=0;i<n;i++){
		int startnode,endnode,cost;
		cin >> startnode >> endnode >> cost;
		graph.addedge(startnode,endnode,cost);
	}
	graph.dijkstra(start,target);
	return 0;
}
