/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int lengthOfLIS(vector<int> &nums) {
        int piles = 0, n = nums.size();
        vector<int> top(n);
        for (int i = 0; i < n; i++) {
            // 要处理的扑克牌
            int poker = nums[i];
            int left = 0, right = piles;
            // 二分查找 插入位置
            while (left < right) {
                int mid = (left + right) / 2;
                if (top[mid] >= poker) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if (left == piles) piles++;
            // 把这张牌放入牌堆顶
            top[left] = poker;
        }
        // 牌堆数就是LIS长度
        return piles;
    }

   public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        // 按照第一列升序，按照第二列降序
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        });

        vector<int> sub_env;
        for (auto env : envelopes) {
            sub_env.push_back(env[1]);
        }

        return lengthOfLIS(sub_env);

        // if (sub_env.size() <= 1) return sub_env.size();
        // vector<int> dp(sub_env.size(), 1);
        // int result = 0;
        // for(int i = 1; i < sub_env.size(); i++){
        //     for(int j = 0; j < i; j++){
        //         if (sub_env[i] > sub_env[j]) dp[i] = max(dp[i], dp[j] + 1);
        //     }
        //     if (dp[i] > result){
        //         result = dp[i];
        //     }
        // }
        // return result;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> env = {
        {5, 2},
        {5, 4},
        {6, 4},
        {6, 7},
        {2, 3},
    };
    Solution solve;
    int ret = solve.maxEnvelopes(env);
    cout << ret << endl;
}