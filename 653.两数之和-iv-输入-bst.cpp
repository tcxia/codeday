/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    bool findTarget(TreeNode *root, int k) {
        vector<int> nums;
        traversal(root, nums);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == k) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
