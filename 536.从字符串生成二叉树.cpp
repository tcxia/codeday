
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x) : val(x), right(nullptr), left(nullptr) {}
};

class Solution {
   public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return nullptr;
        stack<TreeNode*> st;

        for (int i = 0; i < s.size(); i++) {
            int j = i;
            if (s[i] == ')')
                st.pop();
            else if ((s[i] >= '0' && s[i] <= '9')) {
                while (i + 1 < s.size() && s[i + 1] >= '0' && s[i + 1] <= '9') ++i;
                TreeNode* cur = new TreeNode(stoi(s.substr(j, i - j + 1)));
                if (!st.empty()) {
                    TreeNode* t = st.top();
                    if (!t->left)
                        t->left = cur;
                    else
                        t->right = cur;
                }
                st.push(cur);
            }
        }
        return st.top();
    }
};


int main() {
    Solution solve;
    string s = "4(2(3)(1))(6(5))";
    TreeNode* root = solve.str2tree(s);
    cout << root->val << endl;
}