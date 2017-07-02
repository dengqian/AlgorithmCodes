/*输入的第一行有两个正整数,即 N 和 M。(1 ≤ N ≤ 10,1 ≤ M ≤ 10)
　　接下来 N 行按照从最下层到最顶层的顺序给出 N 个窗口的位置。 每行包含四个非负整数 x1, y1, x2, y2,
表示该窗口的一对顶点坐标分别为 (x1, y1) 和 (x2, y2)。保证 x1 < x2,y1 2。
 　　接下来 M 行每行包含两个非负整数 x, y,表示一次鼠标点击的坐标。
 　　题目中涉及到的所有点和矩形的顶点的 x, y 坐标分别不超过 2559 和　　1439。

输出格式

　　输出包括 M 行,每一行表示一次鼠标点击的结果。如果该次鼠标点击选择了一个窗口,则输出这个窗口的编号
(窗口按照输入中的顺序从 1 编号到 N);如果没有,则输出"IGNORED"(不含双引号)。*/
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
