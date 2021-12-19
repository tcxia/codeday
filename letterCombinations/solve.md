## 思路

### 暴力遍历
1. 将数字和字母对应，使用map作为类型存储
2. 遍历digits，将每个数字拆分，并且找到对应字母
3. 暴力组合对应字母，难点在于需要几个for循环，不好写

### 回溯法
回溯三部曲
+ 确定回溯函数参数
1. 首先需要一个字符串`s`来收集叶子节点的结果，然后用一个字符串数组result保存起来，这两个变量定义为全局变量
2. 再来看参数，参数题目指定给的`string digits`，然后还有一个参数就是`int`的`index`
这个`index`是记录遍历第几个数字了，就是用来遍历digits的，同时index也表示树的深度
```cpp
vector<string> result;
string s;
void backtracking(const string& digits, int index)
```

+ 确定终止条件
例如输入用例"23"，那么根节点往下递归两层就可以了，叶子节点就是要收集的结果集
那么终止条件就是如果index等于输入的数字个数(digits size)le 
然后收集结果，结束本层递归
```cpp
if (index == digits.size()){
    result.push_back(s)
    return;
}
```

+ 确定单层遍历逻辑
首先要取index指向的数字，并找到对应的字符集
然后for循环来处理这个字符集
```cpp
int digits = digits[index] - '0';
string letters = letterMap[digit];
for (int i = 0; i < letters.size(); i++){
    s.push_back(letters[i]);
    backtracking(digits, index + 1);
    s.pop_back();
}

```

>tips
输入`1*#`按键等异常情况，一定要处理好
