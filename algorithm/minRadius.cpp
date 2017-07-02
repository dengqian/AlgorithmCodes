#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<limits>
#include<math.h>

#define N 100000

using namespace std;

struct point{
	double x;
	double y;
};

point p[N + 10];
point po[N + 10];

double min(double a , double b){
	return a < b? a:b; 
}
bool cmp(point a, point b){
	if(a.y<b.y || a.y==b.y && a.x<b.x){
		return true;
	}
	return false;
}
bool comp(point a, point b){
	return a.x<b.x;
}
double dis(point a,point b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
/*bool cmp(const point &a, const point &b){
	if(a.y<b.y || a.y==b.y && a.x<b.x){
		return true;
	}
	return false;
}
bool comp(const point &a, const point &b){
	return a.x<b.x;
}*/
double closestDistance(int start, int end){
	double minDis = numeric_limits<double>::max(); 
	if(end - start <= 2){
		if(end - start == 2){
			minDis = min( min( dis(p[start],p[start+1]), dis(p[start],p[end]) ), dis(p[start+1],p[end]) );
		}
		if(end - start == 1){
			minDis = dis(p[start],p[end]);
		}
		return minDis;
	}
	
	int mid = (start+end) / 2;
	double left = closestDistance(start,mid);
	double right = closestDistance(mid+1,end);
	minDis = min(left,right);
//	cout<<"left "<<left<<" right "<<right<<endl;
	int num = 0; 
	for(int i=start; i<=end; i++){
		if((p[i].y-p[mid].y)*(p[i].y-p[mid].y) <= minDis){
			po[num++] = p[i];
		}
	} 
	sort(po,po+num,comp);
	
	for(int j=0; j<num; j++){
		for(int k=j+1; k<num; k++){
			if((po[j].x-po[k].x) * (po[j].x-po[k].x) >= minDis){
				break;
			}
			minDis = min(minDis,dis(po[j],po[k]));
		}
	}
	return minDis;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF && n!=0){
		for(int i = 0; i < n;i++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		//	cin>>p[i].x>>p[i].y;

		}
		sort(p,p+n,cmp);
		double ans = closestDistance(0,n-1);
		ans = sqrt(ans)/2;
		printf("%.2lf\n",ans);
	//	cout.setf(ios::fixed);
	//	cout.precision(2);
	//	cout<<ans<<endl;
	}
	return 0;
} 
