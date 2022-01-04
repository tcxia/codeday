#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

#include "../common/binaryTree.h"
using namespace std;
class Solution {
    void searchBST(TreeNode* cur, unordered_map<int, int>& mapTree) {
        if (cur == NULL) return;
        mapTree[cur->val]++;
        searchBST(cur->left, mapTree);
        searchBST(cur->right, mapTree);
        return;
    }

    bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> findModev2(TreeNode* root) {
        unordered_map<int, int> map;
        vector<int> ret;
        if (root == NULL) return ret;
        searchBST(root, map);
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp);
        ret.push_back(vec[0].first);
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].second == vec[0].second)
                ret.push_back(vec[i].first);
            else
                break;
        }
        return ret;
    }

   public:
    vector<int> ret;
    vector<int> findMode(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> result;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return ret;
    }
};

int main() {
    vector<int> tree = {5, 4, 6, 4, -1, 6, 6, 4, -1, -1, -1, -1, -1, 4};
    TreeNode* root = constructBinaryTree(tree);
    Solution solve;
    vector<int> ret = solve.findMode(root);
    // for (auto& r : ret) {
    //     cout << r << endl;
    // }
}