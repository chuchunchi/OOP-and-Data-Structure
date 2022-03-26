#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

class edge{
    public:
        int start;
        int end;
        int weight;
        
        edge* sortedge(edge* edges,int n){
            std::sort(edges,edges+n);
            return edges;
        }
        bool operator <(const edge& e1){
            return weight < e1.weight;
        }

};

int findset(set<int> *sets,int m,int v){
    for(int i=0;i<m;i++){
        if(sets[i].find(v)!=sets[i].end()){
            //cout << endl << "i=" << i << endl;
            return i;
        }
    }
    return 0;
}

/*void Union(set<int> set1,set<int> set2){
    if(set1==set2){
        return;
    }
    else{
        if(set1.size()>set2.size()){
            set1.insert(set2.begin(),set2.end());
            set2.clear();
        }
        else{
            set2.insert(set1.begin(),set1.end());
            set1.clear();
        }
    }
}*/

int main(){
    int m,n,i;
    cin >> m >> n; //m:#vertices,n:#edges
    
    //make set
    std::set<int> sets[m];
    for(i=0;i<m;i++){
        sets[i].insert(i);
    }
    
    edge edges[n];
    for(i=0;i<n;i++){
        int startnode,endnode,cost;
        cin >> startnode >> endnode >> cost;
        edges[i].start = startnode;
        edges[i].end = endnode;
        edges[i].weight = cost;
    }
    edges->sortedge(edges,n);
    int total=0;
    for(i=0;i<n;i++){
        int a = findset(sets,m,edges[i].start), b = findset(sets,m,edges[i].end);
        if(a!=b){
            //Union(sets[edges[i].start],sets[edges[i].end]);
            
            //cout << edges[i].weight << endl;
            //cout << "sets1: " << edges[i].start << " sets2: " << edges[i].end << endl;
            if(sets[a]==sets[b]){
                continue;
            }
            else{
                if(sets[a].size()>sets[b].size()){
                    sets[a].insert(sets[b].begin(),sets[b].end());
                    sets[b].clear();
                }
                else{
                    sets[b].insert(sets[a].begin(),sets[a].end());
                    sets[a].clear();
                }
            }
            //cout << endl << edges[i].weight << endl;
            total+=edges[i].weight;
        }
    }
    cout << total;
    
    return 0;
}
