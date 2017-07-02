#include<iostream.h>
//#include<queue.h>

int* pos;//图遍历器数组

class graph{

	int vertices;
	char **a;
public:

	char** Geta(){
		return a;
	}
//初始化邻接矩阵,由用户输入
	void Input(){
		a=new char*[vertices];
		cout<<"请输入图的顶点数:"<<endl;
		cin>>vertices;
		cout<<"请输入对应的邻接矩阵（∞用*代替）:"<<endl;
		for(int i=0;i<vertices;i++){
			a[i]=new char[vertices];
			for(int j=0;j<vertices;j++)
				cin>>a[i][j];
		}
	}


//判断是无向图还是有向图（邻接矩阵是否对称）
	bool directed_graph(){
		for(int i=1;i<vertices;i++){
			for(int j=i;j<vertices;j++){
				if(a[i][j]!=a[j][i])
					return true;
			}
		}
		for(i=0;i<vertices;i++)
			if(a[i][i]!='*'){
				cout<<"它不是简单图"<<endl;
				break;
			}
		return false;
	}

//邻接矩阵的遍历函数
	int Begin(int i,int* &pos){  //返回第一个与定点i邻接的顶点
		if(i<0||i>=vertices){
			cout<<"wrong!";
			return -1;
		}
		for(int j=0;j<vertices;j++){
			if(a[i][j]!='*'){
				pos[i]=j;
				return j;
			}
		}
		pos[i]=vertices;//没有邻接顶点
		return -1;
	}
	int Next(int i){     //返回下一个与顶点i邻接的顶点
		if(i<0||i>=vertices){
			cout<<"wrong!";
			return -1;
		}
		for(int j=pos[i]+1;j<vertices;j++){
			if(a[i][j]!='*'){
				pos[i]=j;
				return j;
			}
		}
		pos[i]=vertices;  //不存在下一个顶点
		return -1;
	}

//深度优先搜索
	void dfs(int v,int reach[],int label,int* &pos){
		reach[v]=label;
		cout<<char(v+65)<<" ";
		int u=Begin(v,pos);
		while(u!=-1){
			if(!reach[u])
				dfs(u,reach,label,pos);
			u=Next(v);
		}
	}
	void DFS(int v,int reach[],int label,int* &pos){
		pos=new int[vertices];
		dfs(v,reach,label,pos);
		delete[] pos;
	}

//判断图是否连通
	bool connected(){
		int *t=new int[vertices];   //t数组用于存放标记位，判断对应顶点是否被读过
		for(int i=0;i<vertices;i++) //标记数组初始化
			t[i]=0;

		cout<<"从第一个顶点开始深度优先遍历为：";
		DFS(0,t,1,pos);      //从第一个顶点开始深度遍历
		for(i=0;i<vertices;i++) //检查是否有未读的顶点，若有则返回false，图不连通
			if(!t[i]){
				return false;
				delete[] t;
			}
		return true;
		delete[] t;
	
	}
	
//拓扑排序
	bool Topological(char v[]){
		int *InDegree=new int[vertices]; //存放入度
		int *mark=new int[vertices]; //存放标记
		int count=0;
		int *s=new int[vertices];   
		int top=-1;

		for(int j=0;j<vertices;j++){       //计算i点入度
			InDegree[j]=0;	  //初始化入度数组，标记数组
			mark[j]=0;
			for(int i=0;i<vertices;i++){
				if(a[i][j]!='*')
					InDegree[j]++;//存入数组
			}    
			if(InDegree[j]==0){
				top++;     //用数组模拟堆栈的功能，top记录当前操作的位置为最顶端
				s[top]=j;  //存入入度为0的顶点
				mark[j]=1; //标记此点已被存入
			}
		}

		while(top!=-1){
			int i=s[top];
			top--;        //每次从数组s中（堆栈）中取出一个点，计数器加一
			v[count++]=i+65;
			for(j=0;j<vertices;j++){  //从数组s中取出最后存入的那个点
				if(a[i][j]!='*'){
					InDegree[j]--;  //删除与从此点出去的边，修改其他点的相应入度
				}
				if(InDegree[j]==0&&mark[j]==0){ //入度为0且未被标记的点
					top++;  
					s[top]=j;     //存入数组中
					mark[j]=1;  //标记已存入
				}
			}
		}
		v[count]='\0';
		if(count<vertices){    //如果最后从s中取出的点总数小于原顶点数，则说明图中还剩余顶点，而且这些点的入度均不为0，即含有环
			return false;
		}
		delete[] InDegree;
		delete[] s;
		delete[] mark;
		return true;
	
	}

//单源最短路径
	void shortest(int s,int d[],int p[]){ //寻找从顶点s出发的最短路径，在d中返回最短距离
		int n=10000,t,count=0;;
		int *mark=new int[vertices];
		if(s<0||s>=vertices) return;

		for(int i=0;i<vertices;i++){  //将边的长度存入d数组中
			d[i]=int(a[s][i])-48;
			mark[i]=0;
			if(a[s][i]=='*')
				p[i]=-1;      //若无路径则p中 存为-1，否则存为s
			else{
				p[i]=s;   //p中的值用来说明是否有路径可达，若为-1则不可达
				count++;
			}
		}
		mark[s]=1;
		while(count--){
			for(i=0;i<vertices;i++){   //寻找到d中最短边对应的顶点
				if(n>d[i]&&d[i]>0&&mark[i]==0){ //在未被查看过的、值大于0（对应的边值不为*）的顶点中找到符合要求的
					n=d[i];
					t=i;    //t记录此时顶点的值
				}
			}	
		
			mark[t]=1;  //将此顶点标记为已查看
			for(int j=1;j<vertices;j++){
				if(a[t][j]!='*'&&(p[j]==-1||d[j]>d[t]+a[t][j]-48)){  //若路径不存在或者原路径小于新路径，则修改路径长度
					d[j]=d[t]+(a[t][j]-48);
					if(p[j]==-1){
						p[j]=t;      //找到可达j的路径后修改p[j]的值
						count++;
					}
				}
			}
			n=10000;
		}
	}
};
void main(){
	graph T;
	int reach[100]={0}; //深度遍历中用来标记该位是否被遍历
	char v[100]={'0'};  //存放拓扑排序的结果
	T.Input();
	bool flag=T.directed_graph();
	bool t;
	if(!flag){
		cout<<"这是个无向图"<<endl;

		
		int d[100]={0};    //第一个顶点为源点，求单源最短路径
		int p[100]={0};


		if(T.connected())   //判断连通性
			cout<<endl<<"图是连通的"<<endl;
		else
			cout<<endl<<"图不是连通的"<<endl;


		T.shortest(0,d,p);
		cout<<"顶点A-->A 最短距离是:0"<<endl;
		for(int i=1;d[i]!=NULL;i++){
			if(d[i]<0)
				cout<<"顶点A-->"<<char(65+i)<<"无路径"<<endl;
			else
				cout<<"顶点A-->"<<char(65+i)<<" 最短距离是:"<<d[i]<<endl;
		}
	

	}


	t=T.Topological(v);  //判断是否有环
	if(flag&&t){
		cout<<endl<<"它是有向无环图"<<endl;  //为有向无环图则输出DFS结果和拓扑排序的顺序
		cout<<"从第一个顶点开始深度优先结果为：";
		T.DFS(0,reach,1,pos);
		cout<<endl<<"从第一个顶点开始拓扑排序如下：";
		for(int i=0;v[i]!='\0';i++)
			cout<<v[i]<<" ";
	}
	if(flag&&!t)
		cout<<endl<<"它是个有向图且含有环"<<endl;

	
}