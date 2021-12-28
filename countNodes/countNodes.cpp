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
    int countNodes(TreeNode* root) {
        if(!root){
            return count;
        }
        count += 1;
        countNodes(root->left);
        countNodes(root->right);
        return count;
    }
};

int main() {
    TreeNode* p1 = new TreeNode(1);
    // TreeNode* p2 = new TreeNode(2);
    // TreeNode* p3 = new TreeNode(3);
    // TreeNode* p4 = new TreeNode(4);
    // TreeNode* p5 = new TreeNode(5);
    // TreeNode* p6 = new TreeNode(6);
    // p1->left = p2;
    // p1->right = p3;
    // p2->left = p4;
    // p2->right = p5;
    // p3->left = p6;
    TreeNode* root = p1;

    Solution solve;
    int count = solve.countNodes(root);
    cout << count << endl;
}