#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <cmath>
#define ll unsigned long long
#define INF (~(1<<31))
using namespace std;

struct BinaryTreeNode
{
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(int n):val(n){
		left = NULL;
		right = NULL;
	}
};

void PrePrint(BinaryTreeNode* root){
	if(root == NULL) return;
	cout<<root->val<<endl;
	PrePrint(root->left);
	PrePrint(root->right);
}

void GetMirrorOfBinTree(BinaryTreeNode* root){
	if(root == NULL || root->left==NULL && root->right==NULL){
		return;
	}
	swap(root->left, root->right);
	if(root->left) GetMirrorOfBinTree(root->left);
	if(root->right) GetMirrorOfBinTree(root->right);
}

int main(){
	BinaryTreeNode* root =new BinaryTreeNode(0);
	root->left = new BinaryTreeNode(1);
	root->right = new BinaryTreeNode(2);
	root->left->left = new BinaryTreeNode(3);
	root->left->right = new BinaryTreeNode(4);
	GetMirrorOfBinTree(root);
	PrePrint(root);
	return 0;
}