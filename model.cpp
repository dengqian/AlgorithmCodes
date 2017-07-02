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

int helper(vector<int> nums){
	return 0;
}

int main(){
	int n;
	while(cin >> n){
		int tmp;
		vector<int> nums;
		for(int i=0; i<n; i++){
			cin >> tmp;
			nums.push_back(tmp);
		}
		cout << helper(nums) << endl;
	}
	return 0;
}
