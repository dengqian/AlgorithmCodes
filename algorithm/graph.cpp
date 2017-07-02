/*	给定N个顶点、E条边的图G，完成图的相关算法，具体要求如下：
	1 完成图的创建方法，即从键盘或文件输入图的信息，建立图的邻接表或是邻接矩阵存储结构。
	2 给出判定图的性质的算法，即能够判定图是否是有向图、无向图、有向无环图、连通图等。
	3 根据输入的图的性质，实现以下算法（选择其中一两个）：
如果图是有向无环图，则先实现图的某种遍历算法，在此基础上实现图的拓扑排序算法。
如果图是连通图，则求出图的最大生成树（不是最小生成树，参考讲授的方法），即得到的生成树权值之和最大。
如果图是无向图，则以第一个顶点当做源点，求出单源最短路径。
要求：
	初始输入数据的格式由自己定义，例如，输入文件中保存的初始数据格式有以下两种：
	格式一
	3 
	* 3 2
	* * 1
	5 * *
	解释：第一行是图中所含顶点个数m，后面是m行m列数据，对应邻接矩阵。
	
	格式二
	3 4
	1 2 3
	1 3 2
	2 3 1
	3 1 5
	解释：第一行是图中所含顶点个数m和边数e，后面是e条边的信息，如1 2 3表示顶点1到顶点2有权值为3的边。*/
#include<iostream.h>
enum kind{DG,UDG,DAG,CG} ;// 图的类型。
int* pos;//图遍历数组
class graph
{
public:
	int vertexNum;
	char **matrix;
	graph(int V)
	{
		vertexNum=V;
		matrix=(char **)new char *[vertexNum];
		for(int i=0;i<vertexNum;i++)
		{
			matrix[i]=new char[vertexNum];
		}
	}
	kind judgeKind(bool c);//判断图的类型。
	int First(int i,int* &pos);
	int Next(int i)   ; //返回下一个与顶点i邻接的顶点
	void dfs(int v,int reach[],int label,int* &pos);
	void DFS(int v,int reach[],int label,int* &pos);//深度优先搜索。
	bool Connected() ;//判断是否连通
	bool Topological(int v[]);
	void shortest(int s,int d[],int p[]);//寻找从顶点s出发的最短路径，在d中返回最短距离
	~graph()
	{
		for(int i=0;i<vertexNum;i++)
			delete [] matrix[i];
		delete matrix;
	}
};
kind graph::judgeKind(bool c)
{
	bool Dsign=false;	//标记是否有向
	bool Csign=true;	//标记是否有自环
	for(int i=0;i<vertexNum;i++)
	{
		for(int j=0;j<vertexNum;j++)
		{
			if(matrix[i][j] != '*' && matrix[j][i]!='*')
				Dsign=true;
		}
		if(matrix[i][i] != '*')
			Csign=false;
	}
	if(Dsign && Csign && !c)
		return DAG;
	else if(Dsign)
		return DG;
	else if(!Dsign)
		return UDG;
}
int graph::First(int i,int* &pos)//返回第一个与定点i邻接的顶点
{     
	if(i<0||i>=vertexNum)
	{
		cout<<"wrong!";
		return -1;
	}
	for(int j=0;j<vertexNum;j++)
	{
		if(matrix[i][j]!='*')
		{
			pos[i]=j;
			return j;
		}
	}
	pos[i]=vertexNum;//没有邻接顶点
	return -1;
}
	
