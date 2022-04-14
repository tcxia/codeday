/*
 * @lc app=leetcode.cn id=1672 lang=cpp
 *
 * [1672] 最富有客户的资产总量
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
   public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size();     // 行
        int n = accounts[0].size();  // 列
        int maxValue = 0;
        for (int i = 0; i < m; i++) {
            int one = 0;
            for (int j = 0; j < n; j++) {
                one += accounts[i][j];
            }
            if (one > maxValue) {
                maxValue = one;
            }
        }
        return maxValue;
    }
};
// @lc code=end
