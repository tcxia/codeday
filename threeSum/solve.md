## 解决思路

### 暴力求解
三次循环，并且需要对结果去重，去重难度较大且不易实现

### 哈希解法
两层for循环就可以确定`a`和`b`的数值了，可以使用哈希法来确定`0-(a+b)`是否在数组里出现过，其实这个思路是正确的，但是我们有一个非常棘手的问题，就是题目中说的不可以包含重复的三元组。

把符合条件的三元组放进vector中，然后再去重，这样是非常费时的，很容易超时，也是这道题目通过率如此之低的根源所在。

去重的过程不好处理，有很多小细节，如果在面试中很难想到位。

时间复杂度可以做到$O(n^2)$，但还是比较费时的，因为不好做剪枝操作。

### 双向指针
1. 对数组进行排序sort
2. 一层for循环
3. 若排序后最小元素大于0，则直接返回无结果
4. 去重，必须后面元素开始，注意去重逻辑判断，不能写成`nums[i] == nums[i+1]`会漏掉`[-1, -1, 2]`的情况
5. 定义left和right,分别从i+1和元素最后位置开始
+  while条件为left < right
+  先判断三数之和
    + 若大于0，则表示right过大，right--
    + 若小于0，则表示left较小，left++
    + 若等于0，则添加到vector中，并且按照之前去重复方式进行去重
> tips
注意left和right去重代码的位置，若直接放在第5步之前，可能会漏掉`[0,0,0]`的情况