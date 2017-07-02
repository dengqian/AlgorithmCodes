#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> v, int N, int M, int step) {  
        queue<int> q;  
        vector<vector<int>> d;
        for (int i=0; i<N; ++i)  
            for (int j=0; j<M; ++j)  
                d[i][j] = v[i][j];  
  		int ans = 0;
        q.push(make_pair(0, 0));  
  
        while (step--) {
        	while(!q.empty()){
        		queue<int> que; 
        		int r = q.top().first; 
        		int l = q.top().second;
        		q.pop();
        		int max = 0;
	            for(int i=-1; i<=1; i++){
	            	for(int j=-1; j<=1; j++){
	            		if(r+i>=0 && l+j >=0 && i != j) {
	            			max = max > d[r+i][l+j] ? max:d[r+i][l+j];
	            			que.push(make_pair(r+i, l+j));
	            		}
	            	}
	            }
	            q = que;
	            d[r][l] += max;
	            ans = ans>d[r][l] ? ans:d[r][l];
        	}
        }  
        return ans * 2;  
}  
int main(){
	int n; 
	cin>>n;
	while(n--){
		vector<vector<int>> v;
		int r, l;
		cin>>r>>l;
		int step;
		cin>>step;
		while(r--){
			vector<int> row;
			while(l--) {
				int tmp;
				cin>>tmp;
				row.push_back(tmp));
			}
			v.push_back(row);
		}
		cout<<bfs(v, step/2, step/2, step);
	}
}