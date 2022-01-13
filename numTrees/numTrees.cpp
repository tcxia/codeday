#include <vector>
using namespace std;
class Solution {
   public:
    int numTrees(int n) {
        // dp[i]: 1到i为节点组成的二叉搜索树的个数dp[i]
        // dp[i] += dp[j-1] * dp[i-j], j-1 表示以j 为头节点的左子树的数量； i-j表示以j为头节点的右子树的数量
        // 初始化: dp[0] = 1
        // 遍历顺序: j依赖i，从前往后遍历
        // 举例说明（确定可以省略）
        // 结果返回: 最后需要返回n值的二茬搜索树数量
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[i - j] * dp[j - 1];
            }
        }
        return dp[n];
    }
};