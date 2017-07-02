#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<list>
#include<map>
#include<limits.h>
#include<algorithm>

using namespace std;

long long count = 0;
struct node{
	long long count[16];
};
int main(){
	node a[1000];
	memset(a,0,sizeof(a));
	int n;
	while(cin>>n){
		a[3].count[15] = ;
		for(int i=4;i<n;i++){
			for(int j=0;j<16;j++){
					a[i].count[j] = a[i-1].count[j];
			}
		}
	}
	return 0;
} 
