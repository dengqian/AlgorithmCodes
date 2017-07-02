#include<iostream>
#include<limits>
#include<cmath>
using namespace std;

int main(){
	int n,m; 
	int i,j,k;
	int max=numeric_limits<int>::max();
	int rou[100][100];
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			rou[i][j] = 0;
		}
	}
	int vst[100]={0};
	int dis[100]={0};
	while(cin>>n>>m){
		for(i=1;i<n;i++){
			dis[i] = max;
		}
		int x,y;
		for(i=0;i<m;i++){
			cin>>x>>y;
			rou[x][y] = (int)pow(2,i)%100000;		
			rou[y][x] = (int)pow(2,i)%100000;	
		}
		int min;
		for(i=0;i<n;i++){
			min = max; 
			for(j=0;j<n;j++){
				if(!vst[j] && dis[j]<min){
					min = dis[j];
					k = j;
				}
			}
		//	cout<<"k:"<<k<<endl;
			vst[k] = 1;
		//	cout<<"min:"<<min<<endl;
			for(j=0;j<n;j++){
				if(!vst[j] && rou[k][j]!=0 && rou[k][j]+dis[k]<dis[j]){
			//		cout<<j<<" "<<rou[k][j]<<" "<<dis[j]<<endl;
					dis[j] = rou[k][j] + dis[k];
				}
			}
		}
		for(i=1;i<n;i++){
			if(dis[i] == max){
				cout<<"-1"<<endl;
			}else{
				cout<<dis[i]%100000<<endl;		
			}
		}
	}
	return 0;
} 
