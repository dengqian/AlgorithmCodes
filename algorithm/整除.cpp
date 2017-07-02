#include <iostream>
#include <math.h>
using namespace std;
void fun1(int a[])
{
        int k=0;
        int i,j;
        for(i=2;i<1000;i++)
        {
                bool flag=false;
                for(j=2;j<=sqrt(i);j++)
                {
                        if(i%j==0)
                        {
                                flag=true;
                                break;
                        }
                }
                if(flag==false)
                        a[k++]=i;
        }
}
void fun2(int t[],int s[],int a)
{
        int j;
        for(j=0;t[j]!=0;j++)
        {
                if(a<t[j])
                        break;
                else if(a%t[j]==0)
                {
                        do
                        {
                                s[j]++;
                                a=a/t[j];
                        }
                        while(a%t[j]==0);

                }
        }
}
int main()
{
        int n,a;
        
        int k;
        int i;
        int t[1000]={0};
        fun1(t);
        while(cin>>n>>a)
        {
                int max=1000;
                int s1[1000]={0};
                int s2[1000]={0};
                
                for(i=2;i<=n;i++)
                        fun2(t,s1,i);
                fun2(t,s2,a);
                for(i=0;i<1000;i++)
                {
                        if(s2[i]!=0)
                        {
                                int temp=s1[i]/s2[i];
                                if(temp<max)
                                        max=temp;
                        }
                }
                cout<<max<<endl;

        }
}
