#include<iostream>
#include<stdio.h>
#include<limits>
#include<algorithm>
#include<vector>
#define N 100

using namespace std;

struct edge{
    int cost;
    int from;
    int to;
};

int fa[N];
edge e[27*15];

bool cmp(edge a,edge b){
    return a.cost<b.cost;
}

void init(int n){
    for(int i=0;i<n;i++){
        fa[i] = i;
    }
}

int root(int x){
    return x == fa[x] ? x : fa[x] = root(fa[x]);
}

void unin(int a,int b){
    int aa = root(a);
    int bb = root(b);
    if(aa != bb){
        fa[bb] = aa;
    }
}

int main(){
    init(N);
    int n = 0;
    char a;
    int num;
    char b;
    int cost;
    while(scanf("%d",&n) != EOF && n != 0){
        int cnt = 0;
        for(int i=0;i<n-1;i++){
            //scanf("%c%d",&a,&num);
            cin>>a>>num;
            for(int j=0;j<num;j++){
                //scanf("%c%d",&b,&cost);
                cin>>b>>cost;
                e[cnt].cost = cost;
                e[cnt].from = a - 'A';
                e[cnt++].to = b - 'A';
            }
        }
        sort(e,e+cnt,cmp);
        int sum = 0;
        for(int k=0;k<cnt;k++){
            int from = root(e[k].from);
            int to = root(e[k].to);
    //        cout<<from<<" "<<to<<endl;
            if(from != to){
                sum += e[k].cost;
                unin(from,to);
            }
        }
    /*    for(int kk=0;kk<cnt;kk++){
            cout<<fa[kk]<<endl;
        }*/
        printf("%d\n",sum);
    }
    return 0;
}
