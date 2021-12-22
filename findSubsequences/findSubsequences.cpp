#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;

    bool isIncrease(vector<int>& v) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                if (v[j] < v[i]) {
                    return false;
                }
            }
        }
        return true;
    }

    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used) {
        if (startIndex > nums.size()) {
            return;
        }

        if (isIncrease(path) && path.size() > 1) {
            result.push_back(path);
        }

        for (int i = startIndex; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);

            path.pop_back();
            used[i] = false;
        }
    }

   public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        path.clear();

        vector<bool> used(nums.size(), false);
        backtracking(nums, 0, used);

        return result;
    }
};

int main() {
    vector<int> nums = {4, 4, 3, 2, 1};
    Solution solve;
    vector<vector<int>> result;
    result = solve.findSubsequences(nums);
    for (auto& res : result) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << ",";
        }
        cout << endl;
    }
}