#include<iostream>
using namespace std;
int main(){
	int n = 3;
	int * num = new int[n];
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	for(int j=0;j<n;j++){
		cout<<num[j];
	}
	return 0;
}
