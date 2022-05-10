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
    vector<int> diStringMatchv1(string s) {
        int n = s.size();

        vector<int> temp;
        for (int i = 0; i < n + 1; i++) {
            temp.push_back(i);
        }

        vector<bool> used(temp.size(), false);
        backtracking(temp, used);

        for (int i = 0; i < result.size(); i++) {
            string tmp = "";
            for (int j = 1; j < result[i].size(); j++) {
                if (result[i][j] > result[i][j - 1]) {
                    tmp += "I";
                } else {
                    tmp += "D";
                }
            }
            if (tmp == s) {
                return result[i];
            }
        }
        return temp;
    }

    // 贪心策略
    vector<int> diStringMatch(string s) {
        int n = s.length(), lo = 0, hi = n;
        vector<int> perm(n + 1);
        for (int i = 0; i < n; i++) {
            perm[i] = s[i] == 'I' ? lo++ : hi--;
        }
        perm[n] = lo;
        return perm;
    }
};
// @lc code=end

int main() {
    Solution solve;
    vector<int> ret = solve.diStringMatch("IDID");
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }
}