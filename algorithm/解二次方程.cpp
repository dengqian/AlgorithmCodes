/*x^2+x=3x+4*/
#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;

int main(){
	char aa[50];
	char op[] = "+-=";
	while(cin>>aa){
		string s;
		s = aa;
		float a=0,b=0,c=0;
		bool left = true;
		bool neg = false;
		int pos1 = -1;
		int pos2 = 0;
		while(pos2<s.length()){
			pos2=s.find_first_of(op,pos1+1);
			if(pos2 == s.npos){
				pos2 = s.length();
			}
		//	cout<<pos2<<endl;
				string tempstr = s.substr(pos1+1,pos2-pos1-1);
		//		cout<<tempstr<<endl;
				if(tempstr.find('x',0) == tempstr.npos){
					if(left&&!neg || !left&&neg){
						c += atoi(tempstr.c_str());
					}else{
						c -= atoi(tempstr.c_str());
					}
				}else if(tempstr.find('^',0) == tempstr.npos){
					if(tempstr.length()>1){
						tempstr=tempstr.substr(0,tempstr.length()-1);	
					}else{
						tempstr='1';
					} 
					if(left&&!neg || !left&&neg){
						b += atoi(tempstr.c_str());
					}else{
						b -= atoi(tempstr.c_str());
					}
				}else{
					if(tempstr.length()>3){
						tempstr=tempstr.substr(0,tempstr.length()-3);	
					}else{
						tempstr='1'; 
					}
					if(left&&!neg || !left&&neg){
						a += atoi(tempstr.c_str());
					}else{
						a -= atoi(tempstr.c_str());
					}
		//			cout<<a<<endl;
				}
			
			pos1 = pos2;
			if(pos2<s.length()){
				if(s.at(pos2) == '='){
					left = false;
				}
				if(s.at(pos2) == '-'){
					neg = true;
				}else{
					neg = false;
				}
			}
		//	cout<<left<<" "<<neg<<endl;
		}
		int del = b*b-4*a*c;
		float ans0,ans1;
	//	cout<<a<<" "<<b<<" "<<c<<endl;
		if(del>=0){
			ans0 = (-b-sqrt(del))/(2.0*a);
			ans1 = (-b+sqrt(del))/(2.0*a);
			cout.setf(ios::fixed);
			cout.precision(2);
			if(ans0==0&&ans1==0)
				cout<<0<<" "<<0<<endl;
			else
				cout<<ans0<<" "<<ans1<<endl;
		}else{
			cout<<"No Solution"<<endl;
		}
	} 
	return 0;
} 
