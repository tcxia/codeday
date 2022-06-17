/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int n = arr.size();
        int i = 0;
        while (i < n)
        {
            if (arr[i] == 0)
            {
                cout << *(arr.begin()) << endl;
                arr.insert(arr.begin() + i, 0);
                i += 2;
            }else{
                i += 1;
            }
        }
        arr.resize(n);
    }
};
// @lc code=end

int main()
{
    vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
    Solution solve;
    solve.duplicateZeros(arr);
}