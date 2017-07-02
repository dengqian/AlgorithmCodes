#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        vector<int> act_pro(n, INT_MIN);
        vector<int> neg_pro(n, INT_MAX);
        act_pro[0] = nums[0]>0 ? nums[0]:0;
        neg_pro[0] = nums[0]<0 ? nums[0]:0;
        int ans = nums[0];
        for(int i =1; i<n; i++){
            if(nums[i] > 0){
                act_pro[i] = max(nums[i], nums[i]*act_pro[i-1]);
                neg_pro[i] = min(0, nums[i]*neg_pro[i-1]);
            }else if(nums[i] < 0){
                act_pro[i] = max(nums[i]*neg_pro[i-1], 0);
                neg_pro[i] = min(nums[i], nums[i]*act_pro[i-1]);
            }else{
                act_pro[i] = 0;
                neg_pro[i] = 0;
            }
            ans = max(ans, act_pro[i]);
        }
        return ans;
    }
};

int main(){
    Solution * s = new Solution();
    vector<int> test;
    int n;
    cin>>n;
    while(n--){
        int tmp;
        cin>>tmp;
        test.push_back(tmp);
    }
    cout<<s->maxProduct(test)<<endl;
}