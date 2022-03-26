#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,i,key,lindex,qindex,index;
    cin >> N;
    int lprob[19] = {0},qprob[19] = {0};
    int qind[19] = {0};
    for(i=0;i<N;i++){
    	cin >> key;
    	lindex = qindex = key%19;
    	while(lprob[lindex]!=NULL){
    		lindex++;
    		if(lindex>18){
    			lindex = lindex%19;
			}
		}
		lprob[lindex] = key;
		
		if(qprob[qindex]==NULL){
			qprob[qindex] = key;
			qind[qindex]++;
			continue;
		}
		do{
			index = qindex + (qind[qindex])*(qind[qindex]);
			//cout << endl << index << qindex << qind[qindex]<< endl;
			qind[qindex]++;
			if(index>18){
				index = index%19;
			}
		}while(qprob[index]!=NULL);
		qprob[index] = key;
		qind[index]++;
		
	}
	for(i=0;i<19;i++){
		cout << lprob[i] << ' ';
	}
	cout << endl;
	for(i=0;i<19;i++){
		cout << qprob[i] << ' ';
	}
    return 0;
}

