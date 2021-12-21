#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        // sort(candidates.begin(), candidates.end());
        backtracking(target, candidates, 0, 0);
        return result;
    }

    void backtracking(int target, vector<int>& cand, int startIndex, int sum) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < cand.size(); i++) {
            sum += cand[i];
            path.push_back(cand[i]);
            backtracking(target, cand, i, sum);
            sum -= cand[i];
            path.pop_back();
        }
    }
};

int main() {
    vector<int> cand = {2,3,5};
    int target = 8;
    Solution s;
    vector<vector<int>> result;
    result = s.combinationSum(cand, target);
    for (auto& res : result) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}