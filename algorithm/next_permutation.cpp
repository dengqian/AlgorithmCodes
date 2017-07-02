#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;

vector<int> next_permutation(vector<int>& nums) {
    int len = nums.size();
    int i = len-1;
    while(i>=1 && nums[i] <= nums[i-1])
        i--;
    if(i > 0)
        i--;
    int j = len-1;
    while(j>i && nums[j] <= nums[i])
        j--;
    nums[i] = nums[i]+nums[j];
    nums[j] = nums[i]-nums[j];
    nums[i] = nums[i]-nums[j];
    int temp = i+1;
    if(temp != len-1){
        int pos = len-1+temp;
        for(i = temp; i<(pos+1)/2; i++)
        {
            nums[i] = nums[pos-i] + nums[i];
            nums[pos-i] = nums[i] - nums[pos-i];
            nums[i] = nums[i] - nums[pos-i];
        }
    }
    return nums;
}

void permute(vector<int>& nums) {
    int len = nums.size();
    int total=1;
    for(int i=1; i<=len; i++)
        total *= i;
    for(double i=0; i<total; i++){
        for(int i=0; i<len; i++){
            cout << nums[i];
            if(i != len-1)
                cout << " ";
            else cout << endl;
        }
        nums = next_permutation(nums);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> num;
    int tmp;
    for(int i=0; i<n; i++){
        cin>>tmp;
        vector<int> num;
        for(int j=0; j<tmp; j++) num.push_back(j+1);
        permute(num);
    }
}
