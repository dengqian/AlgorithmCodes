#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<limits>

using namespace std;


int main(){
	int n,m; 
	int i,j,k;
	int max=numeric_limits<int>::max();
	int rou[100][100];
	memset(rou,-1,sizeof(rou));
	int vst[100]={0};
	int dis[100]={0};
	while(cin>>n>>m){
		int x,y;
		for(i=0;i<m;i++){
			cin>>x>>y;
			rou[x][y] = i;		
			rou[y][x] = i;	
		}
		
	}
	
	return 0;
}

