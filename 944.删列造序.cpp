/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();     // 数量
        int n = strs[0].size();  // 每个子字符的长度

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (strs[j][i] < strs[j - 1][i]) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};

// @lc code=end

int main() {
    vector<string> strs = {"zyx","wvu","tsr"};
    Solution solve;
    int ret = solve.minDeletionSize(strs);
    cout << ret << endl;
}