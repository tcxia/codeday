#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxDepth(string s) {
        stack<char> st;
        vector<int> depth;
        int minDepth = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
                depth.push_back(st.size());
            }
            if (s[i] == ')') {
                st.pop();
            }
        }
        if (!st.empty()) {
            return 0;
        } else {
            for (int i = 0; i < depth.size(); i++) {
                // cout << depth[i] << endl;
                if (depth[i] >= minDepth) {
                    minDepth = depth[i];
                }
            }
            return minDepth;
        }
    }
};

int main() {
    string s = "1";
    Solution solve;
    int ret = solve.maxDepth(s);
    cout << ret << endl;
}