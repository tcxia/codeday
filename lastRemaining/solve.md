## 解题思路

`f(n)` 表示从左到右剩下的数字结果
`f'(n)` 表示从右到左删除的结果

+ 对称性: `f(n) + f'(n) = n + 1`
+ 递归性: `f(n) = 2 * f'(n/2)`
+ 初始条件: `f(1) = f'(1) = 1`

根据以上条件可得: 
+ `f(2*n)/2 + f(n) = n + 1`
+ `f(n) / 2 + f(n /2) = n/2 + 1`
+ `f(n) = (n/2 + 1 - f(n/2)) * 2`


1. 从左到右删和从右到左删满足对称性，同样的输入`n`, 从左到右删完剩下的数和从右到左删完剩下的数满足`n/2`中心对称，所有`f(n) + f'(n) = n + 1`
2. 从左到右删完以后，剩下的数都是偶数，可以统一除2最后返回的数再乘2处理，因为该从右往左删了，所以`f(n)=2 * f'(n/2)`
