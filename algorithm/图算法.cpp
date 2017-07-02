#include<iostream.h>
//#include<queue.h>

int* pos;//ͼ����������

class graph{

	int vertices;
	char **a;
public:

	char** Geta(){
		return a;
	}
//��ʼ���ڽӾ���,���û�����
	void Input(){
		a=new char*[vertices];
		cout<<"������ͼ�Ķ�����:"<<endl;
		cin>>vertices;
		cout<<"�������Ӧ���ڽӾ��󣨡���*���棩:"<<endl;
		for(int i=0;i<vertices;i++){
			a[i]=new char[vertices];
			for(int j=0;j<vertices;j++)
				cin>>a[i][j];
		}
	}


//�ж�������ͼ��������ͼ���ڽӾ����Ƿ�Գƣ�
	bool directed_graph(){
		for(int i=1;i<vertices;i++){
			for(int j=i;j<vertices;j++){
				if(a[i][j]!=a[j][i])
					return true;
			}
		}
		for(i=0;i<vertices;i++)
			if(a[i][i]!='*'){
				cout<<"�����Ǽ�ͼ"<<endl;
				break;
			}
		return false;
	}

//�ڽӾ���ı�������
	int Begin(int i,int* &pos){  //���ص�һ���붨��i�ڽӵĶ���
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
		pos[i]=vertices;//û���ڽӶ���
		return -1;
	}
	int Next(int i){     //������һ���붥��i�ڽӵĶ���
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
		pos[i]=vertices;  //��������һ������
		return -1;
	}

//�����������
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

//�ж�ͼ�Ƿ���ͨ
	bool connected(){
		int *t=new int[vertices];   //t�������ڴ�ű��λ���ж϶�Ӧ�����Ƿ񱻶���
		for(int i=0;i<vertices;i++) //��������ʼ��
			t[i]=0;

		cout<<"�ӵ�һ�����㿪ʼ������ȱ���Ϊ��";
		DFS(0,t,1,pos);      //�ӵ�һ�����㿪ʼ��ȱ���
		for(i=0;i<vertices;i++) //����Ƿ���δ���Ķ��㣬�����򷵻�false��ͼ����ͨ
			if(!t[i]){
				return false;
				delete[] t;
			}
		return true;
		delete[] t;
	
	}
	
//��������
	bool Topological(char v[]){
		int *InDegree=new int[vertices]; //������
		int *mark=new int[vertices]; //��ű��
		int count=0;
		int *s=new int[vertices];   
		int top=-1;

		for(int j=0;j<vertices;j++){       //����i�����
			InDegree[j]=0;	  //��ʼ��������飬�������
			mark[j]=0;
			for(int i=0;i<vertices;i++){
				if(a[i][j]!='*')
					InDegree[j]++;//��������
			}    
			if(InDegree[j]==0){
				top++;     //������ģ���ջ�Ĺ��ܣ�top��¼��ǰ������λ��Ϊ���
				s[top]=j;  //�������Ϊ0�Ķ���
				mark[j]=1; //��Ǵ˵��ѱ�����
			}
		}

		while(top!=-1){
			int i=s[top];
			top--;        //ÿ�δ�����s�У���ջ����ȡ��һ���㣬��������һ
			v[count++]=i+65;
			for(j=0;j<vertices;j++){  //������s��ȡ����������Ǹ���
				if(a[i][j]!='*'){
					InDegree[j]--;  //ɾ����Ӵ˵��ȥ�ıߣ��޸����������Ӧ���
				}
				if(InDegree[j]==0&&mark[j]==0){ //���Ϊ0��δ����ǵĵ�
					top++;  
					s[top]=j;     //����������
					mark[j]=1;  //����Ѵ���
				}
			}
		}
		v[count]='\0';
		if(count<vertices){    //�������s��ȡ���ĵ�����С��ԭ����������˵��ͼ�л�ʣ�ඥ�㣬������Щ�����Ⱦ���Ϊ0�������л�
			return false;
		}
		delete[] InDegree;
		delete[] s;
		delete[] mark;
		return true;
	
	}

//��Դ���·��
	void shortest(int s,int d[],int p[]){ //Ѱ�ҴӶ���s���������·������d�з�����̾���
		int n=10000,t,count=0;;
		int *mark=new int[vertices];
		if(s<0||s>=vertices) return;

		for(int i=0;i<vertices;i++){  //���ߵĳ��ȴ���d������
			d[i]=int(a[s][i])-48;
			mark[i]=0;
			if(a[s][i]=='*')
				p[i]=-1;      //����·����p�� ��Ϊ-1�������Ϊs
			else{
				p[i]=s;   //p�е�ֵ����˵���Ƿ���·���ɴ��Ϊ-1�򲻿ɴ�
				count++;
			}
		}
		mark[s]=1;
		while(count--){
			for(i=0;i<vertices;i++){   //Ѱ�ҵ�d����̱߶�Ӧ�Ķ���
				if(n>d[i]&&d[i]>0&&mark[i]==0){ //��δ���鿴���ġ�ֵ����0����Ӧ�ı�ֵ��Ϊ*���Ķ������ҵ�����Ҫ���
					n=d[i];
					t=i;    //t��¼��ʱ�����ֵ
				}
			}	
		
			mark[t]=1;  //���˶�����Ϊ�Ѳ鿴
			for(int j=1;j<vertices;j++){
				if(a[t][j]!='*'&&(p[j]==-1||d[j]>d[t]+a[t][j]-48)){  //��·�������ڻ���ԭ·��С����·�������޸�·������
					d[j]=d[t]+(a[t][j]-48);
					if(p[j]==-1){
						p[j]=t;      //�ҵ��ɴ�j��·�����޸�p[j]��ֵ
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
	int reach[100]={0}; //��ȱ�����������Ǹ�λ�Ƿ񱻱���
	char v[100]={'0'};  //�����������Ľ��
	T.Input();
	bool flag=T.directed_graph();
	bool t;
	if(!flag){
		cout<<"���Ǹ�����ͼ"<<endl;

		
		int d[100]={0};    //��һ������ΪԴ�㣬��Դ���·��
		int p[100]={0};


		if(T.connected())   //�ж���ͨ��
			cout<<endl<<"ͼ����ͨ��"<<endl;
		else
			cout<<endl<<"ͼ������ͨ��"<<endl;


		T.shortest(0,d,p);
		cout<<"����A-->A ��̾�����:0"<<endl;
		for(int i=1;d[i]!=NULL;i++){
			if(d[i]<0)
				cout<<"����A-->"<<char(65+i)<<"��·��"<<endl;
			else
				cout<<"����A-->"<<char(65+i)<<" ��̾�����:"<<d[i]<<endl;
		}
	

	}


	t=T.Topological(v);  //�ж��Ƿ��л�
	if(flag&&t){
		cout<<endl<<"���������޻�ͼ"<<endl;  //Ϊ�����޻�ͼ�����DFS��������������˳��
		cout<<"�ӵ�һ�����㿪ʼ������Ƚ��Ϊ��";
		T.DFS(0,reach,1,pos);
		cout<<endl<<"�ӵ�һ�����㿪ʼ�����������£�";
		for(int i=0;v[i]!='\0';i++)
			cout<<v[i]<<" ";
	}
	if(flag&&!t)
		cout<<endl<<"���Ǹ�����ͼ�Һ��л�"<<endl;

	
}