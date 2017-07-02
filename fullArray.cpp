#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;
void dfs(vector<int> nums, int start){
        if(start >= nums.size()){
            for(int i = 0 ; i < nums.size(); i++)  
	        {  
	            cout<<nums[i]<<' ';  
	  
	        }  
	        cout<<endl;  
            return;
        }
        else{
            for(int i=start; i<nums.size(); i++){
                swap(nums[start], nums[i]);
                dfs(nums, start+1);
            }
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
        dfs(num, 0);
    	num.clear();
    }
}