#include "../common/binaryTree.h"

class Solution {
    vector<vector<int>> paths;
    vector<int> path;
    void backtracking(TreeNode* tree, vector<int>& path, int a, int b) {
        path.push_back(tree->val);
        if (tree->val == a || tree->val == b) {
            paths.push_back(path);
        }
        if (tree->left) {
            backtracking(tree->left, path, a, b);
            path.pop_back();
        }

        if (tree->right) {
            backtracking(tree->right, path, a, b);
            path.pop_back();
        }
    }

   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        paths.clear();
        path.clear();
        backtracking(root, path, p->val, q->val);

        vector<int> pathp = paths[0];
        vector<int> pathq = paths[1];

        for (int i = pathp.size() - 1; i >= 0; i--) {
            for (int j = pathq.size() - 1; j >= 0; j--) {
                if (pathp[i] == pathq[j]) {
                    return new TreeNode(pathp[j]);
                }
            }
        }
        return nullptr;
    }

    TreeNode* lowestCommonAncestorv2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == q || root == p || root == nullptr) return root;
        TreeNode* left = lowestCommonAncestorv2(root->left, p, q);
        TreeNode* right = lowestCommonAncestorv2(root->right, p, q);
        if (left != nullptr && right != nullptr) return root;

        if (left == nullptr && right != nullptr)
            return right;
        else if (left != nullptr && right == nullptr)
            return left;
        else {
            return nullptr;
        }
    }
};

int main() {
    vector<int> treeNums = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    TreeNode* root = constructBinaryTree(treeNums);
    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(1);
    Solution solve;
    TreeNode* ret = solve.lowestCommonAncestor(root, p, q);
    cout << ret->val << endl;
}