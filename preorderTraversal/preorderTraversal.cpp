#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}  // 无参构造
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode *createTree() {
        TreeNode *root = NULL;
        TreeNode *node1 = new TreeNode(1);
        TreeNode *node2 = new TreeNode(2);
        TreeNode *node3 = new TreeNode(3);
        node1->right = node2;
        node2->left = node3;
        root = node1;
        return root;
    }

   public:
   // 递归遍历
    vector<int> result;
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) {
            return result;
        } else {
            result.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return result;
    }
};

int main() {
    Solution solve;
    TreeNode *root = solve.createTree();
    vector<int> result = solve.preorderTraversal(root);
    for (auto &res : result) {
        cout << res << endl;
    }
}