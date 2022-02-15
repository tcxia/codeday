/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 */

// @lc code=start

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
   public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_map<int, int> map;
        vector<int> result;

        for (int i = 0; i < m; i++) {
            auto minValue = min_element(matrix[i].begin(), matrix[i].end());
            auto minIndex = distance(matrix[i].begin(), minValue);
            map[minIndex] = *minValue;
        }

        for (int j = 0; j < n; j++) {
            int count = 0;
            for (auto iter = map.begin(); iter != map.end(); iter++) {
                if (matrix[j][iter->first] < iter->second) {
                    count++;
                }
                if (count == m) {
                    result.push_back(iter->second);
                }
            }
        }

        return result;
    }
};
// @lc code=end
