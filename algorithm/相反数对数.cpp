/*输入格式

　　第一行包含一个正整数 N。(1 ≤ N ≤ 500)。
 　　第二行为 N 个用单个空格隔开的非零整数,每个数的绝对值不超过1000,保证这些整数各不相同。

输出格式

　　只输出一个整数,即这 N 个数中包含多少对相反数。*/
#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<list>
#include<map>

using namespace std;

int main(){
	int n;
	while(cin>>n){
		map<int,int> m;
		int temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			if(temp< 0){
				temp = 0 - temp;
			}
			m[temp]++;
		}
		int count = 0;
		for(map<int,int>::iterator k=m.begin();k!=m.end();k++){
			if(k->second == 2){
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
