/*��1��Ϊ�ո����������������N��Q��1 <= N <= 50000��1 <= Q <= 200000����
 ������2����N+1��ÿ��Ϊһ��������xi��1 <= xi <= 1000000����
 ������N+2����N+Q+1�У�ÿ��Ϊ�ո����������������A��B��1 <= A <= B <= N����

�����ʽ

���������Q�У�ÿ��һ����������ʾ��Ӧ[A,B]������xi������ֵ��*/
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
