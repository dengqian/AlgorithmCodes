#include <iostream.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip.h>
int compare;//��¼�Ƚϴ���
int swap;//��¼��������
int Min=1000;//int������ȡֵ������
int Max=10000;//int����������������
class Sort
{
	int num;//int�������ĸ���
	int *store;//���int��������ݵ�����
	int *temp;//���ڱ���ԭʼ������ݵ�����
public:
	Sort(int n);//���캯��
	void Create(int *s);//��������
	void Copy();//��ֵ����
	bool Compare(int i,int j);//�ȽϺ���
	void Swap(int &i,int &j);//��������
	void InsertSort();//����������
	int FindPiot(int left,int right);//�ҵ���ֵ����
	int Partition(int left,int right,int &pivot);//�ָ��
	int QuickPass(int left,int right);

//	void QuickSort(int i,int j);//����������
	void QuickSort(int left, int right);
	void MergeSort(int *tmp,int left, int right);//�鲢������
	void BuildHeap(int, int ); //�ѵ�������
	void HeapSort(int Length);//�Ѵ�������
	int Range(int start,int end);//����������ֵ����
	void List();//��ʾ������ݷֲ��������
};
Sort::Sort(int n)
{
	num=n;
	store=new int[num];//��ʼ������
	for(int i=0;i<num;i++)
	{
		store[i]=NULL;
	}
	temp=new int[num];//��ʼ����������
	for(i=0;i<num;i++)
	{
		temp[i]=NULL;
	}
}
void Sort::Create(int *s)
{
	for(int i=0;i<num;i++)
	{
		store[i]=s[i];//��ֵ
		temp[i]=s[i];
	}
}
void Sort::Copy()
{
	for (int i=0 ; i<num;i++)
	{
		store[i] = temp[i];//�������������ݴ���store�����Լ���������������
	}
}
bool Sort::Compare(int i,int j)     //�ȽϺ���                
{
	compare++;     //��¼�Ƚϴ���+1                      
	if(i<j)        //��С���򷵻���ֵ                          
	{
		return true;
	}
	else           //���򷵻�false                  
	{
		return false;                         
	}
}

void Sort::Swap(int &i,int &j)//��������
{
	int tmp;
	tmp=i;
	i=j;
	j=tmp;
	swap++;//��¼��������+1
}

void Sort::InsertSort()//��������
{
	for(int i=0;i<num;i++)
	{
		for(int j=i;j>0&&Compare(store[j],store[j-1]);j--)//�µıȽϵ�ֵ��֮ǰ��ֵ�����Ƚ�
		{
			Swap(store[j],store[j-1]);//��С���򽻻�
		}
	}
}

int Sort::FindPiot(int left,int right)//��ֵΪ�����м���ֵ
{
	return (left+right)/2;
}
int Sort::Partition(int left,int right,int &pivot)
{
	do
	{
		while(Compare(store[++left],pivot));//����߿�ʼ����������ֵ���ֵ
		while((right!=0)&&Compare(store[--right],pivot));//���ұ߿�ʼ����������ֵС��ֵ
		Swap(store[left],store[right]);//�򽻻�
	}while(left<right);
	Swap(store[left],store[right]);//ֱ������֪��ֵ�������һ��ѭ���в���Ҫ�Ľ����ľ�����
	return left;//����
}
/*void Sort::QuickSort(int left,int right)//��������
{
	if(right<=left)
		return;
	int pivotindex=FindPiot(store[left],store[right]);//�ҵ���ֵ���ڵ�λ��
	Swap(store[pivotindex],store[right]);//�����һ��Ԫ�ؽ��н���
	int k=Partition(left-1,right,store[right]);//�ҵ���ֵ�������е�ʵ��λ��
	Swap(store[k],store[right]);//����ֵ�����λ��
	QuickSort(left,k-1);//��߼�����������
	QuickSort(k+1,right);//�ұ߼�����������

}*/
int Sort::QuickPass(int left,int right){
	int l = left, r = right;
	int temp=store[l];
	while(l<r)
	{
		while(l<r&&temp<=store[r])
		{
			r--;
			compare++;
		}
		if(l<r)
		{
			store[l++]=store[r];
			swap++;
		}
		while(l<r&&temp>=store[l])
		{
			l++;
			compare++;
		}
		if(l<r)
		{
			store[r--]=store[l];
			swap++;
		}
	}
	store[l]=temp;
	swap++;
	return l;	
}

void Sort::QuickSort(int left, int right)
{
	int pos = 0;
	if (left< right)
	{
		pos = QuickPass(left, right);
		QuickSort(left, pos-1 );
		QuickSort(pos+1, right);
	}

}


