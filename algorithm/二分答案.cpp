#include <iostream>

using namespace std;

int findpos(int *a, int p,int n){
	int i=0;
	while(a[i]<p){
		i++;
	}
	return i;
}

int find(int *a, int l, int r, int p){
	int ans = -1; 
	while(l <= r){
		int mid = (l+r) >> 1;
		if(a[mid] >= p){
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	return l;
}
int find(int *a, int l, int r, int p){
	int ans = -1; 
	while(l <= r){
		int mid = (l+r) >> 1;
		if(a[mid] <= p){
			l = mid - 1;
		}else{
			r = mid + 1;
		}
	}
	return r;
}
int main(){
	return 0;
} 
