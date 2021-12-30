
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool compare(TreeNode *tree1, TreeNode *tree2) {
        if (tree1 == nullptr && tree2 == nullptr)
            return true;
        else if (tree1 == nullptr && tree2 != nullptr)
            return false;
        else if (tree1 != nullptr && tree2 == nullptr)
            return false;
        else if (tree1->val != tree2->val)
            return false;

        bool compareLeft = compare(tree1->left, tree2->right);
        bool compareRight = compare(tree1->right, tree2->right);
        return compareLeft && compareRight;
    }

   public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        return compare(p, q);
    }
};
