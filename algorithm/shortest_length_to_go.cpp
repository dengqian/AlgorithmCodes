/*************************************************************************
	> File Name: top_3_min_num.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年06月04日 星期日 21时42分10秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool notInQueue(priority_queue<int> num, int n){
    while(!num.empty()){
        if(n == num.top()) return false;
        num.pop();
    }
    return true;
}
int helper(vector<int> num){
    priority_queue<int> q;
    for(int i=0; i<num.size(); i++){
        //cout << i << endl;
        if(q.size() < 3 && notInQueue(q, num[i])) q.push(num[i]);
        else{
            if(num[i] < q.top() && notInQueue(q, num[i])){
                q.pop();
                q.push(num[i]);
            }
        }
    }
    return q.size() < 3 ? -1:q.top();
}
int main(){
    int n;
    vector<int> num;
    while(cin >> n){
        int tmp;
        for(int i=0; i<n; i++){
            cin >> tmp;
            num.push_back(tmp);
        }
        cout << helper(num) << endl;
    }
    return 0;
}
