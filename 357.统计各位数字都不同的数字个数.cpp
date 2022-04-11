/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 统计各位数字都不同的数字个数
 */

// @lc code=start
class Solution {
   public:
   /*
   当n=1时，满足条件的结果为10
   当n=2时，即查找满足1位数和2位数，一位数是10，满足聊天的两位数从1到9，结果为10 + 9 * 9
   当n=3时，即查找满足的1位数，2位数和3位数，即10 + 9 * 9 + 9 * 9 * 8
   */
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int sum = 10;
        int add = 9;
        for (int i = 1; i < n; i++) {
            sum += add * (10 - i);
            add *= (10 - i);
        }
        return sum;
    }
};
// @lc code=end
