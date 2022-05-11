/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 本质上是保存二叉搜索树的先序或者后序

class Codec {
   public:
    // Encodes a tree to a single string.
    // 中序遍历
    void inorderTree(TreeNode* root, vector<int>& path) {
        if (root) {
            inorderTree(root->left, path);
            path.push_back(root->val);
            inorderTree(root->right, path);
        }
    }

    string serialize(TreeNode* root) {
        vector<int> path;
        inorderTree(root, path);
        string ret = "";
        for (int i = 0; i < path.size(); i++) {
            ret += to_string(path[i]);
            ret += ",";
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.length();
        vector<int> ret;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (data[i] == ',') {
                int num = stoi(data.substr(flag, i));
                ret.push_back(num);
                flag = i + 1;
            }
        }
        return helper(ret, 0, ret.size() - 1);
    }

    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
};

void splitString(string data) {
    int n = data.length();
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] == ',') {
            int num = stoi(data.substr(flag, i));
            cout << num << endl;
            flag = i + 1;
        }
    }
}

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

int main(){
    splitString("1,12,34,56,78,");
}