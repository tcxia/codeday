#include <iostream>
#include <vector>
using namespace std;

/** 
 * dp[i] 表示到i-1层需要花费的cost
 * dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
 * 
 * 返回值 dp[cost.size()-1][cost.size()-2]
 * 
*/

class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < cost.size(); i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

int main() {
    vector<int> costs = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution solve;
    int ret = solve.minCostClimbingStairs(costs);
    cout << ret << endl;
}