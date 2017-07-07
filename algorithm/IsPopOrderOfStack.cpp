#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <cmath>
#define ll unsigned long long
#define INF (~(1<<31))
using namespace std;

bool IsPopOrder(vector<int>& in, vector<int>& out){
	stack<int> pushed, poped;
	reverse(out.begin(), out.end());
	for(auto it : out){
		poped.push(it);
	}
	for(auto it : in){
		if (it == poped.top()){
			poped.pop();
		}else{
			pushed.push(it);
		}
	}
	while(!poped.empty()){
		if(poped.top() != pushed.top()) return false;
		poped.pop();
		pushed.pop();
	}
	return true;
}
int main(){
	vector<int> in {1,2,3,4,5};
	vector<int> out {4,5,3,2,1};
	if(IsPopOrder(in, out)){
		cout<<"is pop order"<<endl;
	}
}