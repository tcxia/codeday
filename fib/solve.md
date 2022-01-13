## 解题思路

动规五部曲：
1. 确定dp数组以及下标的含义
+ `dp[i]`表示为第`i`个数的斐波那契数值是`dp[i]`
2. 确定递推公式(状态转移方程)
+ `dp[i] = dp[i-1] + dp[i-2]`
3. dp数组如何初始化
+ 题目也给出,`dp[0] = 0`和`dp[1] = 1`
4. 确定遍历顺序
+ 从递推公式`dp[i] = dp[i-1] + dp[i-2]`可以看出，`dp[i]`是依赖`dp[i-1]`和`dp[i-2]`，那么遍历顺序一定是从前到后遍历的
5. 举例推导dp数组
+ 举例，当N=10时，`dp`数组应该是: `0 1 1 2 3 5 8 13 21 34 55`