#include<iostream>
using namespace std;
class point//点结构
{
 public:
	int id;//点的位置的记录。
	int x;//横坐标
	int y;//纵坐标
};
int n;//点对的数目
point* mPoint;
point* Qx ;
point* Qy ;
point* rx;
point* ry;
point* Rx ;
point* Ry ;
point* S;
int num=0;
//快速排序得到Px
void QuickSortX(point a[],int low,int high)
{
	if(low >= high)
	{
		return;
	}
	int first=low;
	int last=high;
	point key=a[first];//用字表的第一个记录作为枢轴
	while(first<last)
	{
		while(first<last && a[last].x>=key.x)
			--last;
		a[first]=a[last];//将比第一个小的移到低端
		while(first<last && a[first].x<=key.x)
			++first;
		a[last]=a[first];//将比第一个大的移到高端
	}
	a[first]=key;//枢轴记录到位
	QuickSortX(a,low,first-1);
	QuickSortX(a,last+1,high);
}
//快速排序得到Py
void QuickSortY(point a[],int low,int high)
{
	if(low >= high)
	{
		return;
	}
	int first=low;
	int last=high;
	point key=a[first];//用字表的第一个记录作为枢轴
	while(first<last)
	{
		while(first<last && a[last].y>=key.y)
			--last;
		a[first]=a[last];//将比第一个小的移到低端
		while(first<last && a[first].y<=key.y)
			++first;
		a[last]=a[first];//将比第一个大的移到高端
	}
	a[first]=key;//枢轴记录到位
	QuickSortY(a,low,first-1);
	QuickSortY(a,last+1,high);
}
int min(int a,int b)
{
	return a<b?a:b;
}
int Dis(point a,point b)
{
	int dis = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
	return dis;
}
int abs(int a)
{
	if(a>=0)
		return a;
	else 
		return -a;
}
point* ClosestPairRec(point Px[],point Py[],int CurrLength)
{
	point* PointPair = new point[2];
	int minDis;
	//递归的出口
	int minx = 0;
	int minx1 = 1;
	num++;
	if(CurrLength <= 3)
	{
		int minDis = Dis(Px[0],Px[1]);
		for(int i=0;i<CurrLength;i++)
			for(int j=i+1;j<CurrLength;j++)
			{
				if(Dis(Px[i],Px[j]) < minDis)
				{
					minDis = Dis(Px[i],Px[j]);
					minx = i;
					minx1 = j;
				}
			}
		PointPair[0] = Px[minx];
		PointPair[1] = Px[minx1];
		num=0;
		return PointPair;
	}

	//定义和以O(n)复杂度构造Qx,Qy,Rx,Ry,
	int j = 0;
	int k = 0;
	int i = 0;
	for(i=0;i<CurrLength;i++)
	{
		if(i<CurrLength/2)
		{
			Qx[i] = Px[i];//Qx和Rx初始化后即建立好。
		}else
		{
			Rx[i-CurrLength/2] = Px[i];
		}
		if(Py[i].x < Px[CurrLength/2].x && j<CurrLength/2)
			Qy[j++] = Py[i];
		else if(k<CurrLength-CurrLength/2)
			Ry[k++] = Py[i];
	}
	cout<<CurrLength<<" "<<"Px[0]"<<Px[0].x<<Px[0].y<<endl;
	for(i=0;i<CurrLength/2;i++)
		cout<<"Qx:"<<Qx[i].x<<Qx[i].y<<"Qy:"<<Qy[i].x<<Qy[i].y<<"Rx:"<<Rx[i].x<<Rx[i].y<<"Ry:"<<Ry[i].x<<Ry[i].y<<endl;
	point* q = new point[2];
	point* r = new point[2];
	q = ClosestPairRec(Qx,Qy,CurrLength/2);
	if(num==0)
	{
		Rx = rx;
		Ry = ry;
	}
	r = ClosestPairRec(Rx,Ry,CurrLength-CurrLength/2);
	int	dq = Dis(q[0],q[1]);
	int dr = Dis(r[0],r[1]);
	int delta = min(dq,dr);
	if(delta == dq)
		PointPair = q;
	else
		PointPair = r;
	minDis = delta;


	//接下来找分割线两边是否存在点对的距离小于delta;
	int	maxX = Qx[CurrLength/2-1].x;
	int n0=0;
	for(i=0;i<CurrLength;i++)
			if(abs(Py[i].x-maxX)<delta)
				S[n0++] = Py[i];
	for(i=0;i<n0;i++)
		cout<<S[i].x<<S[i].y<<endl;
	//寻找15个点之内的点距离最小的点对。
	int CurrMinDis = Dis(S[0],S[1]);
	point* a = new point[2];
	if(n0<2)
		a=q;
	else{
		a[0] = S[0];
		a[1] = S[1];
	}
	int m=n0;
	for(i=0;i<n;i++)
	{
		if(n0>i+15)
			m = i+15;
		else
			 m=n0;
		for(j=i+1;j<m;j++)
		{
			int tempDis = Dis(S[i],S[j]);
			if(tempDis < CurrMinDis)
			{
				CurrMinDis = tempDis;
				a[0] = S[i];
				a[1] = S[j];
			}
		}
	}
	int ds = Dis(a[0],a[1]);
	if(ds<delta)
		return a;
	else if(dq<dr)
		return q;
	else
		return r;
}
	
point* ClosestPair()
{	
	point* Px;
	point* Py;
	Px=new point[n];
	Py=new point[n];
	for(int i=0;i<n;i++)
	{
		Px[i]=mPoint[i];
		Py[i]=mPoint[i];
	}
	QuickSortX(Px,0,n-1);
	QuickSortY(Py,0,n-1);
	int j=0;
	int k=0;
	for(i=0;i<n;i++)
	{
		if(i>=n/2)
		{
			rx[i-n/2] = Px[i];
		}
		if(Py[i].x < Px[n/2].x && j<n/2)
		{k=k;}
		else if(k<n-n/2)
			ry[k++] = Py[i];
	}
	for(i=0;i<n/2;i++)
	{
		cout<<"r"<<rx[i].x<<rx[i].y<<ry[i].x<<ry[i].y<<endl;
	}
	point* Result = new point[2];
	Result = ClosestPairRec(Px,Py,n);
	return Result;
}
int main()
{
	cin>>n;
	mPoint= new point[n];
	Qx = new point[n/2];
	Qy = new point[n/2];
	Rx = new point[n-n/2];
	Ry = new point[n-n/2];
	rx = new point[n-n/2];
	ry = new point[n-n/2];
	S = new point[n];
	for(int i=0;i<n;i++)
	{
		cin>>mPoint[i].x>>mPoint[i].y;
		mPoint[i].id=i;
	}
	point*ResultPair = new point[2];
	ResultPair = ClosestPair();
	int lenght=(ResultPair[1].x-ResultPair[0].x)*(ResultPair[1].x-ResultPair[0].x)+(ResultPair[1].y-ResultPair[0].y)*(ResultPair[1].y-ResultPair[0].y);
	cout<<lenght<<endl;
	delete mPoint;
	delete Qx;
	delete Qy;
	delete Rx;
	delete Ry;
	delete S;
	return 0;
}