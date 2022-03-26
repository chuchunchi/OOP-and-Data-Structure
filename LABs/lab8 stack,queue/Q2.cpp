#include <iostream>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    int time,first=0,last=5000;
    queue <int> buffer;
    cin >> n;
    for(int i=0;i<n;i++){
    	cin >> time;
    	buffer.push(time);
    	if(time>=last){
    		last = time;
    		first = last-5000;
		}
		while(buffer.front()<first){
			buffer.pop();
		}
		cout << buffer.size() << ' ';
	}
    return 0;
}
