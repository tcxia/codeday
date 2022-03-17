/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

#include <vector>
using namespace std;

class Solution {
    TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& preorder, int preorderBegin, int preorderEnd){
        if (preorderBegin == preorderEnd) return nullptr;

        int rootValue = preorder[preorderBegin];
        TreeNode* root = new TreeNode(rootValue);

        if (preorderEnd - preorderBegin == 1) return root; // 如果只有一个元素，直接返回root

        int delimiterIndex; // 寻找分割点
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++){
            if (inorder[delimiterIndex] == rootValue) break;
        }

        // 切割中序数组
        // 中序左区间 左闭右开 [leftInorderBegin, leftInorderEnd)
        int leftInorderBegin = inorderBegin; 
        int leftInorderEnd = delimiterIndex;

        // 中序右区间 左闭右开 [rightInorderBegin, rightInorderEnd)
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        // 切割前序数组
        int leftPreorderBegin = preorderBegin + 1;
        int leftPreorderEnd = preorderBegin + 1 + delimiterIndex - inorderBegin;

        int rightPreorderBegin = preorderBegin + 1 + (delimiterIndex - inorderBegin);
        int rightPreorderEnd = preorderEnd;

        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, preorder, leftPreorderBegin, leftPreorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, preorder, rightPreorderBegin, rightPreorderEnd);

        return root;
    }

   public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (inorder.size() == 0 || preorder.size() == 0) return nullptr;
        return traversal(inorder, 0, inorder.size(), preorder, 0, preorder.size());

    }
};
// @lc code=end
