/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
   public:
    string removeDuplicates(string s) {
        stack<int> st;
        int slen = s.size();
        int point = 0;
        while (point < slen) {
            if (!st.empty() && st.top() == s[point]) {
                st.pop();
            } else {
                st.push(s[point]);
            }
            point++;
        }

        string str = "";
        while (!st.empty()) {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
// @lc code=end

int main() {
    string s = "azxxzy";
    Solution solve;
    string ret = solve.removeDuplicates(s);
    cout << ret << endl;
}
