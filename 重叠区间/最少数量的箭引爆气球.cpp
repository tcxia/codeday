/**
 * @Author: Author
 * @Date: 2023-07-03 16:56:52
 * @Last Modified by: Author
 * @Last Modified time: 2023-07-03 16:56:52
 * @Description: 用最少数量的箭引爆气球
*/

/**
 * 时间复杂度: O(nlogn), n表示数组长度，nlogn是排序的时间，对所有气球排序的时间是n，但是小于前者，忽略
 * 空间复杂度: O(nlogn), 排序需要使用的栈空间
*/

class Solution{
    public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0]  // 按照左边界排序
    }

    int findMinArrowShots(vector<vector<int>>& points){

        sort(points.begin(), points.end(), cmp); // 底层默认是快排
        
        int result = 1;
        for (int i = 1; i < points.size(); ++i){
            if (points[i][0] > points[i - 1][1]){
                result++;
            }
            else{
                points[i][1] = min(points[i-1][1], points[i][1]);
            }
        }
        return result;
    }
};