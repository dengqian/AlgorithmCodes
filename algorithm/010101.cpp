#include<iostream>
#include<set>
#include<vector>
#include<algorithm> 
using namespace std;

int main(){
	char str[100];
	string s;
	while(cin>>str){
		s = str;
		vector<string> vec;
		set<string> strset;
		for(string::size_type i=0;i<s.size();i++){
			for(string::size_type j=i;j<s.size();j++){
				string subs = s.substr(i,j-i+1);
				vec.push_back(subs);
				if(strset.find(subs) == strset.end()){
					strset.insert(subs);
				}
			}
		}
		for(set<string>::iterator k=strset.begin();k!=strset.end();k++){
			if(count(vec.begin(),vec.end(),*k)>1){
				cout<<*k<<endl;
			}
		}
	}
	return 0;
}
