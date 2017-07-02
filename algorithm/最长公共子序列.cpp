#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#define N 100

using namespace std;

int dp[N][N];
int info[N][N];
string a, b;

inline int getdp(int i, int j){
	if(i<0 || j<0)
		return 0;
	return dp[i][j];
}
int getpos(int x, int i, int j){
//	int pos = lower_bound(info, info+re+1, x) - info;
	int mx = 0;
	for(int k=j-1; k>=0; k--){
		if(x > b[k])
			mx = max(mx, i==0?0:info[i-1][k]);
	}
	info[i][j] = mx + 1;
	return mx+1;
}

int main (){
//	string a, b;
	while( cin >> a >> b ){
		int lena = a.length();
		int lenb = b.length();
		memset(dp, 0, sizeof(dp));
		memset(info, 0, sizeof(info));
//		info[0] = -1;
		int re = 0;
		for(int i=0; i<lena; i++){
			for(int j=0; j<lenb; j++){
				if(a[i] == b[j]){
					dp[i][j] = getpos(a[i], i, j);
					re = max(re, dp[i][j]);
				}else{
					info[i][j] = i==0?0:info[i-1][j];
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			//	cout << i << " " << j << " " << dp[i][j] << endl;
			}
		}
		cout << "re = " << re << endl;
		for(int i=0; i<lena; i++){
			for(int j=0; j<lenb; j++){
				cout << info[i][j] << " " ;
			}
			cout << endl;
		}
	}
	return 0;
}


/*
最长公共上升子序列 
*/

