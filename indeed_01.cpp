#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cstdio>
#include <queue>
#include <stmp_ansck>
#include <map>
#include <cctype>
#include <unordered_map>

#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)

using namespace std;

int helper(vector<int> nums, vector<int> skip){
	int n=0;
	for(int i=0; i<nums.size(); i++){
		n = max(nums[i], n);
	}; 
	unordered_map<int, bool> m;
	for(int i=0; i<skip.size(); i++){
		m[skip[i]] = true;
	}
	vector<int> rn(n+1, 0);
	int cur_nums = 0;
	for(int i=1; i<=n; i++){
		cur_nums = rn[i-1]+1;
		while(m[cur_nums] == true) cur_nums++;
		rn[i] = cur_nums;
	}
	for(int i=0; i<nums.size(); i++){
		cout<<rn[nums[i]]<<endl;
	}
	return 0;
}

int main(){
	int n,m;
	while(cin >> n >> m){
		int tmp;
		vector<int> nums;
		for(int i=0; i<n; i++){
			cin >> tmp;
			nums.push_back(tmp);
		}
		vector<int> skip;
		for(int i=0; i<m; i++){
			cin >> tmp;
			skip.push_back(tmp);
		}
		helper(nums, skip);
	}
	return 0;
}
