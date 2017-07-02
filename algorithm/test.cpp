#include<iostream>
#include<vector>
using namespace std;
int main(){
	char a;
	while(cin>>a){
		vector<char> ch;
		ch.push_back(a);
		while((a=cin.get())!='\n'){
			ch.push_back(a);
		}
		for(int i=0;i<ch.size();i++){
			if(ch[i] != ' '){
				cout<<ch[i];	
			}
		}
		vector <char>().swap(ch);  
	//	ch.swap(vector<char>()) ;  
	}
	return 0;
} 
