#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& cand, int target, int startIndex, int sum, vector<bool>& used) {
        if (sum > target) {
            return;
        }

        if (sum == target) {
            result.push_back(path);
        }

        for (int i = startIndex; i < cand.size(); i++) {
            // used[i-1] == true表示同一树枝cand[i-1]使用过
            // used[i-1] == false表示同一树层cand[i-1]使用过

            // 对同一树层使用过的元素跳过
            if (i > 0 && cand[i] == cand[i - 1] && used[i - 1] == false) {
                continue;
            }
            sum += cand[i];

            used[i] = true;

            path.push_back(cand[i]);
            backtracking(cand, target, i + 1, sum, used);

            used[i] = false;
            sum -= cand[i];
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        result.clear();
        path.clear();

        sort(candidates.begin(), candidates.end());  // 得排序，让相同元素相邻
        backtracking(candidates, target, 0, 0, used);

        return result;
    }
};

int main() {
    vector<int> cand = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    Solution s;
    vector<vector<int>> result;
    result = s.combinationSum2(cand, target);
    for (auto& res : result) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}