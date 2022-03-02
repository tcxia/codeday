/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        unordered_map<char, int> need, window;
        for (char c : p) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        int start = 0;
        while (right < s.size()) {
            char c = s[right++];

            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            // if (valid == p.size()){
            //     result.push_back(left);
            // }

            
            while (right - left >= p.size()) {
                // int start = left;
                if (valid == need.size())
                    result.push_back(left);

                char d = s[left++];

                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }  
            }
        }
        return result;
    }
};
// @lc code=end
