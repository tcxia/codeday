#include <iostream>
#include <vector>
using namespace std;
/**
 * dp[i] 表示和为i的最少硬币个数
 * dp[i] = min(dp[i], dp[i-coins] + 1);
 *
 * dp[0] = 0;
 *
 * 返回数据 dp[amount] > amount ? -1 : dp[amount]
 */
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int init = amount + 1;
        vector<int> dp(amount + 1, init);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] < 0) continue;
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    Solution solve;
    int ret = solve.coinChange(coins, 11);
    cout << ret << endl;
}