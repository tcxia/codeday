#include <iostream>
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
    vector<string> result;

   public:
    vector<string> binaryTreePaths(TreeNode *root) {
        
    }
};

int main() {
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p5 = new TreeNode(5);
    p1->left = p2;
    p1->right = p3;
    p2->right = p5;
    TreeNode *root = p1;
    Solution solve;
    vector<string> result;
    result = solve.binaryTreePaths(root);
    for (auto &res : result) {
        cout << res << endl;
    }
}