#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
#define MAX_VERTEX_NUM 20
#define OK 1
#define ERROR 0
#define MAX 1000
typedef struct Arcell{
　double adj;
}Arcell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
　char vexs[MAX_VERTEX_NUM];//节点数组
　AdjMatrix arcs;//邻接矩阵
　int vexnum,arcnum;//图的当前节点数和弧数
}MGraph;
typedef struct Pnode//用于普利姆算法
{
　char adjvex;//节点
　double lowcost;//权值
}Pnode,Closedge[MAX_VERTEX_NUM];//记录顶点集U到V-U的代价最小的边的辅助数组定义
typedef struct Knode//用于克鲁斯卡尔算法中存储一条边及其对应的2个节点
{
　char ch1;//节点1
　char ch2;//节点2
　double value;//权值
}Knode,Dgevalue[MAX_VERTEX_NUM];
　
　//-------------------------------------------------------------------------------
int CreateUDG(MGraph&G,Dgevalue&dgevalue);
int LocateVex(MGraphG,charch);
int Minimum(MGraphG,Closedgeclosedge);
void MiniSpanTree_PRIM(MGraphG,charu);
void Sortdge(Dgevalue&dgevalue,MGraphG);
　
　//-------------------------------------------------------------------------------
int CreateUDG(MGraph&G,Dgevalue&dgevalue)//构造无向加权图的邻接矩阵
{
	
　	int i,j,k;
　	cout<<"请输入图中节点个数和边/弧的条数：";
　	cin>>G.vexnum>>G.arcnum;
　	cout<<"请输入节点：";
　	for(i=0;i<G.vexnum;++i)
　	cin>>G.vexs[i];
　	for(i=0;i<G.vexnum;++i)//初始化数组
　	{
		for(j=0;j<G.vexnum;++j){
　			G.arcs[i][j].adj=MAX;
　		}
　	}
　	cout<<"请输入一条边依附的定点及边的权值："<<endl;
　	for(k=0;k<G.arcnum;++k)
　	{
　		cin>>dgevalue[k].ch1>>dgevalue[k].ch2>>dgevalue[k].value;
　		i=LocateVex(G,dgevalue[k].ch1）;
　		j=LocateVex(G,dgevalue[k].ch2）;
　		G.arcs[i][j].adj=dgevalue[k].value;
　		G.arcs[j][i].adj=G.arcs[i][j].adj;
　	}
　	return OK;
　}
int LocateVex(MGraphG,charch)//确定节点ch在图G.vexs中的位置
{
	inta;
　	for(inti=0;i<G.vexnum;i++)
　	{
　		if(G.vexs[i]==ch)
　		a=i;
　	}
　	return a;
}
void MiniSpanTree_PRIM(MGraphG,charu)//普利姆算法求最小生成树
{
	int i,j,k;
	Closedge closedge;
	k=LocateVex(G,u);
	for(j=0;j<G.vexnum;j++)
	{
	　if(j!=k)
	　{
		　closedge[j].adjvex=u;
		　closedge[j].lowcost=G.arcs[k][j].adj;
	　}
　	}
　	closedge[k].lowcost=0;
　	for(i=1;i<G.vexnum;i++)
　	{
	　	k=Minimum(G,closedge);
	　	cout<<"("<<closedge[k].adjvex<<","<<G.vexs[k]<<","<<closedge[k].lowcost<<")"<<endl;
	　	closedge[k].lowcost=0;
	　	for(j=0;j<G.vexnum;++j)
	　	{
		　if(G.arcs[k][j].adj<closedge[j].lowcost)
		　{
			　closedge[j].adjvex=G.vexs[k];
			　closedge[j].lowcost=G.arcs[k][j].adj;
		　}
		}
	}
}
　int Minimum(MGraph G,Closedge closedge)//求closedge中权值最小的边，并返回其顶点在vexs中的位置
　{
	　int i,j;
	　double k=1000;
	　for(i=0;i<G.vexnum;i++)
	　{
		　if(closedge[i].lowcost!=0&&closedge[i].lowcost<k)
		　{
			　k=closedge[i].lowcost;
			　j=i;
		　}
	　}
	　return j;
　}
　void MiniSpanTree_KRSL(MGraph G,Dgevalue &dgevalue)//克鲁斯卡尔算法求最小生成树
　{
	　int p1,p2,i,j;
	　int bj[MAX_VERTEX_NUM];//标记数组
	　for(i=0;i<G.vexnum;i++)//标记数组初始化
	　	bj[i]=i;
	　Sortdge(dgevalue,G);//将所有权值按从小到大排序
	　for(i=0;i<G.arcnum;i++)
	　{
		　p1=bj[LocateVex(G,dgevalue[i].ch1）];
		　p2=bj[LocateVex(G,dgevalue[i].ch2）];
		　if(p1!=p2）
		　{
			　cout<<"("<<dgevalue[i].ch1<<","<<dgevalue[i].ch2<<","<<dgevalue[i].value<<")"<<endl;
			　for(j=0;j<G.vexnum;j++)
			　{
				　if(bj[j]==p2）
				　bj[j]=p1;
			　}
		　}
	　}
　}
void Sortdge(Dgevalue &dgevalue,MGraph G)//对dgevalue中各元素按权值按从小到大排序
{
　	int i,j;
　	double temp;
	char ch1,ch2;
	for(i=0;i<G.arcnum;i++)
	{
		for(j=i;j<G.arcnum;j++)
		{
			if(dgevalue[i].value>dgevalue[j].value)
			{
				temp=dgevalue[i].value;
			　	dgevalue[i].value=dgevalue[j].value;
			　	dgevalue[j].value=temp;
			　	ch1=dgevalue[i].ch1;
			　	dgevalue[i].ch1=dgevalue[j].ch1;
				dgevalue[j].ch1=ch1;
				ch2=dgevalue[i].ch2;
				dgevalue[i].ch2=dgevalue[j].ch2;
				dgevalue[j].ch2=ch2;
			}
	　	}
	}
}
void main()
　{
　int i,j;
　MGrap hG;
　char u;
　Dgevalue dgevalue;
　CreateUDG(G,dgevalue);
　cout<<"图的邻接矩阵为："<<endl;
　for(i=0;i<G.vexnum;i++)
　{
　for(j=0;j<G.vexnum;j++)
　cout<<G.arcs[i][j].adj<<"";
　cout<<endl;
　}
　cout<<"=============普利姆算法===============\n";
　cout<<"请输入起始点：";
　cin>>u;
　cout<<"构成最小代价生成树的边集为：\n";
　MiniSpanTree_PRIM(G,u);
　cout<<"============克鲁斯科尔算法=============\n";
　cout<<"构成最小代价生成树的边集为：\n";
　MiniSpanTree_KRSL(G,dgevalue);
　}
