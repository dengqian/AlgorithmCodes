#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<list>
 
using namespace std;

int main(){
	int n;
	cin>>n;
	map<int,int> f;
	for(int i=0;i<n;i++){
		int m;
		cin>>m;
		f[m]++;
	}
	int ans,m=0;
	for(map<int,int>::iterator it=f.begin();it!=f.end();it++){
		if(it->second > m){
			m = it->second;
			ans = it->first; 
		}
	}
	cout<<ans<<endl;
	return 0;	
} 
