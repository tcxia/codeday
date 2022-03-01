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
        vector<vector<string>> mat;

        int pos = 0;
        while(pos < s.size()){
            for(int i = 0; i < numRows; i++){
                mat[pos][i] = s[pos];
                pos++;
            }
            int flag = pos;
            for(int j = numRows - 1; j >= 0; j--){
                mat[pos--][j] = s[flag];
                flag++;
            }
        }
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                cout << mat[i][j] << endl;
            }
        }
    }
};
// @lc code=end

int main(){
    Solution solve;
    solve.convert("PAYPALISHIRING", 4);
}

