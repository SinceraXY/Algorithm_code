# 202. 快乐数

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/happy-number/description/
- **难度**：Easy
- **标签**：哈希表、数学、双指针

## 题目描述

编写一个算法来判断一个数 `n` 是不是快乐数。

**快乐数** 定义为：
- 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和
- 然后重复这个过程直到这个数变为 1（此时这个人感到快乐），或是无限循环但始终变不到 1（此时这个人不快乐）
- 那些 **最终能变成 1 的数** 就是快乐数

如果 `n` 是快乐数就返回 `true`；不是，则返回 `false`。

### 示例

**示例 1：**
```
输入：n = 19
输出：true
解释：
1² + 9² = 82
8² + 2² = 68
6² + 8² = 100
1² + 0² + 0² = 1
```

**示例 2：**
```
输入：n = 2
输出：false
```

### 提示
- `1 <= n <= 2³¹ - 1`

## 解题思路

### 方法：哈希表检测循环

**核心思想：**
1. 如果一个数不是快乐数，那么在不断计算各位数字平方和的过程中，必然会进入一个循环
2. 使用哈希表记录已经出现过的数字，一旦发现重复就说明进入了循环
3. 如果过程中出现了 1，则说明是快乐数

**算法步骤：**
1. 创建一个哈希表来记录已经出现过的数字
2. 循环计算当前数字的各位平方和：
   - 如果结果为 1，返回 `true`
   - 如果结果已在哈希表中，返回 `false`（检测到循环）
   - 否则将结果加入哈希表，继续下一轮计算

**辅助函数：**
- `getSum(n)`：计算数字 n 的各位数字平方和

## 复杂度分析

- **时间复杂度**：O(log n)
  - 每次操作都会使数字的位数减少，最多操作 O(log n) 次
- **空间复杂度**：O(log n)
  - 哈希表最多存储 O(log n) 个不同的数字

## 代码实现

### Python 实现
```python
# 哈希表法
class Solution:
    def getSum(self, n: int) -> int:
        sum_val = 0
        while n:
            n, digit = divmod(n, 10)   #使用`divmod()`函数优雅地处理数字分解
            sum_val += digit ** 2
        return sum_val
    
    def isHappy(self, n: int) -> bool:
        seen = set()
        while n != 1 and n not in seen:
            seen.add(n)
            n = self.getSum(n)
        return n == 1
```

### C++ 实现
```cpp
//哈希表法
class Solution {
    public:
        int getSum(int n)
        {
            int sum=0;
            while(n)
            {
                sum+=(n%10)*(n%10);
                n/=10;
            }
            return sum;
        }
        bool isHappy(int n) {
            unordered_set<int>set;
            while(1)
            {
                int sum=getSum(n);
                if(sum==1)
                {
                    return true;
                }
                if(set.find(sum)!=set.end())
                {
                    return false;
                }
                else
                {
                    set.insert(sum);
                }
                n=sum;
            }        
        }
    };
```

### Go 实现
```go
// 哈希表法
func getSum(n int) int {
    sum := 0
    for n > 0 {
        sum += (n % 10) * (n % 10)
        n /= 10
    }
    return sum
}

func isHappy(n int) bool {
    m := map[int]bool{}   //利用 Go 的 map 和简洁的循环语法
    for ; n != 1 && !m[n]; n, m[n] = getSum(n), true { }
    return n == 1
}
```

## 关键知识点

1. **哈希表的应用**：检测循环是哈希表的经典应用场景
2. **数字操作**：熟练掌握取余和整除操作来分解数字
3. **循环检测**：在迭代过程中及时发现重复状态

## 注意事项

1. **边界情况处理**：输入为 1 时直接返回 `true`
2. **循环优化**：可以考虑使用快慢指针来检测循环，空间复杂度更优
3. **数字处理**：注意各位数字的正确提取和平方计算