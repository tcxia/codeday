## 解决思路


设函数 `check(i, j, k)` 表示判断以网格的`(i, j) `位置出发，能够搜索到单词` word[k..]`， 其中`word[k..]`表示字符串 `word`从第`k`个字符开始的后缀子串。如果能搜索到，则返回`true`, 否则返回`false`。函数` check(i, j, k)`的执行步骤如下：
+ 如果`board[i][j] != s[k]`，当前字符串不匹配，直接返回`false`
+ 如果当前已访问到字符串的末尾，且对应字符依然匹配，此时直接返回`true`
+ 否则，遍历当前位置的所有相邻位置，如果从某个相邻位置出发，能够搜索子串` word[k+1..]`，则返回`true`， 否则返回`false`

这样对每一个位置`(i, j)`都调用函数`check(i, j, 0)`进行检查，只要有一处返回`true`， 就说明网格中能够找到对应的单词，否则说明找不到

为了防止重复遍历相同的位置，需要额外维护一个与`board`等大的`visited`数组，用于标识每个位置是否被访问过，每次遍历相邻位置时，需要跳过已经被访问的位置