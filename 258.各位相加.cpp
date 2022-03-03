/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start

#include <cstring>
#include <iostream>

using namespace std;

class Solution {
   public:
    int addDigits(int num) {
        if (num < 10){
            return num;
        }

        string numstr = to_string(num);
        // cout << numstr << endl;
        int result = 0;
        while (numstr.size() > 1) {
            int sum = 0;
            for (int i = 0; i < numstr.size(); i++) {
                sum += (numstr[i] - '0');
            }
            if (sum >= 10){
                numstr = to_string(sum);
            }else{
                result = sum;
                break;
            }
        }
        // cout << numstr << endl;
        return result;
    }
};
// @lc code=end

int main() {
    Solution solve;
    int ret = solve.addDigits(384);
    cout << ret << endl;
}