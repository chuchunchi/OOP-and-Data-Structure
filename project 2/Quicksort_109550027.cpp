#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
using namespace std;

void quicksort(int*,int,int);
int partition(int*,int,int);
int main(){

	while(1){
		clock_t starttime,endtime;
		int n,i;
		cin >> n;
		if(n==0){
			break;
		}
		int arr[n];
		for(i=0;i<n;i++){
			int k;
			cin >> k;
			arr[i] = k;
		}
		starttime = clock();
		quicksort(arr,0,n-1);
		endtime = clock();
		for(i=0;i<n;i++){
			cout << arr[i] << ' ';
		}
		cout << endl;
		//cout << starttime << ' ' << endtime << endl;
		cout << "spent time: " << float(float(endtime-starttime)/CLOCKS_PER_SEC)<< " seconds" << endl;
	}
	return 0;
}

void quicksort(int* A,int p,int q){
	if(p<q){
		int r = partition(A,p,q);
		quicksort(A,p,r-1);
		quicksort(A,r+1,q);
	}
}
int partition(int* A,int p,int q){
	int pivot = q;
	int i = p-1;
	for(int j=p;j<=q;j++){
		if(A[j]<=A[pivot]){
			i++;
			swap(A[i],A[j]);
		}
	}
	return i;
}

