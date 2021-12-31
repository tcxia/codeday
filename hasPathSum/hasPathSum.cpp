#include <iostream>
#include <vector>

#include "../common/binaryTree.h"
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
// };

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
};

int main() {
    vector<int> vec = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};
    TreeNode* root = constructBinaryTree(vec);

    Solution solve;
    bool flag = solve.hasPathSum(root, 22);
    cout << flag << endl;
}