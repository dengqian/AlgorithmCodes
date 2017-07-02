#include<iostream>
using namespace std;
int main(){
	char a;
	while(cin>>a){
		cout<<a;
		while((a=cin.get())!='\n'){
			if( a!=' ')
				cout<<a;
		}
		cout<<endl; 
	}
	return 0;
} 
