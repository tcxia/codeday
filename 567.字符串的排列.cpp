/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for(char c: s1) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size()){
            char a = s2[right++];
            if (need.count(a)){
                window[a]++;
                if (window[a] == need[a]){
                    valid++;
                }
            }

            while (right - left >= s1.size()){
                if (valid == need.size()){
                    return true;
                }
                
                char b = s2[left++];
                if (need.count(b)){
                    if (need[b] == window[b]){
                        valid--;
                    }
                    window[b]--;
                }
            }
        }
        return false;
    }
};
// @lc code=end

