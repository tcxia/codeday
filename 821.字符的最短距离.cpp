/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

// @lc code=start

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> answer;
        vector<int> cdis;
        for (int i = 0; i < s.size(); i++) {
            if (c == s[i]) cdis.push_back(i);
        }

        for (int j = 0; j < s.size(); j++) {
            if (s[j] == c)
                answer.push_back(0);
            else {
                int tmp = INT32_MAX;
                for (int d = 0; d < cdis.size(); d++) {
                    if (abs(cdis[d] - j) < tmp) {
                        tmp = abs(cdis[d] - j);
                    }
                }
                answer.push_back(tmp);
            }
        }
        return answer;
    }
};
// @lc code=end
