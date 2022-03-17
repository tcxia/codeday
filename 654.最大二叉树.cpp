/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    TreeNode *traversal(vector<int> &nums, int left, int right) {
        if (left == right) return nullptr;

        // int maxvalue = *max_element(left, right);
        int maxvalue = INT32_MIN;
        for (int i = left; i < right; i++) {
            if (nums[i] >= maxvalue) maxvalue = nums[i];
        }
        TreeNode *root = new TreeNode(maxvalue);

        if (right - left == 1) return root;

        int delimterIndex;
        for (delimterIndex = 0; delimterIndex < nums.size(); delimterIndex++) {
            if (nums[delimterIndex] == maxvalue) break;
        }

        int leftBegin = left;
        int leftEnd = delimterIndex;

        int rightBegin = delimterIndex + 1;
        int rightEnd = right;

        root->left = traversal(nums, leftBegin, leftEnd);
        root->right = traversal(nums, rightBegin, rightEnd);

        return root;
    }

   public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        if (nums.size() == 0) return nullptr;
        return traversal(nums, 0, nums.size());
    }
};
// @lc code=end
