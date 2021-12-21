#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        path.clear();
        backtracking(n, k, 1, 0);
        return result;
    }

    void backtracking(int targetSum, int k, int startIndex, int sum) {
        if (sum > targetSum){
            return;
        }
        if (path.size() == k) {
            if (sum == targetSum)
                result.push_back(path);
            return;
        }

        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) {
            path.push_back(i);
            sum += i; // 处理函数
            backtracking(targetSum, k, i + 1, sum);
            sum -= i;
            path.pop_back();
        }
    }
};