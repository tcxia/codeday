/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */

#include <iostream>
#include <list>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
   public:
    // Encodes a tree to a single string.
    void rserialize(TreeNode* root, string& str) {
        if (root == nullptr)
            str += "None";
        else {
            str += to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }
    string serialize(TreeNode* root) {
        string ret;
        rserialize(root, ret);
        return ret;
    }

    TreeNode* rdeserialize(list<string>& data) {
        if (data.front() == "None") {
            data.erase(data.begin());
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(data.front()));
        data.erase(data.begin());
        root->left = rdeserialize(data);
        root->right = rdeserialize(data);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> data;
        string str;
        for (auto& ch : data) {
            if (ch == ',') {
                data.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        if (!str.empty()) {
            data.push_back(str);
            str.clear();
        }
        return rdeserialize(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
