#include<string>
#include<queue>
#include<iostream>
#include<sstream>
using namespace std;

// Definition for a binary tree node.
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
        if(root == NULL) return "";
        string ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            root = que.front();
            que.pop();
            if(root == NULL){
                ans += "null,";
            }else{
                ans += (to_string(root->val) + ",");
                que.push(root->left);
                que.push(root->right);
            }
        }
        return ans;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss;
        ss.str(data);
        string item;
        if(!getline(ss, item, ',')) return NULL;
        
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> que;
        que.push(root);
        while(1){
            TreeNode* node = que.front();
            que.pop();
            // 左子树
            if(!getline(ss, item, ',')) break;
            if(item != "null"){
                node->left = new TreeNode(stoi(item));
                que.push(node->left);
            }
            // 右子树
            if(!getline(ss, item, ',')) break;
            if(item != "null"){
                node->right = new TreeNode(stoi(item));
                que.push(node->right);
            }
        }
        return root;
    }
};