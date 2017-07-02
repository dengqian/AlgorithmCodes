#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<list>
 
using namespace std;

int main(){
	string s;
	while(cin>>s){
		int a[10]={0};
		int num;
		int k=0;
		for(int i=0;i<12;i++){
			if(s[i] == '-'){
				continue;
			}else{
				a[k++] = s[i] - '0';
			}
		}
		int ans = 0;
		for(int j=0;j<9;j++){
		//	cout<<a[j]<<endl;
			ans += a[j]*(j+1);
		}
		ans = ans%11;
		char ans1;
		if(ans == 10){
			ans1 = 'X';
		}else{
			ans1 = ans + '0';	
		} 
	//	cout<<ans<<' '<<ans1<<endl;
		if(ans1 == s[12]){
			cout<<"Right"<<endl;
		}else{
			s[12] = ans1;
			cout<<s<<endl;
		}
	}
	return 0;
} 
