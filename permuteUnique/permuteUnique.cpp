#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, vector<bool>& used, vector<bool>& used_ord) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if ((i > 0 && nums[i] == nums[i-1] && !used_ord[i-1]) || used[i]){
                continue;
            }
            used[i] = true;
            used_ord[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used, used_ord);
            used[i] = false;
            used_ord[i] = false;
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        path.clear();

        vector<bool> used(nums.size(), false);
        vector<bool> used_ord(nums.size(), false);

        backtracking(nums, used, used_ord);

        return result;
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result;
    Solution s;
    result = s.permuteUnique(nums);
    for (auto& res : result) {
        for (int i = 0; i < res.size(); i++) {
            if(i == res.size() - 1){
                cout << res[i];
                continue;
            }
            cout << res[i] << ",";
        }
        cout << endl;
    }
}