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
 
using namespace std;
//using namespace std;
 
int main() {
    int n,k;
 
    cin >> n >> k;
    std::vector<int> father(n+2,0);
    std::vector<char> label(n+2,'#');
 
    for (int i = 0 ; i < n ; i++){
        int left,right;
        int fa = i + 1;
        std :: cin >> left >> right;
        father[left] = fa;
        father[right] = fa;
        label[left] = 'L';
        label[right] = 'R';
    }
    std::string result ="";
    while (k != 1 ){
        result.push_back(label[k]);
        k = father[k];
    }
    std::reverse(result.begin(), result.end());
    std::cout<<  result << std::endl;
}