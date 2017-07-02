#include<iostream>
#include<vector>
using namespace std;
int main(){
	char a;
	vector<char> ch;
	while(cin>>a){
		while((a=cin.get())!='\n'){
			ch.push_back(a);
		}
		for(int i=0;i<ch.size();i++){
			if(ch[i] != ' '){
				cout<<ch[i];	
			}
		}
		ch.clear();
	}
	return 0;
} 
