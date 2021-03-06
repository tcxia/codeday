## 思路

### 解决难点
1. 一个行程中，如果航班处理不好容易变成一个圈，成为死循环
2. 有多种解法，字母序靠前排在前面，需要记录映射关系
3. 使用回溯（深度搜索）的话，终止条件是什么
4. 搜索过程中，如何遍历一个机场所对应的所有机场


### 回溯法解决思路
+ 递归函数参数
1. 使用`unorder_map<string, map<string, int>>`来记录航班的映射关系，定义为全局变量
2. 还需要`ticketNum`,表示有多少个航班（终止条件会用）
3. 回溯还需要返回值（之前都是`void`），因为只需要一个行程，就是唯一通向叶子节点的路线，找到叶子节点直接返回


+ 递归终止条件
1. 按照示例1的提示，有4个航班，那么只要找出一种行程，行程里的机场个数是5就可以了，所以终止条件，就是在回溯过程中，遇到的机场个数，达到了（航班数量+1）就找到了一个行程，把所有航班串在一起

+ 单层搜索逻辑
1. 选择映射函数时，不能选择`unorder_map<string, multiset<string>>`,因为一旦有元素增删`multiset`迭代器就会失效
2. 所有要找到一个对数据进行排序的容器，而且还要容易增删元素，迭代器还不能失效
3. 使用`unorder_map<string, map<string, int>>`中`int`用来判断集合里的机场是否使用过，这样避免了直接去删元素