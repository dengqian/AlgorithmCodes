#include<iostream>
using namespace std;
void qsort(int num[],int start,int end){
	if(start>=end){
		return;
	}
	int first = start;
	int last = end;
	int key = num[first];
	while(first<last){
		while(first<last && num[last]>=key){
			--last;
		}
		num[first]=num[last];
		while(last>first && num[first]<=key){
			++first;
		}
		num[last]=num[first];
	}
	num[first]=key;
	qsort(num,start,first-1);
	qsort(num,last+1,end);
}
int main(){
	const int N = 100;
	int num[N]={0};
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>num[i];
		} 
		qsort(num,0,n-1);
		for(int j=0;j<n;j++){
			cout<<num[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
 
