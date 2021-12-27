#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    int count = 0;

   public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            count++;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                if ((node->left == nullptr) && (node->right == nullptr)) {
                    return count;
                } else {
                    que.pop();
                    if (node->left) que.push(node->left);
                    if (node->right) que.push(node->right);
                }
            }
        }
        return count;
    }
};

int main() {
    TreeNode* p1 = new TreeNode(1);
    TreeNode* p2 = new TreeNode(2);
    TreeNode* p3 = new TreeNode(3);
    TreeNode* p4 = new TreeNode(4);
    TreeNode* p5 = new TreeNode(5);
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    TreeNode* root = p1;

    Solution solve;
    int count = solve.minDepth(root);
    cout << count << endl;
}