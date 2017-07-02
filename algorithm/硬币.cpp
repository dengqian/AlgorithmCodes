#include<iostream>
using namespace std;
/*
const int N=100;
struct Object{
	int weight;
	int value;
};
Object obj[N];
int MaxValue(int n,int totalWeight){
	if(n==0)
		return 0;
	if(totalWeight <= obj[n])
		return 0;
}*/
void makeChange(int values[],int number,int money,int coinUsed[]){
	coinUsed[0] = 0;
	for(int i=1;i<=money;i++)
	{
		int minNum = i;
		for(int kinds = 0;kinds<number;kinds ++)
		{
			if(values[kinds] <= i)
			{
				int temp = coinUsed[i-values[kinds]]+1;
				if(temp<minNum)
				{
					minNum = temp;
				}
			}
		}
		coinUsed[i] = minNum;
		cout<<"面值为"<<i<<"的最小硬笔数为："<<endl;
	}
}
int main(){
	int coinValue[5] = { 25, 21, 10, 5, 1 };  
        // 需要找零的面值  
        int money = 63;  
        // 保存每一个面值找零所需的最小硬币数，0号单元舍弃不用，所以要多加1  
        int coinsUsed[64] ;  
        makeChange(coinValue, 5, money, coinsUsed);
		system("pause");
	return 0;
}