#include<iostream>
#include<cmath>
using namespace std;
void findPrimeNum(int n[]){
	int k=0;
	for(int i=2;i<1000;i++){
		bool flag = true;
		for(int j=0;j<sqrt(i);j++){
			if(i%j == 0){
				flag = false;
			}
		}
		if(!flag){
			n[k++] = i;
		}
	}
}
void primeDivide(int n[],int t[],int a){
	for(int i=0;n[i]!=0;i++){
		if(n){
			
		}
	}
}
int main(){
	
} 
