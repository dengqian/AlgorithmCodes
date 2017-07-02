#include<iostream>
#include<limits>
#include<cmath>
using namespace std;
int main(){
	int max = numeric_limits<int>::max();
	int i,j,k;
	int a[100][100];
	int len[100]={0};
	int vst[100]={0};
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			a[i][j] = 0;
		}
	}
	int m,n;
	while(cin>>n>>m){
		for(i=0;i<n;i++){
			len[i] = max;
		} 
		len[0] = 0;
		k=0;
		int x,y;
		for(j=0;j<m;j++){
			cin>>x>>y;	
			a[x][y] = (int)pow(2,j);
		}
		for(i=0;i<n;i++){
			int min = max;
			for(j=0;j<n;j++){
				if(vst[j]==0 && len[j]<min){
					min = len[j];
					k=j;
				}
			}
			vst[k] = 1;
			cout<<k<<endl;
			for(j=0;j<n;j++){
				if(a[k][j]!=0 && vst[j]==0 && a[k][j]+len[k]<len[j]){
					len[j] = a[k][j]+len[k];
				}
			}
		}
		for(i=1;i<n;i++){
			cout<<len[i]<<endl;
		}
	}
}
