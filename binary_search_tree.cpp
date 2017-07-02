#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <cmath>
#define ll unsigned long long
#define INF (~(1<<31))
using namespace std;
class Node
{
public:
	int val;
	Node(int v):val(v){left = NULL; right = NULL;};
	Node* left;
	Node* right;
	//~Node();
};
bool insertNode(Node* &t, int num){
	if(!t){
		t = new Node(num);
	}
	else if(num == t->val) return false;
	else if (num < t->val) {
		insertNode(t->left, num);
	}
	else {
		insertNode(t->right, num);
	}
	return true;
}

bool deleteNode(Node* &t){
	if(!t) return false;
	if(!t->left && !t->right) {
		delete t;
		t = NULL;
	}
	else if (!t->left && t->right){
		Node *tmp = t;
		t = t->right;
		delete tmp;
	}
	else if (!t->right && t->left){
		Node *tmp = t;
		t = t->left;
		delete tmp;
	}else{
		Node* tmp = t;
		Node* l = t->left;
		while(l->right){
			tmp = l;
			l = l->right;
		}
		tmp->right = l->left;
		t->val = l->val;
		delete l;
	}
	return true;
}
bool deleteTreeNode(Node* &t, int num){
	if (!t) return false;
	if(t->val == num) {
		deleteNode(t);
		return true;
	}
	else if (t->val > num)  return deleteTreeNode(t->left, num);
	else return deleteTreeNode(t->right, num);
}

bool findNode(Node* t, int num){
	if(!t) return false;
	if(t->val == num) return true;
	else if(t->val > num) findNode(t->left, num);
	else findNode(t->right, num);
	return false;
}

void midOrderTraverse(Node* t){
	if(!t) return;
	midOrderTraverse(t->left);
	cout<<t->val<<endl;
	midOrderTraverse(t->right);
}

void preOrderTraverse(Node* t){
	if(!t) return;
	cout<<t->val<<endl;
	preOrderTraverse(t->left);
	preOrderTraverse(t->right);
}
int main(){
	Node* root=NULL;
	int n;
	cin>>n;
	int tmp;
	while(n--){
		cin>>tmp;
		insertNode(root, tmp);
	}
	midOrderTraverse(root);
	deleteTreeNode(root, 5);
	midOrderTraverse(root);
	return 0;
}









