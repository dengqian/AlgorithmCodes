#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

void print_vector(vector<int> nums){
    for(int i=0; i<nums.size(); i++) cout<<nums[i]<<' ';
    cout<<endl;
}
int find_max(vector<int> nums){
    int max = nums[0];
    for(int i=1; i<nums.size(); i++){
        max = nums[i]>max ? nums[i]:max;
    }
    return max;
}
vector<int> counting_sort(vector<int> nums){
    int max_item = find_max(nums);
    int n = nums.size();
    vector<int> tmp(max_item+1, 0);
    vector<int> res(n+1, 0);
    for(int i=0; i<n; i++){
        tmp[nums[i]] = tmp[nums[i]] + 1;
    }
    for (int i=1; i<=max_item; i++){
        tmp[i] = tmp[i]+tmp[i-1];
    }
    for (int i=n-1; i>=0; i--){
        res[tmp[nums[i]]] = nums[i];
        tmp[nums[i]] --;
    }
    print_vector(res);
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    int tmp;
    for(int i=0; i<n; i++){
        cin>>tmp;
        nums.push_back(tmp);
    }
    nums = counting_sort(nums);
    print_vector(nums);
}
