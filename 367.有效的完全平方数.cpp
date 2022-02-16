/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 0, high = num;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if ((long)mid * mid == num){
                return true;
            }else if ((long)mid * mid > num){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end

