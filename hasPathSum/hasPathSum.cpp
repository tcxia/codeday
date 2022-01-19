#include <iostream>
#include <vector>

#include "../common/binaryTree.h"
using namespace std;
class Solution {
    void backtracking(TreeNode* cur, vector<int>& path, vector<vector<int>>& result) {
        path.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr) {
            result.push_back(path);
        }
        if (cur->left) {
            backtracking(cur->left, path, result);
            path.pop_back();
        }
        if (cur->right) {
            backtracking(cur->right, path, result);
            path.pop_back();
        }
    }

    bool traversal(TreeNode* cur, int count) {
        if (cur->left == nullptr && cur->right == nullptr && count == 0) return true;
        if (cur->left == nullptr && cur->right == nullptr) return false;

        if (cur->left) {
            count -= cur->left->val;
            if (traversal(cur->left, count)) return true;
            count += cur->left->val;
        }

        if (cur->right) {
            count -= cur->right->val;
            if (traversal(cur->right, count)) return true;
            count += cur->right->val;
        }
        return false;
    }

   public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        vector<int> path;
        vector<vector<int>> result;
        backtracking(root, path, result);

        for (auto& res : result) {
            int sum = 0;
            for (int i = 0; i < res.size(); i++) {
                sum += res[i];
            }
            if (sum == targetSum) {
                return true;
            }
        }
        return false;
    }

    bool hasPathSumv2(TreeNode* root, int targetSum) {
        // if(cur)
        if (root == nullptr) return false;
        return traversal(root, targetSum - root->val);
    }
};

int main() {
    vector<int> vec = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};
    TreeNode* root = constructBinaryTree(vec);

    Solution solve;
    bool flag = solve.hasPathSum(root, 22);
    cout << flag << endl;
}