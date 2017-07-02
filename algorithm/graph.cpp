/*	����N�����㡢E���ߵ�ͼG�����ͼ������㷨������Ҫ�����£�
	1 ���ͼ�Ĵ������������Ӽ��̻��ļ�����ͼ����Ϣ������ͼ���ڽӱ�����ڽӾ���洢�ṹ��
	2 �����ж�ͼ�����ʵ��㷨�����ܹ��ж�ͼ�Ƿ�������ͼ������ͼ�������޻�ͼ����ͨͼ�ȡ�
	3 ���������ͼ�����ʣ�ʵ�������㷨��ѡ������һ��������
���ͼ�������޻�ͼ������ʵ��ͼ��ĳ�ֱ����㷨���ڴ˻�����ʵ��ͼ�����������㷨��
���ͼ����ͨͼ�������ͼ�������������������С���������ο����ڵķ����������õ���������Ȩֵ֮�����
���ͼ������ͼ�����Ե�һ�����㵱��Դ�㣬�����Դ���·����
Ҫ��
	��ʼ�������ݵĸ�ʽ���Լ����壬���磬�����ļ��б���ĳ�ʼ���ݸ�ʽ���������֣�
	��ʽһ
	3 
	* 3 2
	* * 1
	5 * *
	���ͣ���һ����ͼ�������������m��������m��m�����ݣ���Ӧ�ڽӾ���
	
	��ʽ��
	3 4
	1 2 3
	1 3 2
	2 3 1
	3 1 5
	���ͣ���һ����ͼ�������������m�ͱ���e��������e���ߵ���Ϣ����1 2 3��ʾ����1������2��ȨֵΪ3�ıߡ�*/
#include<iostream.h>
enum kind{DG,UDG,DAG,CG} ;// ͼ�����͡�
int* pos;//ͼ��������
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
	kind judgeKind(bool c);//�ж�ͼ�����͡�
	int First(int i,int* &pos);
	int Next(int i)   ; //������һ���붥��i�ڽӵĶ���
	void dfs(int v,int reach[],int label,int* &pos);
	void DFS(int v,int reach[],int label,int* &pos);//�������������
	bool Connected() ;//�ж��Ƿ���ͨ
	bool Topological(int v[]);
	void shortest(int s,int d[],int p[]);//Ѱ�ҴӶ���s���������·������d�з�����̾���
	~graph()
	{
		for(int i=0;i<vertexNum;i++)
			delete [] matrix[i];
		delete matrix;
	}
};
kind graph::judgeKind(bool c)
{
	bool Dsign=false;	//����Ƿ�����
	bool Csign=true;	//����Ƿ����Ի�
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
int graph::First(int i,int* &pos)//���ص�һ���붨��i�ڽӵĶ���
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
	pos[i]=vertexNum;//û���ڽӶ���
	return -1;
}
	