int graph::Next(int i)    //返回下一个与顶点i邻接的顶点
{ 
	if(i<0||i>=vertexNum)
	{
		cout<<"wrong!";
		return -1;
	}
	for(int j=pos[i]+1;j<vertexNum;j++)
	{
		if(matrix[i][j]!='*')
		{
			pos[i]=j;
			return j;
		}
	}
	pos[i]=vertexNum;  //不存在下一个顶点
	return -1;
}
//深度优先搜索
void graph::dfs(int v,int reach[],int label,int* &pos)
{
	reach[v]=label;
	cout<<v<<" ";
	int u=First(v,pos);
	while(u!=-1)
	{
		if(!reach[u])
			dfs(u,reach,label,pos);
		u=Next(v);
	}
}
void graph::DFS(int v,int reach[],int label,int* &pos)
{
	pos=new int[vertexNum];
	dfs(v,reach,label,pos);
	delete[] pos;
}
bool graph::Connected() //判断是否连通
{
	int *t=new int[vertexNum];   //t数组用于存放标记位，判断对应顶点是否被读过
	for(int i=0;i<vertexNum;i++) //标记数组初始化
		t[i]=0;
	cout<<"从第一个顶点开始深度优先遍历为：";
	DFS(0,t,1,pos);      //从第一个顶点开始深度遍历
	for(i=0;i<vertexNum;i++) //检查是否有未读的顶点，若有则返回false，图不连通
		if(!t[i])
		{
			return false;
			delete[] t;
		}
	return true;
	delete[] t;
	
}
//拓扑排序
bool graph::Topological(int v[])
{
	int *InDegree=new int[vertexNum]; //存放入度
	bool *mark=new bool[vertexNum]; //存放标记
	int count=0;
	int *s=new int[vertexNum];   
	int top=-1;
	for(int j=0;j<vertexNum;j++)
	{       //计算i点入度
		InDegree[j]=0;	  //初始化入度数组，标记数组
		mark[j]=0;
		for(int i=0;i<vertexNum;i++)
		{
			if(matrix[i][j]!='*')
				InDegree[j]++;//存入数组
		}    
		if(InDegree[j]==0)
		{
			top++;     //用数组模拟堆栈的功能，top记录当前操作的位置为最顶端
			s[top]=j;  //存入入度为0的顶点
			mark[j]=1; //标记此点已被存入
		}
	}

	while(top!=-1)
	{
		int i=s[top];
		top--;        //每次从数组s中（堆栈）中取出一个点，计数器加一
		v[count++]=i;
		for(j=0;j<vertexNum;j++) //从数组s中取出最后存入的那个点
		{ 
			if(matrix[i][j]!='*')
			{
				InDegree[j]--;  //删除与从此点出去的边，修改其他点的相应入度
			}
			if(InDegree[j]==0 && mark[j]==0)//入度为0且未被标记的点
			{ 
				top++;  
				s[top]=j;     //存入数组中
				mark[j]=1;  //标记已存入
			}
		}
	}
	if(count<vertexNum) //如果最后从s中取出的点总数小于原顶点数，则说明图中还剩余顶点，而且这些点的入度均不为0，即含有环
	{   
		return false;
	}
	delete[] InDegree;
	delete[] s;
	delete[] mark;
	return true;
	
}
//单源最短路径
void graph::shortest(int s,int d[],int p[])//寻找从顶点s出发的最短路径，在d中返回最短距离
{ 
	int n=10000,t,count=0;;
	int *mark=new int[vertexNum];
	if(s<0||s>=vertexNum) return;

	for(int i=0;i<vertexNum;i++)//将边的长度存入d数组中
	{  
		d[i]=int(matrix[s][i])-48;
		mark[i]=0;
		if(matrix[s][i]=='*')
			p[i]=-1;      //若无路径则p中 存为-1，否则存为s
		else
		{
			p[i]=s;   //p中的值用来说明是否有路径可达，若为-1则不可达
			count++;
		}
	}
	mark[s]=1;
	while(count--)
	{
		for(i=0;i<vertexNum;i++)  //寻找到d中最短边对应的顶点
		{ 
			if(n>d[i]&&d[i]>0&&mark[i]==0)//在未被查看过的、值大于0（对应的边值不为*）的顶点中找到符合要求的
			{ 
				n=d[i];
				t=i;    //t记录此时顶点的值
			}
		}	
		mark[t]=1;  //将此顶点标记为已查看
		for(int j=1;j<vertexNum;j++)
		{
			if(matrix[t][j]!='*'&&(p[j]==-1||d[j]>d[t]+matrix[t][j]-48))//若路径不存在或者原路径小于新路径，则修改路径长度
			{  
				d[j]=d[t]+(matrix[t][j]-48);
				if(p[j]==-1)
				{
					p[j]=t;      //找到可达j的路径后修改p[j]的值
					count++;
				}
			}
		}
		n=10000;
	}
}
void main()
{
	int i,j;
	int m;
	cout<<"请输入结点个数：";
	cin>>m;
	cout<<"请输入"<<m<<"行"<<m<<"列数据"<<endl;
	graph G(m);
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>G.matrix[i][j];
		}
	}
	if(G.Connected())   //判断连通性
			cout<<endl<<"图是连通的"<<endl;
	else
		cout<<endl<<"图不是连通的"<<endl;
	int v[100];  //存放拓扑排序的结果
	for(i=0;i<100;i++)
		v[i]=-1;
	char circle=G.Topological(v);
	if(G.judgeKind(circle) == UDG)//无向图的时候求单源最短路径
	{
		cout<<"这是一个无向图"<<endl;
		int d[100]={0};    //第一个顶点为源点，求单源最短路径
		int p[100]={0};
		G.shortest(0,d,p);
		cout<<"顶点1-->1 最短距离是:0"<<endl;
		for(i=1;d[i]!=NULL;i++)
		{
			if(d[i]<0)
				cout<<"顶点1-->"<<i<<"无路径"<<endl;
			else
				cout<<"顶点1-->"<<i<<" 最短距离是:"<<d[i]<<endl;
		}
	}
	if(G.judgeKind(circle) == DAG)
	{
		int reach[100]={0}; //深度遍历中用来标记该位是否被遍历
		cout<<"这是一个有向无环图"<<endl;
		cout<<"从第一个顶点开始深度优先结果为：";
		G.DFS(0,reach,1,pos);
		cout<<endl<<"从第一个顶点开始拓扑排序为：";
		for(i=0;v[i]!=-1;i++)
			cout<<v[i]<<" ";
	}
	if(G.judgeKind(circle) == DG)
		cout<<"这是一个有向图,但是有环"<<endl;
}

