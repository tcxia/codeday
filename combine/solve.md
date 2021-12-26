##  思路

套用回溯法三部曲

+ 递归函数的返回值和参数
+ 回溯的终止条件
+ 单层遍历逻辑


### 剪枝操作

主要优化for循环，可以画树图然后优化
1. 已经选择的元素个数: path.size()
2. 还需要选择的元素个数: k - path.size()
3. 在集合n中至多要从该起始位置: n - (k - path.size()) + 1开始遍历
+ +1表示包括起始位置

举例来说，当n=4, k=4时，那么第一层for循环时候，从元素2开始的遍历都没有意义了，在第二层for循环，从元素3开始的遍历都没有意义了