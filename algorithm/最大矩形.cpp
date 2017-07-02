#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<list>
#include<map>
#include<limits.h>
#include<algorithm>

using namespace std;

int main(){
	int n;
	vector<int> num;
	while(cin>>n){
		int temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			num.push_back(temp);	
		} 
		int maxArea = 0;
		for(vector<int>::iterator j=num.begin();j!=num.end();j++){
			int len = *j;
			int wid = -1;
			for(vector<int>::iterator k=j;k!=num.end();k++){
			//	cout<<*k<<' '<<len<<endl;
				if(*k>=len){
					wid ++;
				}else{
					break;
				}
			}
			for(vector<int>::iterator l=j;l!=num.begin()-1;l--){
				if(*l>=len){
					wid ++;
				}else{
					break;
				}
			}
			int area = len * wid;
		//	cout<<wid<<endl;
		//	cout<<area<<endl;
			if(area > maxArea){
				maxArea = area;
			} 
		}
		cout<<maxArea<<endl;
	}
	return 0;
}
