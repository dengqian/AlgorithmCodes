#include<iostream>  
using namespace std;  

const int c = 10;             //背包的容量  
const int w[] = {0,2,2,6,5,4};//物品的重量，其中0号位置不使用 。   
const int v[] = {0,6,3,5,4,6};//物品对应的代价，0号位置置为空。  
const int n = sizeof(w)/sizeof(w[0]) - 1 ; //n为物品的个数   
int x[n+1];  
void package(int m[][11],const int w[],const int v[],const int n)
{
	int i,j;
	for(j=0;j<=c;j++)
	{
		if(j<w[n])
			m[n][j] = 0;
		else
			m[n][j] = v[n];
	}
	for(i=n-1;i>=1;i--)
	{
		for(j=0;j<=c;j++)
		{
			if(j < w[i])
				m[i][j] = m[i+1][j];
			else
			{
				m[i][j] = m[i+1][j] > m[i+1][j-w[i]]+v[i] ? m[i+1][j] : m[i+1][j-w[i]] + v[i];
			}
		}
	}
}

void answer(int m[][11],const int n)  
{  
    int j = c;  
    int i;  
    for(i = 1; i <= n-1; i++)  
        if(m[i][j] == m[i+1][j]) x[i] = 0;  
		else{   
			x[i] = 1;  
            j = j - w[i];  
        }      
    x[n] = m[i][j] ? 1 : 0;   
}  
int main()  
{  
 int m[6][11]={0};  
   
 package(m,w,v,n);  
 for(int i = 0; i <= 5; i++)  
 {  
     for(int j = 0; j <= 10; j++)  
     printf("%2d ",m[i][j]);  
     cout << endl;   
 }   
 answer(m,n);  
 cout << "The best answer is:\n";  
 for(i = 1; i <= 5; i++)  
 cout << x[i] << " ";  
 system("pause");  
 return 0;  
} 
