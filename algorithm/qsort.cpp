#include<iostream>
using namespace std;

void quickSort(int * num,int start,int end){
	if(start>=end){
		return;
	}
	int key = num[start];
	int low = start;
	int high = end;
	while(low<high){
		while(low<high && num[high]>=key){
			--high;
		}
		num[low] = num[high];
		while(low<high && num[low]<=key){
			++low;
		}
		num[high] = num[low];
	}
	num[low] = key;
	quickSort(num, start, low-1);
	quickSort(num, high+1, end);
}
int main(){
	int n;
	while(cin>>n){
		int * num = new int[n];
		for(int i=0; i<n; i++){
			cin>>num[i];
		} 
		quickSort(num, 0, n-1);
		for(int j=0; j<n; j++){
			cout<<num[j]<<" ";
		}
		cout<<endl;
		delete num;
	}
	return 0;
} 
