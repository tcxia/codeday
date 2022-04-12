/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        unordered_map<char, int> map;
        string saz = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0; i < widths.size(); i++) {
            map[saz[i]] = widths[i];
        }
        int lineCount = 0;
        int numCounts = 0;
        vector<int> result;

        for (int i = 0; i < s.size(); i++) {
            numCounts += map[s[i]];
            if (numCounts > 100 && numCounts - map[s[i]] < 100){
                lineCount++;
                numCounts = map[s[i]];
            }else if (numCounts == 100){
                lineCount++;
                numCounts = 0;
            }
            cout << numCounts << endl;
        }
        if (numCounts == 0){
            result.push_back(lineCount);
            result.push_back(numCounts + 100);
        }else{
            result.push_back(lineCount+1);
            result.push_back(numCounts);
        }
        

        return result;
    }
};
// @lc code=end


int main(){
    vector<int> widths = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    string s = "abcdefghijklmnopqrstuvwxyz";
    Solution solve;
    solve.numberOfLines(widths, s);
}