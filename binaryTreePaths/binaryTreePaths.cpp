#include <iostream>
#include <vector>
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
    vector<string> result;
   public:
    vector<string> binaryTreePaths(TreeNode *root) {
        queue<TreeNode*> que;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
            int size = que.size();
            string path;
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                path += to_string(node->val) + "->";
                if((node->left == nullptr) && (node->right == nullptr)){
                    result.push_back(path);
                }
            }
        }
    }
};