int graph::Next(int i)    //������һ���붥��i�ڽӵĶ���
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
	pos[i]=vertexNum;  //��������һ������
	return -1;
}
//�����������
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
bool graph::Connected() //�ж��Ƿ���ͨ
{
	int *t=new int[vertexNum];   //t�������ڴ�ű��λ���ж϶�Ӧ�����Ƿ񱻶���
	for(int i=0;i<vertexNum;i++) //��������ʼ��
		t[i]=0;
	cout<<"�ӵ�һ�����㿪ʼ������ȱ���Ϊ��";
	DFS(0,t,1,pos);      //�ӵ�һ�����㿪ʼ��ȱ���
	for(i=0;i<vertexNum;i++) //����Ƿ���δ���Ķ��㣬�����򷵻�false��ͼ����ͨ
		if(!t[i])
		{
			return false;
			delete[] t;
		}
	return true;
	delete[] t;
	
}
//��������
bool graph::Topological(int v[])
{
	int *InDegree=new int[vertexNum]; //������
	bool *mark=new bool[vertexNum]; //��ű��
	int count=0;
	int *s=new int[vertexNum];   
	int top=-1;
	for(int j=0;j<vertexNum;j++)
	{       //����i�����
		InDegree[j]=0;	  //��ʼ��������飬�������
		mark[j]=0;
		for(int i=0;i<vertexNum;i++)
		{
			if(matrix[i][j]!='*')
				InDegree[j]++;//��������
		}    
		if(InDegree[j]==0)
		{
			top++;     //������ģ���ջ�Ĺ��ܣ�top��¼��ǰ������λ��Ϊ���
			s[top]=j;  //�������Ϊ0�Ķ���
			mark[j]=1; //��Ǵ˵��ѱ�����
		}
	}

	while(top!=-1)
	{
		int i=s[top];
		top--;        //ÿ�δ�����s�У���ջ����ȡ��һ���㣬��������һ
		v[count++]=i;
		for(j=0;j<vertexNum;j++) //������s��ȡ����������Ǹ���
		{ 
			if(matrix[i][j]!='*')
			{
				InDegree[j]--;  //ɾ����Ӵ˵��ȥ�ıߣ��޸����������Ӧ���
			}
			if(InDegree[j]==0 && mark[j]==0)//���Ϊ0��δ����ǵĵ�
			{ 
				top++;  
				s[top]=j;     //����������
				mark[j]=1;  //����Ѵ���
			}
		}
	}
	if(count<vertexNum) //�������s��ȡ���ĵ�����С��ԭ����������˵��ͼ�л�ʣ�ඥ�㣬������Щ�����Ⱦ���Ϊ0�������л�
	{   
		return false;
	}
	delete[] InDegree;
	delete[] s;
	delete[] mark;
	return true;
	
}
//��Դ���·��
void graph::shortest(int s,int d[],int p[])//Ѱ�ҴӶ���s���������·������d�з�����̾���
{ 
	int n=10000,t,count=0;;
	int *mark=new int[vertexNum];
	if(s<0||s>=vertexNum) return;

	for(int i=0;i<vertexNum;i++)//���ߵĳ��ȴ���d������
	{  
		d[i]=int(matrix[s][i])-48;
		mark[i]=0;
		if(matrix[s][i]=='*')
			p[i]=-1;      //����·����p�� ��Ϊ-1�������Ϊs
		else
		{
			p[i]=s;   //p�е�ֵ����˵���Ƿ���·���ɴ��Ϊ-1�򲻿ɴ�
			count++;
		}
	}
	mark[s]=1;
	while(count--)
	{
		for(i=0;i<vertexNum;i++)  //Ѱ�ҵ�d����̱߶�Ӧ�Ķ���
		{ 
			if(n>d[i]&&d[i]>0&&mark[i]==0)//��δ���鿴���ġ�ֵ����0����Ӧ�ı�ֵ��Ϊ*���Ķ������ҵ�����Ҫ���
			{ 
				n=d[i];
				t=i;    //t��¼��ʱ�����ֵ
			}
		}	
		mark[t]=1;  //���˶�����Ϊ�Ѳ鿴
		for(int j=1;j<vertexNum;j++)
		{
			if(matrix[t][j]!='*'&&(p[j]==-1||d[j]>d[t]+matrix[t][j]-48))//��·�������ڻ���ԭ·��С����·�������޸�·������
			{  
				d[j]=d[t]+(matrix[t][j]-48);
				if(p[j]==-1)
				{
					p[j]=t;      //�ҵ��ɴ�j��·�����޸�p[j]��ֵ
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
	cout<<"�������������";
	cin>>m;
	cout<<"������"<<m<<"��"<<m<<"������"<<endl;
	graph G(m);
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>G.matrix[i][j];
		}
	}
	if(G.Connected())   //�ж���ͨ��
			cout<<endl<<"ͼ����ͨ��"<<endl;
	else
		cout<<endl<<"ͼ������ͨ��"<<endl;
	int v[100];  //�����������Ľ��
	for(i=0;i<100;i++)
		v[i]=-1;
	char circle=G.Topological(v);
	if(G.judgeKind(circle) == UDG)//����ͼ��ʱ����Դ���·��
	{
		cout<<"����һ������ͼ"<<endl;
		int d[100]={0};    //��һ������ΪԴ�㣬��Դ���·��
		int p[100]={0};
		G.shortest(0,d,p);
		cout<<"����1-->1 ��̾�����:0"<<endl;
		for(i=1;d[i]!=NULL;i++)
		{
			if(d[i]<0)
				cout<<"����1-->"<<i<<"��·��"<<endl;
			else
				cout<<"����1-->"<<i<<" ��̾�����:"<<d[i]<<endl;
		}
	}
	if(G.judgeKind(circle) == DAG)
	{
		int reach[100]={0}; //��ȱ�����������Ǹ�λ�Ƿ񱻱���
		cout<<"����һ�������޻�ͼ"<<endl;
		cout<<"�ӵ�һ�����㿪ʼ������Ƚ��Ϊ��";
		G.DFS(0,reach,1,pos);
		cout<<endl<<"�ӵ�һ�����㿪ʼ��������Ϊ��";
		for(i=0;v[i]!=-1;i++)
			cout<<v[i]<<" ";
	}
	if(G.judgeKind(circle) == DG)
		cout<<"����һ������ͼ,�����л�"<<endl;
}

