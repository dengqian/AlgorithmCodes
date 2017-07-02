#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <sstream>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if(!root) return ans;
        else ans = to_string(root->val);
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            queue<TreeNode*> qq;
            while(!q.empty()){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left) {
                    qq.push(cur->left);
                    ans += "," + to_string(cur->left->val);
                }else if(!q.empty()) ans += ",null";
                if(cur->right) {
                    qq.push(cur->right);
                    ans += "," + to_string(cur->right->val);
                }else if(!q.empty()) ans += ",null";
            }
            q = qq;
        }
        //cout << ans <<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root;
        if(data =="") return root;
        stringstream str;
        str.str(data);
        string cur;
        queue<TreeNode*> q;
        getline(str, cur, ',');
        root = new TreeNode(stoi(cur));
        q.push(root);
        int cnt = 0;
        while(!q.empty()){
            queue<TreeNode*> qq;
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                cout << cur << endl;
                if(getline(str, cur, ',') && cur!="null"){
                    node->left = new TreeNode(stoi(cur));
                    qq.push(node->left);
                }
                if(getline(str, cur, ',') && cur!="null"){
                    node->right = new TreeNode(stoi(cur));
                    qq.push(node->right);
                }
            }
            q = qq;
        }
        return root;
    }
};

int main(){
	Codec codec;
	TreeNode* root = codec.deserialize("1,2,3,null,4");
	cout<<codec.serialize(root);
	return 0;
}


