#include<stdio.h>
#include<stdlib.h>
#define max 11000000000
int a[1000][1000];
int d[1000];//d表示某特定边距离
int p[1000];//p表示永久边距离
int i,j,k;
int m;//m代表边数
int n;//n代表点数
int main(){
	scanf("%d%d",&n,&m);
	int min1;
	int x,y,z;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
		a[y][x]=z;
	}
	for(i=1;i<=n;i++)
		d[i]=max;
	d[1]=0;
	for(i=1;i<=n;i++){
		min1=max;
		for(j=1;j<=n;j++)
			if(!p[j]&&d[j]<min1){
				min1=d[j];
				k=j;
			}
		p[k]=1;
		for(j=1;j<=n;j++)
			if(a[k][j]!=0&&!p[j]&&d[j]>d[k]+a[k][j])
				d[j]=d[k]+a[k][j];
	}
	for(i=1;i<=n;i++)
		printf("%d",d[i]);
	return0;
}
