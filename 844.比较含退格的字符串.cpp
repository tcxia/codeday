/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    string endStr(string str) {
        int flag = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != '#') {
                str[flag] = str[i];
                flag++;
            } else {
                // flag = flag > 0 ? flag-- : 0;
                flag--;
                flag = flag < 0 ? 0 : flag;
            }
        }
        return str.substr(0, flag);
    }

   public:
    bool backspaceCompare(string s, string t) {
        string sr = endStr(s);
        string tr = endStr(t);
        if (sr == tr) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end

int main() {
    Solution solve;
    solve.backspaceCompare("a##c", "#a#c");
}