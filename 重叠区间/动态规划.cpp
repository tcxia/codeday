/**
 * @Author: Author
 * @Date: 2023-06-30 10:07:33
 * @Last Modified by: Author
 * @Last Modified time: 2023-06-30 10:07:33
 * @Description: 动态规划解决无重叠区间问题
*/

/**
 * 时间复杂度: O(n^2), n是区间的数量
 * 空间复杂度: O(n), 存储所有状态f的空间
*/


class Solution{
    public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        if (intervals.empty()){
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v){
            return u[0] < v[0];
        });

        int n = intervals.size();
        vector<int> f(n, 1);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < i; ++j){
                if (intervals[j][1] <= intervals[i][0]){
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return n - *max_element(f.begin(), f.end());
    }
};