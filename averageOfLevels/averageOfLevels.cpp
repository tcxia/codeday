#include <queue>
#include <vector>

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
    vector<double> result;

   public:
    vector<double> averageOfLevels(TreeNode *root) {
        queue<TreeNode *> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            int sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                sum += node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(sum / size);
        }
        return result;
    }
};