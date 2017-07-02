/*给定n，a求最大的k，使n！可以被a^k整除但不能被a^(k+1)整除。
!!!!!思路错误，1000！根本不能表示！！！ 
*/
#include<iostream>
#include<cmath>
using namespace std;

unsigned long fact(int n){
	if(n<=1){
		return 1;
	}
	unsigned long num = 1; 
	for(int i=1;i<=n;i++){
		num *= i; 
	}
	return num;
}
int getMaxOrder(unsigned long n,int a){
	int num = a;
	int i = 0;
	for(i=0;num<=n;i++){
		num = num*a;
		cout<<num<<endl; 
	}
	return i;
}
int findK(int n,int a){
	unsigned long num = fact(n);
	cout<<"阶乘："<<num<<endl;
	cout<<a<<endl;
	int order = getMaxOrder(num,a);
	cout<<order<<endl;
	cout<<a<<" "<<pow(a,order)<<endl;
	for(int i=order;i>=0;i--){
		if(num%long(pow(a,i))==0 && num%long(pow(a,(i+1)))!=0){
			cout<<i<<endl;
			return i;
		}
	}
	return 0;
}
int main(){
	int n;
	while(cin>>n){
		int a;
		cin>>a;
		int k = findK(n,a);
		cout<<k<<endl;
	}
} 
