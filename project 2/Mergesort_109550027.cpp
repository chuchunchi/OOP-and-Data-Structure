#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
using namespace std;

void mergesort(int*,int,int);
void merge(int*,int,int,int);

int main(){
	while(1){
		int n,i;
		clock_t t;
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
		t = clock();
		mergesort(arr,0,n-1);
		t = float(clock()-t);

		for(i=0;i<n;i++){
			cout << arr[i] << ' ';
		}
		cout << endl;
		cout << "spent time: " << float(t)/CLOCKS_PER_SEC << " seconds" << endl;
		
	}
	return 0;
}

void mergesort(int* A,int l ,int r){
	if(r>l){
		int m = (l+r)/2;
		mergesort(A,l,m);
		mergesort(A,m+1,r);
		merge(A,l,m,r);
		//cout << "f" << endl;
	}
}

void merge(int* A,int l,int m ,int r){
	int left[m-l+1],right[r-m];
	int i,j,k;
	i=0,j=0;
	for(k=l;k<r+1;k++){
		if(k<=m){
			left[i++] = A[k];
		}
		else{
			right[j++] = A[k];
		}
	}
	i=j=0;
	for(k=l;k<r+1;k++){//&&i<(m-l+1)&&j<(r-m)
		if(i>=(m-l+1)){
			A[k] = right[j++];
			continue;
		}
		if(j>=(r-m)){
			A[k] = left[i++];
			continue;
		}
		if(left[i]<=right[j]){
			A[k] = left[i++];
		}
		else if(left[i]>right[j]){
			A[k] = right[j++];
		}
	}
}





