#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<int> result;

   public:
    // 递归搜索
    vector<int> postorderTraversal(TreeNode *root) {
        if (root) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            result.push_back(root->val);
        }
        return result;
    }

    vector<int> postorderTraversalv2(TreeNode *root) {
        stack<TreeNode *> st;
        if (root == NULL) return result;
        TreeNode* cur = root; // 设定指针
        if(!st.empty() || cur != NULL){
            if (cur != NULL){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top(); // 返回栈顶元素但是不是删除
                st.pop(); // 删除栈顶元素
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};
