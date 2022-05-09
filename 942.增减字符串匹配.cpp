/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 */

// @lc code=start

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            path.push_back(nums[i]);
            used[i] = true;

            backtracking(nums, used);

            used[i] = false;
            path.pop_back();
        }
    }

   public:
    vector<int> diStringMatch(string s) {
        int n = s.size();

        vector<int> temp;
        for (int i = 0; i < n + 1; i++) {
            temp.push_back(i);
        }

        vector<bool> used(temp.size(), false);
        backtracking(temp, used);

        return temp;
    }
};
// @lc code=end

int main() {
    Solution solve;
    solve.diStringMatch("IDID");
}