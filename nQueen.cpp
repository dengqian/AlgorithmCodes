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
        vector<string> tmp;
        NQueens(res, tmp, 0, n);
        return res;
    }
    void NQueens(vector<vector<string> >& res, vector<string>& tmp, int row, int n){
        cout<<tmp[0]<<endl;
        if(tmp.size() == n){
            res.push_back(tmp);
            return;
        }
        for(int i=0; i<n; i++){
            if(isValid(tmp, row, i)){
                tmp[row][i] = 'Q';
                NQueens(res, tmp, row+1, n);
                tmp[row][i] = '.';
            }
        }
    }
    bool isValid(vector<string> str, int row, int col){
        for(int i=0; i<str.size(); i++){
            if (str[i][col] == 'Q') return false;
        }
        for(int i=row-1,j=col-1; i>=0 && j>=0; --i, --j){
            if (str[i][j] == 'Q') return false;
        }
        for(int i=row-1,j=col+1; i>=0 && j<str[i].size(); --i, ++j){
            if(str[i][j] == 'Q') return false;
        }
        return true;
    }
};
int main(){
    Solution* so = new Solution();
    vector<vector<string> > ans = so->solveNQueens(4);
    for(int i=0; i<ans.size(); i++){
        for (int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<endl;
        }
    }
    return 0;
}