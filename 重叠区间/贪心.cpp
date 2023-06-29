/**
 * @Author: Author
 * @Date: 2023-06-29 20:15:38
 * @Last Modified by: Author
 * @Last Modified time: 2023-06-29 20:15:38
 * @Description: 用贪心策略解决区间重叠问题
*/

/**
 * 时间复杂度: O(nlogn), 其中n是数组intervals长度
 * 空间复杂度: O(1)
*/


class Solution{
    public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        int result = 1;
        sort(intervals.begin(), intervals.end(), cmp); // 按照左边界排序
        for(int i = 1; i < intervals.size(); ++i){
            if (intervals[i][0] >= intervals[i - 1][1]) {
                result++;
            }else{
                intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
            }
        }
        return intervals.size() - result;
    }
};