/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> window; // 利用哈希表
        int left = 0, right = 0;
        int result = 0;

        while (right < s.size()){
            char c = s[right++];
            // right++;
            window[c]++;

            while (window[c] > 1){
                char d = s[left++];
                // left++;
                window[d]--;
            }
            result = max(result, right - left);
        }
        return result;
    }
};
// @lc code=end

