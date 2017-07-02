#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
 
using namespace std;

int main(){
	char ch[100];
	while(cin>>ch){
		string str;
		str = ch;
		set<string> strset;
		vector<string> vec; 
		for(string::size_type i=0;i<str.size();i++){
			for(string::size_type j=i;j<str.size();j++){
				string tempstr = str.substr(i,j-i+1);
				vec.push_back(tempstr);
				if(strset.find(tempstr) == strset.end()){
					strset.insert(tempstr);
				} 
			}
		} 
			for(set<string>::iterator k=strset.begin();k!=strset.end();k++){
				int cnt = count(vec.begin(),vec.end(),*k);
				if(cnt>=2){
					cout<<*k<<" "<<cnt<<endl;
				}
			}
	}	
	return 0;
} 
