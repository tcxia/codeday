/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int num = 1;
        result.push_back(1);

        for(int i = 1; i < n;i++){
            if (num * 10 <= n) num *= 10;
            else{
                while (num % 10 == 9 || num == n) num /= 10;
                num++;
            }
            result.push_back(num);
        }
        return result;
    }
};
// @lc code=end
