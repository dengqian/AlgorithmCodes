#include<iostream>
#include<cstring>
#include<string>
#include<set>
 
using namespace std;

int main(){
	set<char> tree;
	int n;
	while(cin>>n && n){
		char str[10];
		string a;
		cin>>str;
		for(int i=0;i<strlen(str);i++){
			if(tree.find(str[i]) == tree.end())
				tree.insert(str[i]);
		}
		for(set<char>::iterator ii=tree.begin();ii!=tree.end();ii++){
			a += *ii; 
		}
		for(int j=0;j<n;j++){
			set<char> temptree;
			char tempstr[10];
			string b;
			cin>>tempstr;
			for(int k=0;k<strlen(tempstr);k++){
				if(temptree.find(tempstr[k]) == temptree.end())
					temptree.insert(tempstr[k]);
			}
			for(set<char>::iterator kk=temptree.begin();kk!=temptree.end();kk++){
				b += *kk;
			} 
			if(a == b){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
}
