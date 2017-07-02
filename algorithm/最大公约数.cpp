#include<iostream>
using namespace std;
int greatest_common_divisor(int a, int b){
	int min = a>b?b:a;
	for(int i=min;i>0;i--){
		if(a%i == 0 && b%i == 0){
			return i;
		}
	}
}
int main(){
	int a,b;
	while(cin>>a){
		cin>>b;
		cout<<greatest_common_divisor(a,b);
		cout<<endl;
	} 
}