void Sort::MergeSort(int *tmp,int left,int right)//�鲢����
{
	int mid=(left+right)/2;//�ҵ����������
	if(left==right)
		return;
	MergeSort(tmp,left,mid);//���߼����鲢����
	MergeSort(tmp,mid+1,right);//�Ұ�߼����ݹ���й鲢����
	for(int i=left;i<=right;i++)//��store�е����ݴ���tmp
	{
		tmp[i]=store[i];
	}
	int i1=left;
	int i2=mid+1;
	for(int curr=left;curr<right;curr++)
	{
		if(i1==mid+1)//i1Խ��
			store[curr]=tmp[i2++];
		else 
			if(i2>right)//i2Խ��
			{
				store[curr]=tmp[i1++];
			}
			else 
				if(Compare(tmp[i1],tmp[i2]))
				{
					store[curr]=tmp[i1++];
				}
				else
				{
					store[curr]=tmp[i2++];
				}
	}
}
void Sort::BuildHeap(int curr, int n)
{
	while(2*curr+1<n)//2*curr+1��2*curr+2��curr�����Һ���		
	{
		int max=2*curr+1 ;//�����¼���ֵ�±�Ϊmax	
        if(2*curr+2<n) 	
        {
			if(Compare(store[2*curr+1],store[2*curr+2])) //�Ƚ����Ӻ��Һ���
			{
                max=2*curr+2;
            }
        }
        if(Compare(store[curr],store[max]))//��curr�������ݱ�max��������С
        {
             
			Swap(store[curr],store[max]);//����curr��max������
            curr=max;//�ѱ��ƻ�����Ҫ���µ���
        }
        else
        {
             
			break;//���Һ��Ӿ�С���δ�ƻ���������Ҫ����
		}
	}
}
void Sort::HeapSort( int n)
{
    int i=0; //��store[n]���ɴ����,��store[0]Ϊ��
    for (i=n/2-1; i>=0; i--)
    {
        BuildHeap(i,n);//�����һ�еķ�Ҷ�ӽڵ㴦��ʼ�Ƚϣ����store[0]Ϊ���ֵ
    }
    for (i=n-1; i>0; i--)
    {
		Swap(store[0],store[i]);//�����ֵ�������һ��
        BuildHeap(0, i);//���µ��������
    }
}
int Sort::Range(int start,int end)//����������ж��ٸ���
{
	int count=0;
	for (int i=0;i<num;i++)
	{
		if (start<=temp[i] && temp[i]<end)
		{
			count++;
		}
	}
	return count;
}
void Sort::List()//��ʾ���ݷֶ�
{
	int group=Max/1000+1;
	double *total=new double [group];
	for (int i=0 ; i<group ; i++)
	{
		total [i] = (double)(Range(i*1000,i*1000+1000-1))/num*100;
	}
	cout<<"���ݶ� "<<setw(20)<<"��ռ����"<<endl;
	for (int j=0 ; j<group-1 ;j++)
	{
		cout<<j*1000<<" ~ "<<j*1000+999<<setw(20)<<total[j]<<"%"<<endl;
	}
}
void main()
{
	char answer;
	do
	{
		srand((unsigned)time(NULL));				
		int n;
		cout<<"����������ݵĸ���n��n<10000��";
		n=rand()%10000;
		cout<<n<<endl;
		Sort s(n);
		int *sort = new int [n];
		for(int i=0;i<n;i++)                               //������������
		{
			sort[i]=Min+rand()%(Max-Min);
		}
		s.Create(sort);
		s.List();
		cout<<setw(20)<<"�Ƚϴ���"<<setw(20)<<"��������"<<endl;
		cout<<"----------------------------------------"<<endl;
		//��������
		swap=0;
		compare=0;	
		s.InsertSort();
		cout<<"��������  "<<compare<<setw(20)<<swap<<setw(20)<<endl;
		//��������
	    s.Copy();
		swap=0;
		compare=0;		
		s.QuickSort(0,n-1);	
		cout<<"��������  "<<compare<<setw(20)<<swap<<setw(20)<<endl;
		//�鲢����	
		s.Copy();
		swap=0;
		compare=0;		
		int *temp= new int[n];
		s.MergeSort(temp,0,n-1);
		cout<<"�鲢����  "<<compare<<setw(20)<<swap<<setw(20)<<endl;
		//������
		s.Copy();
		swap=0;
		compare=0;		
		s.HeapSort(n);
		cout<<"������   "<<compare<<setw(20)<<swap<<setw(20)<<endl;
		cout<<"�Ƿ�����������ݣ�(y/n): "<<endl;
		cin>>answer;
	}while(answer=='y'||answer=='Y');
}
