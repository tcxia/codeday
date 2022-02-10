/*
 * @lc app=leetcode.cn id=1447 lang=cpp
 *
 * [1447] 最简分数
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {

    // 求解最大公约数
    int measure(int i, int j) {
        while (i != j) {
            if (i > j) {
                i = i - j;
            } else {
                j = j - i;
            }
        }
        return i;
    }

   public:
    vector<string> result;

    vector<string> simplifiedFractions(int n) {
        if (n <= 1) return result;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                int max_measure = measure(i, j);  // 最大公约数
                string a = to_string(j / max_measure);  // 分子
                string b = to_string(i / max_measure);  // 分母
                string tmp = a + "/" + b;
                // cout << tmp << endl;
                if (find(result.begin(), result.end(), tmp) != result.end()) {
                    // result.push_back(tmp);
                    continue;
                } else {
                    result.push_back(tmp);
                }
                // if (!count(result.begin(), result.end(), tmp)){
                //     result.push_back(tmp);
                // }
            }
        }
        return result;
    }
};
// @lc code=end

int main() {
    Solution solve;
    vector<string> ret = solve.simplifiedFractions(4);
    for (auto& r : ret) {
        cout << r << endl;
    }
}
