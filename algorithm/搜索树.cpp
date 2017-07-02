#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class BSTnode{
	public:
	int a;
	BSTnode * lchild;
	BSTnode * rchild;
};
BSTnode* searchBST(BSTnode * root,int a){
	if(root->lchild==NULL&&a<root->a || root->rchild==NULL&&a>root->a ){
		return root;
	}else if(a<root->a){
		return searchBST(root->lchild,a);
	}else{
		return searchBST(root->rchild,a);
	}
}
void createBSTree(BSTnode* &root,int a){
	if(root == NULL){
		root=new BSTnode;
		root->a = a;
		root->lchild=NULL;
		root->rchild=NULL;
	}else{
		BSTnode * newnode = new BSTnode;
		newnode->a = a;
		newnode->lchild = NULL;
		newnode->rchild = NULL;
		BSTnode * tempnode = searchBST(root,a);
		if(a > tempnode->a){
			tempnode->rchild = newnode;
		}else{
			tempnode->lchild = newnode;
		}
	} 
}
void  PreOrder(BSTnode* T,string &s)
{
    if(T){
        s+=(T->a + '0');
        PreOrder(T->lchild,s);
        PreOrder(T->rchild,s);
    }
}
void MidOrder(BSTnode* T,string &s){
	if(T){
        MidOrder(T->lchild,s);
		s+=(T->a + '0');
        MidOrder(T->rchild,s);
    }
}
int main(){
	int n;
	while(cin>>n && n){	
		string str;
		string strM;
		char s[10];
		cin>>s;
		BSTnode * root = NULL; 
		for(int i=0;i<strlen(s);i++){
			createBSTree(root,s[i]-'0');
		}
		PreOrder(root,str);
		MidOrder(root,strM);
	//	cout<<str<<" "<<strM<<endl;
		for(int j=0;j<n;j++){
			char ss[10];
			string stri; 
			string striM;
			cin>>ss;
			BSTnode* root1 = NULL;
			for(int k=0;k<strlen(ss);k++){
				createBSTree(root1,ss[k]-'0');
			}
			PreOrder(root1,stri);
			MidOrder(root1,striM);
		//	cout<<stri<<" "<<striM<<endl;
			if(str==stri && strM==striM){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
} 
