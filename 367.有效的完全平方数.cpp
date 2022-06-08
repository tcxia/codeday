/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start

#include <iostream>

using namespace std;
class Solution {
   public:
    bool isPerfectSquarev2(int num) {
        int low = 1, high = num;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            cout << mid << "," << high  << ","<< low<< endl;
            if ((long)mid * mid == num) {
                return true;
            } else if ((long)mid * mid > num) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }

    // 如果一个数是完全平方数，那么它的前n个连续奇数的和 = n^2
    bool isPerfectSquare(int num){
        int i = 1;
        while (num > 0){
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};
// @lc code=end

int main() {
    Solution solve;
    bool ret = solve.isPerfectSquare(5);
    cout << ret << endl;
}