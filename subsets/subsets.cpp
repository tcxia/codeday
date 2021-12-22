#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int startIndex, vector<int>& path) {
        if (path.size() <= nums.size() && path.size() > 0) {
            result.push_back(path);  // 不用返回
        }

        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);

            backtracking(nums, i + 1, path);

            path.pop_back();
        }
    }

    void backtrackingv2(vector<int>& nums, int startIndex) {
        result.push_back(path);
        if (startIndex >= nums.size()) {
            return;
        }

        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrackingv2(nums, i + 1);
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        path.clear();

        backtracking(nums, 0, path);

        result.push_back({});  // 添加空集合
        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution solve;
    vector<vector<int>> result;
    result = solve.subsets(nums);
    for (auto& res : result) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}