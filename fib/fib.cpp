#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    int fib(int n) {
        if (n <= 1)
            return n;
        else {
            return fib(n - 1) + fib(n - 2);
        }
    }

    int fibv2(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int fibv3(int n) {
        int dp[2]; // 只有两个元素
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

int main() {
    Solution solve;
    int ret = solve.fibv2(5);
    cout << ret << endl;
}