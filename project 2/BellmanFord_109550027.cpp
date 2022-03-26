#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int inf = std::numeric_limits<int>::max();
class edge{
    public:
        int start;
        int end;
        int weight;
};

void bellmanford(int m,int n,int s,int t,edge* edges){
	vector<int> distant(m,0);
	for(int i=0;i<m;i++){
		if(i!=s){
			distant[i] =inf;
		}
	}
	
	for(int i=0;i<m-1;i++){
		for(int j=0;j<n;j++){
			int start = edges[j].start;
			int end = edges[j].end;
			int weight = edges[j].weight;
			//cout << "start: " << start <<endl << "end: " << end << endl << "weight: " << weight << endl;
			if(distant[start]!=inf && distant[start]+weight<distant[end]){
				distant[end] = distant[start] + weight;
			}
			cout<< "disstart: " << distant[start] << "   w: " << weight << "   disend: " <<  distant[end] << endl;
		}
	}
	//cout << distant[t] << endl ;
	for(int j=0;j<n;j++){
			int start = edges[j].start;
			int end = edges[j].end;
			int weight = edges[j].weight;
			//cout<< distant[start] << " " << weight << endl <<  distant[end] << endl;
			
			if(distant[start]!=inf && distant[start]+weight<distant[end]){
				cout << "Negative loop detected!";
				
				return;
			}
	}
	cout << distant[t];
	
}

int main(){
    int m,n,i;
    cin >> m >> n; //m:#vertices,n:#edges
    int s,t;
    cin >> s >> t;//start,target
    
    edge edges[n];
    for(i=0;i<n;i++){
        int startnode,endnode,cost;
        cin >> startnode >> endnode >> cost;
        edges[i].start = startnode;
        edges[i].end = endnode;
        edges[i].weight = cost;
    }
    bellmanford(m,n,s,t,edges);
    
    return 0;
}
