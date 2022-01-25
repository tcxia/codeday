#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[i] 表示 队伍为i的配对次数
 * dp[i] = dp[i-1] + 1
 */
class Solution {
    bool func(int n) {
        if (n % 2 == 0) {
            return true;
        } else {
            return false;
        }
    }

   public:
    int numberOfMatches(int n) {
        int sum = 0;
        while (n != 1) {
            if (func(n)) {
                sum += (n / 2);
                n = n / 2;
            } else {
                sum += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
        }
        return sum;
    }
};

int main() {
    Solution solve;
    int ret = solve.numberOfMatches(7);
    cout << ret << endl;
}