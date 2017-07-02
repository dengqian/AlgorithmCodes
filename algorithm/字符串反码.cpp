#include<iostream>
#include<cstring> 

using namespace std;
int main(){
	char str[80];
	while(cin.getline(str,80)&& strcmp(str,"!")!=0){
		for(int i=0;i<strlen(str);i++){
			if(str[i]<='z' && str[i]>='a'){
				int len = str[i] - 'a';
				str[i] = 'z' - len; 
			}else if(str[i]<='Z' && str[i]>='A'){
				int len = str[i] - 'A';
				str[i] = 'Z' - len; 
			}
		}
		for(int j=0;j<strlen(str);j++){
			cout<<str[j];
		} 
		cout<<endl;	
	}
	return 0;
}
