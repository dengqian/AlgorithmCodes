/*����ĵ�һ��������������,�� N �� M��(1 �� N �� 10,1 �� M �� 10)
���������� N �а��մ����²㵽����˳����� N �����ڵ�λ�á� ÿ�а����ĸ��Ǹ����� x1, y1, x2, y2,
��ʾ�ô��ڵ�һ�Զ�������ֱ�Ϊ (x1, y1) �� (x2, y2)����֤ x1 < x2,y1 2��
 ���������� M ��ÿ�а��������Ǹ����� x, y,��ʾһ������������ꡣ
 ������Ŀ���漰�������е�;��εĶ���� x, y ����ֱ𲻳��� 2559 �͡���1439��

�����ʽ

����������� M ��,ÿһ�б�ʾһ��������Ľ��������ô������ѡ����һ������,�����������ڵı��
(���ڰ��������е�˳��� 1 ��ŵ� N);���û��,�����"IGNORED"(����˫����)��*/
#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<list>
#include<map>
#include<limits.h>
#include<algorithm>

using namespace std;
struct node{
	int id;
	int x1;
	int y1;
	int x2;
	int y2;
};
void cmp(node n1,node n2){
	return;
}
int min(int a,int b){
	return a<b ? a:b; 
}
int max(int a,int b){
	return a>b ? a:b;
}
int main(){
	int n,m;
	vector<node> vec;
	while(cin>>n>>m){
		node temp={0,0,0,0,0};
		for(int i=0;i<n;i++){
			cin>>temp.x1>>temp.y1>>temp.x2>>temp.y2;
			temp.id = i + 1;
			vec.push_back(temp);
		} 
		for(int k=0;k<m;k++){
			int x,y;
			cin>>x>>y;
			int x1,y1,x2,y2;
			vector<node>::iterator j = vec.end()-1;
			for(j;j+1 != vec.begin();j--){
				x1 = (*j).x1; 
				x2 = (*j).x2;
				y1 = (*j).y1;
				y2 = (*j).y2;
			//	cout<<x1<<' '<<x2<<' '<<y1<<' '<<y2<<endl;
				if(j == vec.end()){
					if(x>=x1&&x<=x2 && y>=y1&&y<=y2){
						cout<<(*j).id<<endl;
						break;
					}
				}else{
					if(x>=x1&&x<=x2 && y>=y1&&y<=y2){
						cout<<(*j).id<<endl;
						node tempnode = *j;
						vec.erase(j);
						vec.push_back(tempnode);
						break;
					}
				}
			}
			if(j+1 == vec.begin()){
				cout<<"IGNORED"<<endl;
			}	
		} 
	} 
	return 0;
}
