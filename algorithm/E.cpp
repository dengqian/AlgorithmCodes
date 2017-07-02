#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#define N 100000
#define MOD 1000000007

using namespace std;

int sum[4 * N  + 10];

void update(int f, int l, int r, int x, int k){
	if(l == r){
		k = (x%2==0 ? k : -k);
		sum[f] = k;
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid){
		update(f << 1, l, mid, x, k);
	}else{
		update(f << 1 | 1, mid+1, r, x, k);
	}
	sum[f] = sum[f << 1] + sum[f << 1 | 1];
//	printf("[%d %d]\n", f, sum[f]);
	return ;
}

int qu(int f, int l, int r, int lx, int rx){
	if(lx > rx){
		return 0;
	}
	if(l == lx && r == rx){
		if(l == r){
			return (l%2==0 ? sum[f] : -sum[f]);
		}
		return sum[f];
	}
	int mid = (l + r) >> 1;
	if(rx <= mid){
		return qu(f << 1, l, mid, lx, rx);
	}else if(lx > mid){
		return qu(f << 1 | 1, mid+1, r, lx, rx);
	}else{
		int a = qu(f << 1, l, mid, lx, mid);
		int b = qu(f << 1 | 1, mid+1, r, mid+1, rx);
		if((mid - lx + 1) % 2 == 0){
			return a + b;
		}else{
			return a - b;
		}
	}
}

int main (){
	int T;
	scanf("%d", &T);
	while(T--){
		char p[N + 10];
		scanf("%s", p);
		int len = strlen(p);
		
		memset(sum, 0, sizeof(sum));
		
		for(int i=0; i<len; i++){
			update(1, 0, len-1, i, p[i]-'0');
	/*		for(int j=1; j<6; j++){
				printf("%d..", sum[j]);
			}
			printf("\n");*/
		}
		int quary;
		scanf("%d", &quary);
		while(quary --){
			int t;
			scanf("%d", &t);
			if(t == 1){
				int a, b;
				cin >> a >> b;
				a--;
				update(1, 0, len-1, a, (int)b);
			}else{
				long long a, b;
				cin >> a >> b;
				a--;
				b--;
				
				cout << "[ " << t  << " " << a << " "<< b << " ]" << endl;
				if(a / len == b / len){
					cout << qu(1, 0, len-1, a % len, b % len) % MOD << endl;
					continue;
				}
				
				long long aa = a / len;
				long long aaa = ((aa+1) * len)-1;
				int re1 = qu(1, 0, len-1, a % len, aaa % len);
				
				long long bb = b / len;
				long long bbb = (bb * len);
				int re2 = qu(1, 0, len-1, bbb % len, b % len);
				
				long long num = (bbb - aaa + 1) / len;
				
				long long re3 = num * sum[1];
				
				long long re = re1 + ((aaa - a + 1) % 2 == 0 ? re3 : -re3) + ((bbb - a + 1) % 2 == 0 ? re2 : -re2);
				re %= MOD;
				cout << re << endl;
			}
		}
	}
    return 0;
}
