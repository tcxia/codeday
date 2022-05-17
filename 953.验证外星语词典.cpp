/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isAlienSortedv2(vector<string>& words, string order) {
        vector<bool> temp;
        int n = words.size();
        int first = 0, second = 1;
        while (second < n) {
            int flen = words[first].size();
            int slen = words[second].size();
            int pf = 0, ps = 0;
            while (pf < flen && ps < slen) {
                if (words[first][pf] != words[second][ps]) {
                    char fw = words[first][pf];
                    char sw = words[second][ps];
                    int f_ind = order.find(fw, 0);
                    int s_ind = order.find(sw, 0);
                    if (f_ind < s_ind)
                        temp.push_back(true);
                    else
                        return false;
                }
                pf++;
                ps++;
            }
            if (pf != flen && ps == slen) {
                return false;
            }

            first++;
            second++;
        }
        for (int i = 0; i < temp.size(); i++) {
            if (!temp[i]) return false;
        }
        return true;
    }

    bool isAlienSorted(vector<string>& words, string order){
        vector<int> index(26);
        for(int i = 0; i < order.size(); i++){
            index[order[i] - 'a'] = i;
        }

        for(int i = 1; i < words.size(); i++){
            bool valid = false;
            for(int j = 0; j < words[i-1].size() && j < words[i].size(); j++){
                int prev = index[words[i-1][j] - 'a'];
                int curr = index[words[i][j] - 'a'];
                if (prev < curr){
                    valid = true;
                    break;
                }
                else if(prev > curr){
                    return false;
                }
            }
            if (!valid){
                if (words[i-1].size() > words[i].size()){
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

int main() {
    vector<string> words = {"fxasxpc", "dfbdrifhp", "nwzgs"};
    string order = "zkgwaverfimqxbnctdplsjyohu";
    Solution solve;
    bool ret = solve.isAlienSorted(words, order);
    cout << ret << endl;
}