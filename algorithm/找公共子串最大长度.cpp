#include <iostream>  
#include <cstdlib>  
#include <cstring>  
  
using namespace std;  

void initIndexs(char ch, char * str, int *indexs)  
{  
    for(unsigned int i=0,j=0; i<strlen(str);i++)  
    {  
        if(ch == str[i])  
            indexs[j++] = i+1;  
    }  
}  

char * LCS(char *str1, char *str2, int *maxLen)  
{  
    int *indexs=NULL; //存放在str2中与str1[i]中字符相等的字符所在位置，  
  
    int start,end;//最长公共子序列的起始和终止位置  
    int len=0;//公共子字符串的长度  
    int offset=0;//最长公共子字符串起始位置的偏移量  
  
    for(unsigned int i=0; i<strlen(str1); i++)//遍历str1  
    {  
        start = i;  
  
        free(indexs);   //重新分配内存并初始化为0  
        indexs = (int *) calloc(strlen(str2),sizeof(int));  
        initIndexs(str1[i], str2, indexs);  
  
        for(int j=0;  indexs[j] !=0; j++)//找出str2中与str1中字符相等的字符串  
        {  
            end = i + 1;  
            for(; str1[end] == str2[indexs[j]]; )  
            {  
                end++;  indexs[j]++;  
            }  
            len = end - start;  
  
            if( len > *maxLen)  
            {  
                *maxLen = len;   //找出最长公共子字符串的长度  
                offset = start;  
            }  
        }  
    }  
  
    return str1+offset;  
}  
  
int main()  
{  
    char  str1[20]="aocdfacddcdfe";  
    char str2[20]="pmcdfacdfe";  
    int len=0;  
    char *ch = LCS(str1,str2,&len);  
    cout <<"The longest common string is ";  
    for(int i=0;i<len;i++)  
    cout << ch[i];  
    return 0;  
}  
