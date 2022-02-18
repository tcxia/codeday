/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start

#include <vector>
using namespace std;

/**
 * 1  2 3 4
 * 12 13 14 5
 * 11 16 15 6
 * 10 9 8 7
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        int loop = n / 2; // 每个圈循环几次， 例如n为奇数3，那么loop=1 只循环一圈，矩阵中间的值需要单独处理
        int mid = n / 2; // 矩阵中间的位置，例如n=3, 中间位置为(1, 1)，n为5，中间位置为(2, 2)
        int count = 1; // 用来给矩阵每一个空格赋值
        int offset = 1; // 每一圈循环，需要控制每一条边遍历的长度
        int i, j;
        while(loop--){
            i = startx;
            j = starty;

            // 模拟填充上行从左到右（左闭右开）
            for(j = starty; j < starty + n - offset; j++){
                ret[startx][j] = count++;
            }

            // 模拟填充右列从上到下（左闭右开）
            for(i = startx; i < startx + n - offset; i++){
                ret[i][j] = count++;
            }

            // 模拟填充下行从右到左（左闭右开）
            for(; j > starty; j--){
                ret[i][j] = count++;
            }

            // 模拟填充左列从下到上（左闭右开）
            for(; i > startx; i--){
                ret[i][j] = count++;
            }

            // 第二圈开始，起始位置要各自加1，例如，第一圈起始位置是（0，0），第二圈起始位置是（1，1）
            startx++;
            starty++;

            // offset 控制每一圈里每一条边遍历的长度
            offset += 2;
        }

        // 如果n为奇数的化，需要单独给矩阵最中间的位置赋值
        if (n % 2){
            ret[mid][mid] = count;
        }
        return ret;
    }
};
// @lc code=end
