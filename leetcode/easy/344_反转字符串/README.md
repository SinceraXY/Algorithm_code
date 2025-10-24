# 344. 反转字符串

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/reverse-string/description/
- **难度**：Easy
- **标签**：双指针、字符串

## 题目描述

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 `s` 的形式给出。

不要给另外的数组分配额外的空间，你必须**原地修改输入数组**、使用 O(1) 的额外空间解决这一问题。

**示例 1：**
```
输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]
```

**示例 2：**
```
输入：s = ["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
```

**提示：**
- `1 <= s.length <= 10^5`
- `s[i]` 都是 ASCII 码表中的可打印字符

## 解题思路

### 方法：双指针

这是一道经典的双指针问题，思路非常简单直接。

**基本思路：**
1. 使用两个指针 `i` 和 `j`，分别指向数组的开头和结尾
2. 交换 `s[i]` 和 `s[j]` 的值
3. `i` 向右移动，`j` 向左移动
4. 当 `i >= j` 时停止（即两个指针相遇或交错）

**关键点：**
- 只需要遍历到数组的一半即可（`i < s.size()/2`）
- 使用内置的 `swap` 函数或语言特性进行交换
- 原地修改，不使用额外数组

**图解过程：**
```
初始: ["h","e","l","l","o"]
       ↑           ↑
       i           j

步骤1: ["o","e","l","l","h"]  // 交换 h 和 o
           ↑       ↑
           i       j

步骤2: ["o","l","l","e","h"]  // 交换 e 和 l
               ↑
              i,j

结束: i >= j，停止
```

## 复杂度分析

- **时间复杂度**：O(n)，其中 n 是数组的长度
  - 只需要遍历数组的一半，进行 n/2 次交换操作

- **空间复杂度**：O(1)
  - 只使用了常数个额外变量（i、j），没有使用额外的数组空间
  - 符合题目要求的原地修改

## 代码实现

### C++
```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--)
        {
            swap(s[i],s[j]);
        }    
    }
};
```

### Python
```python
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        i, j = 0, len(s) - 1
        while i < len(s) // 2:
            s[i], s[j] = s[j], s[i]
            i += 1
            j -= 1
```

### Go
```go
func reverseString(s []byte) {
	for i, j := 0, len(s)-1; i < len(s)/2; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}
```

## 其他解法

### 方法二：库函数
某些语言提供了内置的反转函数：
- **Python**: `s.reverse()`
- **C++**: `reverse(s.begin(), s.end())`

但这些方法虽然简洁，却失去了练习双指针技巧的意义。

## 相关题目

- [541. 反转字符串 II](https://leetcode.cn/problems/reverse-string-ii/)
- [151. 反转字符串中的单词](https://leetcode.cn/problems/reverse-words-in-a-string/)
- [557. 反转字符串中的单词 III](https://leetcode.cn/problems/reverse-words-in-a-string-iii/)