#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, vector<bool> &used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]){
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;

            backtracking(nums, used); // 不用索引求值了

            used[i] = false;
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);

        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution solve;
    vector<vector<int>> result;
    result = solve.permute(nums);
    for (auto& res : result) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << ",";
        }
        cout << endl;
    }
}