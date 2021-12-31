#include <iostream>
#include <queue>

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
   public:
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> que;
        int result = 0;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                if (i == 0) {
                    result = node->val;
                }
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
};

int main() {
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode* p4 = new TreeNode(4);
    TreeNode* p5 = new TreeNode(5);
    TreeNode* p6 = new TreeNode(6);
    TreeNode* p7 = new TreeNode(7);
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p3->left = p5;
    p3->right = p6;
    p5->left = p7;

    TreeNode *root = p1;

    Solution solve;
    int result = solve.findBottomLeftValue(root);
    cout << result << endl;
}