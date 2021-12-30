#include <iostream>
#include <stack>
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
    void travesal(TreeNode *cur, vector<int> &path, vector<string> &result) {
        path.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr) {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }

        if (cur->left) {
            travesal(cur->left, path, result);
            path.pop_back();  // 回溯
        }

        if (cur->right) {
            travesal(cur->right, path, result);
            path.pop_back();  // 回溯
        }
    }

   public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> result;
        vector<int> path;
        if (root == nullptr) return result;
        travesal(root, path, result);
        return result;
    }

    vector<string> binaryTreePathsv2(TreeNode *root) {
        stack<TreeNode *> treeSt;
        stack<string> pathSt;
        vector<string> result;
        if (root == nullptr) return result;
        treeSt.push(root);
        pathSt.push(to_string(root->val));
        while (!treeSt.empty()) {
            TreeNode *node = treeSt.top();
            treeSt.pop();
            string path = pathSt.top();
            pathSt.pop();
            if (node->left == nullptr && node->right == nullptr) {
                result.push_back(path);
            }

            if (node->left) {
                treeSt.push(node->left);
                pathSt.push(path + "->" + to_string(node->left->val));
            }

            if (node->right) {
                treeSt.push(node->right);
                pathSt.push(path + "->" + to_string(node->right->val));
            }
        }
        return result;
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