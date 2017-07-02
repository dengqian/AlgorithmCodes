//
//  main.cpp
//  nqueen
//
//  Created by tinyqian on 2016/12/7.
//  Copyright © 2016年 tinyqian. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> flag(5*n - 2, 1);
        vector<string> tmp(n, string(n,'.'));
        NQueens(res, tmp, flag, 0, n);
        return res;
    }
    void NQueens(vector<vector<string> >& res, vector<string>& tmp, vector<int> flag, int row, int n){
        if(row == n){
            res.push_back(tmp);
            return;
        }
        for(int col=0; col<n; col++){
            if(flag[col] && flag[n+row+col] && flag[4*n-2+col-row]){
                tmp[row][col] = 'Q';
                flag[col] = flag[n+row+col] = flag[4*n-2+col-row] = 0;
                NQueens(res, tmp, flag, row+1, n);
                tmp[row][col] = '.';
                flag[col] = flag[n+row+col] = flag[4*n-2+col-row] = 1;
            }
        }
    }
};
int main(){
    Solution* so = new Solution();
    vector<vector<string> > ans = so->solveNQueens(4);
    for(int i=0; i<ans.size(); i++){
        for (int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
