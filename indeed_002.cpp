#include <vector>
#include <iostream>
#include <map>
#include <stack>
#include <cmath>
#include <sstream>
#include <memory>
#include <cassert>
#include <set>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include "stdio.h"
 
typedef long long LL;
using namespace std;
 
 
int main() {
    LL t;
    int n;
    int m = 10;
    cin >> n >> t;
    vector<int> a(n+m, 0);
    vector<vector<int>> nums(n+m, vector<int>(100, 0));
 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        nums[i][0] = a[i];
    }
 
    for (int j = 1; j <= 70; j++) {
        for (int i = 1; i <= n; i++) {
            nums[i][j] = nums[nums[i][j - 1]][j - 1];
        }
    }
 
    for (int i = 1; i <= n; i++) {
        nums[i][0] = a[i];
    }
 
    for (int i = 1; i <= n; i++) {
        int cur = i;
        for (int j = 63; j >= 0; j--) {
            LL tmp = 1ll << j;
            if(t & tmp) {
                cur = nums[cur][j];
            }
 
        }
        cout << cur << endl;
    }
 
    return 0;
}