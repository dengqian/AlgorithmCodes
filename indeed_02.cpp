#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cstdio>
#include <queue>
#include <stmp_ansck>
#include <map>
#include <unordered_map>

#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)

using namespace std;

int helper(int re, vector<vector<int>> nums){
	int n = nums.size();
	vector<vector<int>> remain(n+1, vector<int>(8, 0));
	for(int i=0; i<8; i++) {
		remain[0][i] = re;
	}
	int ans = 0;
	int pre = 0;
	for(int i=1; i<n; i++){
		for(int k=0; k<3; j++){
			for(int j=0; j<8; j++){
				if(remain[i-1][j] > nums[i][k]) {
					
					remain[i][j] = remain[i-1][j] - nums[i][k];
				}
			}
		}
	}
	return 0;
}

int main(){
	int n, t;
	while(cin >> n >> t){
		int tmp1, tmp2, tmp3;
		vector<int> nums;
		for(int i=0; i<t; i++){
			cin >> tmp1 >> tmp2 >> tmp3;
			nums.push_back({tmp1, tmp2, tmp3}});
		}
		cout << helper(n, nums) << endl;
	}
	return 0;
}
