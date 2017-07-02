#include<iostream>
using namespace std;
int* bfind(int* start,int* end,int value)
{
	if(start==end)return start;
	while(start+1<end)
	{
		int* mid=start+(end-start)/2;
		if(value<*mid)end=mid;
		else start=mid;
	}
	if(*start<value)start++;
	return start;
}
template<class T>void arraycopy(T* dest,T* src,int count)
{
	memmove(dest,src,count*sizeof(T));
}
class node
{
	node(const node&);
public:
	node** child;
	int* data;
	int count;
	int degree;
	explicit node(int d):degree(d),count(0)
	{
		child=new node*[degree*2];
		data=new int[degree*2-1];
		memset(child,0,sizeof(node*)*degree*2);
	}
	~node(){delete[] data,delete[] child;}
	void spiltchild(int index)
	{
		arraycopy(data+index+1,data+index,count-index);
		arraycopy(child+index+2,child+index+1,count-index);
		data[index]=child[index]->data[degree-1];
		child[index+1]=new node(degree);
		child[index]->count=degree-1;
		child[index+1]->count=degree-1;
		arraycopy(child[index+1]->data,child[index]->data+degree,degree-1);
		arraycopy(child[index+1]->child,child[index]->child+degree,degree);
		count++;
	}
	void mergechild(int index)
	{
		arraycopy(child[index]->data+degree,child[index+1]->data,degree-1);
		arraycopy(child[index]->child+degree,child[index+1]->child,degree);
		child[index]->data[degree-1]=data[index];
		child[index]->count+=child[index+1]->count+1;
		count--;
		delete child[index+1];
		arraycopy(data+index,data+index+1,count-index);
		arraycopy(child+index+1,child+index+2,count-index);
	}
	void leftrotate(int index)
	{
		child[index]->data[child[index]->count++]=data[index];
		child[index]->child[child[index]->count]=child[index+1]->child[0];
		data[index]=child[index+1]->data[0];
		arraycopy(child[index+1]->child,child[index+1]->child+1,child[index+1]->count);
		arraycopy(child[index+1]->data,child[index+1]->data+1,--child[index+1]->count);
	}
	void rightrotate(int index)
	{
		arraycopy(child[index+1]->data+1,child[index+1]->data,child[index+1]->count);
		arraycopy(child[index+1]->child+1,child[index+1]->child,++child[index+1]->count);
		child[index+1]->data[0]=data[index];
		child[index+1]->child[0]=child[index]->child[child[index]->count];
		data[index]=child[index]->data[--child[index]->count];
	}
	bool insert(int value)
	{
		int index=bfind(data,data+count,value)-data;
		if(index<count && data[index]==value)return false;
		else if(child[index])
		{
			if(child[index]->count==degree*2-1)
			{
				spiltchild(index);
				if(value>data[index])index++;
				else if(value==data[index])return false;
			}
			return child[index]->insert(value);
		}
		else
		{
			arraycopy(data+index+1,data+index,count++-index);
			data[index]=value;
			return true;
		}
	}
	bool remove(int value)
	{
		int index=bfind(data,data+count,value)-data;
		if(child[index])
		{
			if(child[index]->count<degree)
				if(index<count)
					if(child[index+1]->count>=degree)
						leftrotate(index);
					else mergechild(index);
				else
					if(child[index-1]->count>=degree)
						rightrotate(index-1);
					else mergechild(--index);
			else if(index<count && data[index]==value)
				swap(data[index],child[index]->data[child[index]->count-1]);
			return child[index]->remove(value);
		}
		else if(index<count && data[index]==value)
		{
			arraycopy(data+index,data+index+1,--count-index);
			return true;
		}
		else return false;
	}
};
void output(node* value,int deep=0)
{
	if(value)
	{
		for(int i=0;i<value->count;i++)
		{
			output(value->child[i],deep+1);
			for(int j=0;j<deep;j++)cout<<"\t";
			cout.width(8);
			cout<<value->data[i];
			for(j=deep;j<5;j++)cout<<"________";
			cout<<endl;
		}
		output(value->child[value->count],deep+1);
	}
}
class tree
{
public:
	node* root;
	int degree;
	explicit tree(int degree):root(new node(degree)),degree(degree){;}
	bool insert(int value)
	{
		if(root->count==degree*2-1)
		{
			node* temp=new node(degree);
			temp->child[0]=root;
			root=temp;
		}
		return root->insert(value);
	}
	bool remove(int value)
	{
		bool rtn=root->remove(value);
		if(root->count==0 && root->child[0])root=root->child[0];
		return rtn;
	}
	void output()
	{
		::output(root);
	}
};
int main()
{
	cout<<"输入节点个数和阶数：";
	int count;int degree;
	cin>>count>>degree;
	tree btree(degree);
	int value;
	cout<<"输入关键字：";
	for(int i=0;i<count;i++)
	{
		cin>>value;
		btree.insert(value);
	}
	btree.output();
	while(true)
	{
		char cmd;
		cout<<"输入操作指令："<<endl;
		cout<<" //  插入单个关键字：I 76"<<endl;
		cout<<" //  删除单个关键字：D 50"<<endl;
		cout<<" //  插入多个关键字：MI 76,23,51#"<<endl;
		cout<<" //  删除多个关键字：MD 50,4,14#"<<endl;
		cout<<" //  退出：其它格式"<<endl;
		cout<<"请按上述指令格式输入操作指令："<<endl;
		cin>>cmd;
		if(cmd=='i' || cmd=='I')
			for(cin.get(cmd);cmd==' ';cin.get(cmd))
			{
				cin>>value;
				btree.insert(value);
			}
		else
			for(cin.get(cmd);cmd==' ';cin.get(cmd))
			{
				cin>>value;
				btree.remove(value);
			}
		btree.output();
	}
	system("pause");
	return 0;
}
