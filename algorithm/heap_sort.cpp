#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <cmath>
#define ll unsigned long long
#define INF (~(1<<31))
using namespace std;

void max_heapify(vector<int> &a, int n, int size){
	int l = 2*n;
	int r = 2*n + 1;
	int large = n;
	if (l<=size && a[l]>a[n])
		large = l;
	else large = n;
	if (r<=size && a[r]>a[large])
		large = r;
	if (large != n){
		int tmp = a[n];
		a[n] = a[large];
		a[large] = tmp;
		max_heapify(a, large, size);
	}

}

void build_max_heap(vector<int> &a){
	int n = a.size()-1;
	for(int i=n/2; i>=1; i--){
		max_heapify(a, i, n);
	}
}

void heap_sort(vector<int> &a){
	build_max_heap(a);
	for(int i=a.size()-1; i>=1; i--){
		int tmp = a[1];
		a[1] = a[i];
		a[i] = tmp;
		max_heapify(a, 1, i-1);
	}
}
int main(){
	int n;
	cin>>n;
	vector<int> v;
	v.push_back(0);
	for(int i=0; i<n; i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	heap_sort(v);
	for(int i=1; i<v.size(); i++){
		cout<<v[i]<<' ';
	}
	return 0;
}














