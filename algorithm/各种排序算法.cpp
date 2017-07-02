#include <iostream.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip.h>
int compare;//记录比较次数
int swap;//记录交换次数
int Min=1000;//int型整数取值的下限
int Max=10000;//int型整数个数的上限
class Sort
{
	int num;//int型整数的个数
	int *store;//存放int型随机数据的数组
	int *temp;//用于保存原始随机数据的数组
public:
	Sort(int n);//构造函数
	void Create(int *s);//创建函数
	void Copy();//赋值函数
	bool Compare(int i,int j);//比较函数
	void Swap(int &i,int &j);//交换函数
	void InsertSort();//插入排序函数
	int FindPiot(int left,int right);//找到轴值函数
	int Partition(int left,int right,int &pivot);//分割函数
	int QuickPass(int left,int right);

//	void QuickSort(int i,int j);//快速排序函数
	void QuickSort(int left, int right);
	void MergeSort(int *tmp,int left, int right);//归并排序函数
	void BuildHeap(int, int ); //堆调整函数
	void HeapSort(int Length);//堆创建函数
	int Range(int start,int end);//计算区间数值函数
	void List();//显示随机数据分布情况函数
};
Sort::Sort(int n)
{
	num=n;
	store=new int[num];//初始化数组
	for(int i=0;i<num;i++)
	{
		store[i]=NULL;
	}
	temp=new int[num];//初始化缓存数组
	for(i=0;i<num;i++)
	{
		temp[i]=NULL;
	}
}
void Sort::Create(int *s)
{
	for(int i=0;i<num;i++)
	{
		store[i]=s[i];//赋值
		temp[i]=s[i];
	}
}
void Sort::Copy()
{
	for (int i=0 ; i<num;i++)
	{
		store[i] = temp[i];//将缓存数组内容传入store，得以继续计算其他排序
	}
}
bool Sort::Compare(int i,int j)     //比较函数                
{
	compare++;     //记录比较次数+1                      
	if(i<j)        //若小于则返回真值                          
	{
		return true;
	}
	else           //否则返回false                  
	{
		return false;                         
	}
}

void Sort::Swap(int &i,int &j)//交换函数
{
	int tmp;
	tmp=i;
	i=j;
	j=tmp;
	swap++;//记录交换次数+1
}

void Sort::InsertSort()//插入排序
{
	for(int i=0;i<num;i++)
	{
		for(int j=i;j>0&&Compare(store[j],store[j-1]);j--)//新的比较的值和之前的值继续比较
		{
			Swap(store[j],store[j-1]);//若小于则交换
		}
	}
}

int Sort::FindPiot(int left,int right)//轴值为数组中间点的值
{
	return (left+right)/2;
}
int Sort::Partition(int left,int right,int &pivot)
{
	do
	{
		while(Compare(store[++left],pivot));//从左边开始，遇到比轴值大的值
		while((right!=0)&&Compare(store[--right],pivot));//从右边开始，遇到比轴值小的值
		Swap(store[left],store[right]);//则交换
	}while(left<right);
	Swap(store[left],store[right]);//直至交换知轴值处对最后一趟循环中不必要的交换的纠正，
	return left;//返回
}
/*void Sort::QuickSort(int left,int right)//快速排序
{
	if(right<=left)
		return;
	int pivotindex=FindPiot(store[left],store[right]);//找到轴值所在的位置
	Swap(store[pivotindex],store[right]);//和最后一个元素进行交换
	int k=Partition(left-1,right,store[right]);//找到轴值在数组中的实际位置
	Swap(store[k],store[right]);//将轴值放入该位置
	QuickSort(left,k-1);//左边继续快速排序
	QuickSort(k+1,right);//右边继续快速排序

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


void Sort::MergeSort(int *tmp,int left,int right)//归并排序
{
	int mid=(left+right)/2;//找到数组的中心
	if(left==right)
		return;
	MergeSort(tmp,left,mid);//左半边继续归并排序
	MergeSort(tmp,mid+1,right);//右半边继续递归进行归并排序
	for(int i=left;i<=right;i++)//把store中的数据存至tmp
	{
		tmp[i]=store[i];
	}
	int i1=left;
	int i2=mid+1;
	for(int curr=left;curr<right;curr++)
	{
		if(i1==mid+1)//i1越界
			store[curr]=tmp[i2++];
		else 
			if(i2>right)//i2越界
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
	while(2*curr+1<n)//2*curr+1和2*curr+2是curr的左右孩子		
	{
		int max=2*curr+1 ;//定义记录最大值下标为max	
        if(2*curr+2<n) 	
        {
			if(Compare(store[2*curr+1],store[2*curr+2])) //比较左孩子和右孩子
			{
                max=2*curr+2;
            }
        }
        if(Compare(store[curr],store[max]))//若curr处的数据比max处的数据小
        {
             
			Swap(store[curr],store[max]);//交换curr与max的数据
            curr=max;//堆被破坏，需要重新调整
        }
        else
        {
             
			break;//左右孩子均小则堆未破坏，不再需要调整
		}
	}
}
void Sort::HeapSort( int n)
{
    int i=0; //将store[n]建成大根堆,以store[0]为根
    for (i=n/2-1; i>=0; i--)
    {
        BuildHeap(i,n);//从最后一行的非叶子节点处开始比较，最后store[0]为最大值
    }
    for (i=n-1; i>0; i--)
    {
		Swap(store[0],store[i]);//将最大值防在最后一个
        BuildHeap(0, i);//重新调整大根堆
    }
}
int Sort::Range(int start,int end)//算出区间内有多少个数
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
void Sort::List()//显示数据分段
{
	int group=Max/1000+1;
	double *total=new double [group];
	for (int i=0 ; i<group ; i++)
	{
		total [i] = (double)(Range(i*1000,i*1000+1000-1))/num*100;
	}
	cout<<"数据段 "<<setw(20)<<"所占比例"<<endl;
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
		cout<<"随机生成数据的个数n（n<10000）";
		n=rand()%10000;
		cout<<n<<endl;
		Sort s(n);
		int *sort = new int [n];
		for(int i=0;i<n;i++)                               //获得随机数数组
		{
			sort[i]=Min+rand()%(Max-Min);
		}
		s.Create(sort);
		s.List();
		cout<<setw(20)<<"比较次数"<<setw(20)<<"交换次数"<<endl;
		cout<<"----------------------------------------"<<endl;
		//插入排序
		swap=0;
		compare=0;	
		s.InsertSort();
		cout<<"插入排序  "<<compare<<setw(20)<<swap<<setw(20)<<endl;
		//快速排序
	    s.Copy();
		swap=0;
		compare=0;		
		s.QuickSort(0,n-1);	
		cout<<"快速排序  "<<compare<<setw(20)<<swap<<setw(20)<<endl;
		//归并排序	
		s.Copy();
		swap=0;
		compare=0;		
		int *temp= new int[n];
		s.MergeSort(temp,0,n-1);
		cout<<"归并排序  "<<compare<<setw(20)<<swap<<setw(20)<<endl;
		//堆排序
		s.Copy();
		swap=0;
		compare=0;		
		s.HeapSort(n);
		cout<<"堆排序   "<<compare<<setw(20)<<swap<<setw(20)<<endl;
		cout<<"是否继续输入数据？(y/n): "<<endl;
		cin>>answer;
	}while(answer=='y'||answer=='Y');
}
