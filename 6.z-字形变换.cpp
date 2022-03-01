/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start


#include <iostream>
#include <vector>


using namespace std;

using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length(), r = numRows;
        if (r == 1 | r >= n){
            return s;
        }

        int t = r * 2 - 2;
        int c = (n + t - 1) / t * (r - 1);

        vector<string> mat(r, string(c, 0));
        for(int i = 0, x = 0, y = 0; i < n; ++i){
            mat[x][y] = s[i];
            if (i % t < r - 1){
                ++x;
            }else{
                --x;
                ++y;
            }
        }
        string ans;
        for(auto &row : mat){
            for(char ch : row){
                if (ch){
                    ans += ch;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution solve;
    solve.convert("PAYPALISHIRING", 4);
}

