#include<iostream>
using namespace std;
int n;//任务个数
int *M;
int *P;
class Task
{
public:
	int weight;//权重
	int start;
	int end;
};

Task *task;
int max(int a, int b)
{
	return a>b?a:b;
}
int MComputeOpt(int j)
{
	if(j==0)
		return 0;
	if(M[j] != -1)
		return M[j];
	else 
	{
		M[j] = max(task[j].weight + MComputeOpt(P[j]),MComputeOpt(j-1));
		return M[j];
		cout<<j<<" "<<M[j]<<endl;
	}
}
int main()
{
	cout<<"请输入任务的个数"<<endl;
	cin>>n;
	int i=0;
	task = new Task[n+1];
	M = new int[n+1];
	P = new int[n+1];
	for(i=1;i<=n;i++)
	{
		cin>>task[i].start>>task[i].end;
		cin>>task[i].weight;
		M[i] = -1;
	}
	for(i=1;i<=n;i++)
		for(int j=i;j>=0;j--)
		{
			if(task[j].end <= task[i].start)
			{	
				P[i] = j;
				break;
			}
			if(j==0)
				P[i] = 0;
		}
		for(i=1;i<=n;i++)
			cout<<P[i]<<"  "<<endl;
	int result = MComputeOpt(n);
	cout<<"result:"<<result<<endl;
	return 0;
}