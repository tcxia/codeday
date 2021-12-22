#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int startIndex, vector<int>& path, vector<bool>& used) {
        if (path.size() <= nums.size()) {
            result.push_back(path);
        }

        for (int i = startIndex; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;

            backtracking(nums, i + 1, path, used);

            path.pop_back();
            used[i] = false;
        }
    }

   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        path.clear();

        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), false);

        backtracking(nums, 0, path, used);

        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 2};
    Solution solve;
    vector<vector<int>> result;
    result = solve.subsetsWithDup(nums);
    for (auto& res : result) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << ",";
        }
        cout << endl;
    }
}