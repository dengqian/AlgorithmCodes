/*�����ʽ

������һ�а���һ�������� N��(1 �� N �� 500)��
 �����ڶ���Ϊ N ���õ����ո�����ķ�������,ÿ�����ľ���ֵ������1000,��֤��Щ����������ͬ��

�����ʽ

����ֻ���һ������,���� N �����а������ٶ��෴����*/
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
