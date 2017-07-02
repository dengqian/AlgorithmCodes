#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class  BinTreeNode
{
public:
	char it;			//结点值
	BinTreeNode *leftChild,*rightChild;//左孩子，右孩子。
	BinTreeNode(){
		leftChild = NULL;
		rightChild = NULL;	
	} 
};
BinTreeNode* CreateBiTree()//先序递归创建树
{
    int p;
    cin>>p;
	BinTreeNode* T;
    if(p!=0)
    {
        T=new BinTreeNode;
        T->it=p;
        T->leftChild=CreateBiTree();
        T->rightChild=CreateBiTree();
    }else{
        T = NULL;
    }
  	return (T);
}
void scanTree(BinTreeNode *root,int& min,int& max){
	int temp = root->it;
	if(temp<min){
		min = temp;
	}
	if(temp>max){
		max = temp;
	}
	if(root->leftChild!=NULL){
		scanTree(root->leftChild,min,max);
	}
	if(root->rightChild!=NULL){
		scanTree(root->rightChild,min,max);
	}
}
int main(){	
	BinTreeNode *root;
	root=CreateBiTree(); 
	int min = root->it;
	int max = root->it;
	scanTree(root,min,max);
	cout<<max-min<<endl;
	return 0;
}
