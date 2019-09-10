/*
二叉树的先序、中序、后序遍历：
深度优先遍历（DFS），用栈或者递归；

二叉树的层次遍历：
宽度优先遍历（BFS），用队列；
 */
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 迭代法先根遍历(PreOrder)
class Solution {
   public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                ans.push_back(root->val);
                root = root->left;
            }
            root = s.top();
            s.pop();
            root = root->right;
        }
        return ans;
    }
};

// 迭代法中根遍历(InOrder)
class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};

// 迭代法后根遍历(PostOrder)
class Solution {
   public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* pre = NULL;
        stack<TreeNode*> s;
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            if (root->right && pre != root->right) {
                root = root->right;
            } else {
                s.pop();
                ans.push_back(root->val);
                pre = root;
                root = NULL;
            }
        }
        return ans;
    }
};

/*
另外一种中根遍历：
先右子树，再根结点，再左子树
对于BST，这样遍历可以得到结点的降序排列，有时候会很有用。
参考：LeetCode：538. Convert BST to Greater Tree
 */
class Solution {
   public:
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->right;
            }
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            root = root->left;
        }
        return ans;
    }
};

// 二叉树层次遍历
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            vector<int> vec;
            int n = que.size();
            for (int i = 0; i < n; i++) {
                root = que.front();
                vec.push_back(root->val);
                que.pop();
                if (root->left) que.push(root->left);
                if (root->right) que.push(root->right);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};