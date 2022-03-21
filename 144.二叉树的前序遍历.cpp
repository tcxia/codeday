/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <stack>
#include <vector>
using namespace std;

class Solution {
    void traversal(TreeNode *root, vector<int> &nums) {
        if (root) {
            nums.push_back(root->val);
            traversal(root->left, nums);
            traversal(root->right, nums);
        }
    }

   public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;
        if (root == nullptr) return result;
        TreeNode* cur = root;
        while (!st.empty() || cur != nullptr) {
            while (cur != nullptr){
                result.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
        return result;
    }



    vector<int> preorderTraversalv2(TreeNode *root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
// @lc code=end
