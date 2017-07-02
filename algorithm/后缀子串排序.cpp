#include<iostream>
#include<string>
#include<cstring>
#include<set>

using namespace std;

int main(){
	string str;
	char s[500];
	while(cin>>s){
		set<string> strset;
		str=s; 
		int len=strlen(s);
		for(int i=0;i<len;i++){
			string subStr=str.substr(i,len-i);
		//	cout<<subStr<<endl;
			strset.insert(subStr);
		}
		//cout<<strset.size()<<endl;
		for(set<string>::iterator j=strset.begin();j!=strset.end();j++){
			cout<<*j<<endl;
		}
	}
}
