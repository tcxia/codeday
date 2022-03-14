/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 *
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <stack>

using namespace std;

class Solution {
   public:
    vector<int> inorderTraversalv2(TreeNode *root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }

    void inorder(TreeNode* root, vector<int>& res){
        if (!root) {return;}

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty()){
            if (cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
    

};
// @lc code=end
