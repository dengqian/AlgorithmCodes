/*第1行为空格隔开的两个正整数N，Q（1 <= N <= 50000，1 <= Q <= 200000）。
 　　第2至第N+1行每行为一个正整数xi（1 <= xi <= 1000000）。
 　　第N+2至第N+Q+1行，每行为空格隔开的两个正整数A，B（1 <= A <= B <= N）。

输出格式

　　输出共Q行，每行一个整数，表示对应[A,B]区间内xi的最大差值。*/
#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<list>

using namespace std;

const int N = 50000;
const int Q = 200000;

struct node{
	int min;
	int max;
};
node num[4 * N +10];

void update(int f,int l,int r,int x,node k){
	if(r == l){
		num[f].min = node.min;
		num[f].max = node.max;
		return;
	}
	int mid = (l + r)>>1;
	if(x <= mid){
		update(f,l,mid,x,k);
		
	}else{
		update(f,mid+1,r,x,k);
	}
}
int main(){
	return 0;
} 
