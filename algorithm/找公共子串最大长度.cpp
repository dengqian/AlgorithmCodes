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
    int *indexs=NULL; //�����str2����str1[i]���ַ���ȵ��ַ�����λ�ã�  
  
    int start,end;//����������е���ʼ����ֹλ��  
    int len=0;//�������ַ����ĳ���  
    int offset=0;//��������ַ�����ʼλ�õ�ƫ����  
  
    for(unsigned int i=0; i<strlen(str1); i++)//����str1  
    {  
        start = i;  
  
        free(indexs);   //���·����ڴ沢��ʼ��Ϊ0  
        indexs = (int *) calloc(strlen(str2),sizeof(int));  
        initIndexs(str1[i], str2, indexs);  
  
        for(int j=0;  indexs[j] !=0; j++)//�ҳ�str2����str1���ַ���ȵ��ַ���  
        {  
            end = i + 1;  
            for(; str1[end] == str2[indexs[j]]; )  
            {  
                end++;  indexs[j]++;  
            }  
            len = end - start;  
  
            if( len > *maxLen)  
            {  
                *maxLen = len;   //�ҳ���������ַ����ĳ���  
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
