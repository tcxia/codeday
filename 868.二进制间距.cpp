/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */

// @lc code=start

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    string convert(int num) {
        string s = "";
        int bin[32], length;
        for (length = 0; num > 0; length++){
            bin[length] = num % 2;
            num = num / 2;
        }
        for(int i = length - 1; i >= 0; i--){
            s += to_string(bin[i]);
        }
        
        return s;
    }

   public:
    int binaryGap(int n) {
        string sbin = convert(n);
        vector<int> distance;
        int result = 0;
        for (int i = 0; i < sbin.size(); i++) {
            if (sbin[i] == '1') {
                distance.push_back(i);
            }
        }
        for (int i = 1; i < distance.size(); i++) {
            int tmp = distance[i] - distance[i - 1];
            if (tmp > result) {
                result = tmp;
            }
        }
        return result;
    }
};
// @lc code=end

int main() {
    Solution solve;
    solve.binaryGap(22);
}