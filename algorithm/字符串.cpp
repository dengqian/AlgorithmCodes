#include<iostream>
#include<string>
using namespace std;
const int N = 80;
void shape(char a[],int n1,int n2)
{
	int len = strlen(a);
	int i,j;
	for(i=0;i<n1;i++)
	{
		cout<<a[i];
		for(j=0;j<n2-2;j++)
		{
			if(i == n1-1)
			{
				cout<<a[n1+j];
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<a[len-i-1]<<endl;
	}
}
int main(){
	char a[N];
	while(cin>>a) {
		int len = strlen(a);
		int length = len+2;
		int n1,n2,n3;
		if(length %3 == 0)	{
			n1 = n2 = n3 = length/3;
		}else{
			 n3 = n1 = int(length/3);
			 n2 = length - 2*n1;
		}
		shape(a,n1,n2);
	}
	return 0;
}
