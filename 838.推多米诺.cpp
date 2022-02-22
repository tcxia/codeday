/*
 * @lc app=leetcode.cn id=838 lang=cpp
 *
 * [838] 推多米诺
 */

// @lc code=start
#include <iostream>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        for(int i = 0; i < dominoes.size(); i++){
            char tmp = dominoes[i];
            
        }
        return dominoes;
    }
};
// @lc code=end

int main(){
    string str = ".L.R...LR..L..";
    Solution solve;
    string ret = solve.pushDominoes(str);
    cout << ret << endl;
}
