# 541. 反转字符串 II

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/reverse-string-ii/description/
- **难度**：Easy
- **标签**：双指针、字符串

## 题目描述

给定一个字符串 `s` 和一个整数 `k`，从字符串开头算起，每计数至 `2k` 个字符，就反转这 `2k` 字符中的前 `k` 个字符。

- 如果剩余字符少于 `k` 个，则将剩余字符全部反转。
- 如果剩余字符小于 `2k` 但大于或等于 `k` 个，则反转前 `k` 个字符，其余字符保持原样。

**示例 1：**
```
输入：s = "abcdefg", k = 2
输出："bacdfeg"
```

**示例 2：**
```
输入：s = "abcd", k = 2
输出："bacd"
```

**提示：**
- `1 <= s.length <= 10^4`
- `s` 仅由小写英文组成
- `1 <= k <= 10^4`

## 解题思路

这道题的关键是理解反转规则：每隔 `2k` 个字符，反转前 `k` 个字符。

**核心思路：**
1. 遍历字符串，步长为 `2k`
2. 每次迭代时，反转从当前位置开始的前 `k` 个字符（或剩余所有字符，如果不足 `k` 个）
3. 使用 `min(i+k, n)` 来处理边界情况，确保不会越界

**算法步骤：**
1. 将字符串转换为可变类型（因为需要原地修改）
2. 从索引 0 开始，每次移动 `2k` 个位置
3. 对于每个位置 `i`，反转 `[i, min(i+k, n))` 范围内的字符
4. 返回结果字符串

## 复杂度分析

- **时间复杂度**：O(n)，其中 n 是字符串 s 的长度。

- **空间复杂度**：O(1) 或 O(n)，取决于使用的语言中字符串类型的性质。如果字符串是可修改的，那么我们可以直接在原字符串上修改，空间复杂度为 O(1)，否则需要使用 O(n) 的空间将字符串临时转换为可以修改的数据结构（例如数组），空间复杂度为 O(n)。
  - C++：string 是可修改的，空间复杂度为 O(1)
  - Python：字符串不可变，需转换为列表，空间复杂度为 O(n)
  - Go：字符串不可变，需转换为字节数组，空间复杂度为 O(n)

## 代码实现

### C++

```22:31:leetcode/easy/541_反转字符串 II/541_反转字符串 II.cpp
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        for (int i = 0; i < n; i += 2*k) {
            reverse(s.begin() + i, s.begin() + min(i + k, n));
        }
        return s;
    }
};
```

### Python

```1:7:leetcode/easy/541_反转字符串 II/541_反转字符串 II.py
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        s = list(s)
        n = len(s)
        for i in range(0, n, 2*k):
            s[i:min(i+k, n)] = reversed(s[i:min(i+k, n)])
        return ''.join(s)
```

### Go

```1:17:leetcode/easy/541_反转字符串 II/541_反转字符串 II.go
func reverseStr(s string, k int) string {
	t := []byte(s)
	for i := 0; i < len(s); i += 2 * k {
		sub := t[i:min(i+k, len(s))]
		for j, n := 0, len(sub); j < n/2; j++ {
			sub[j], sub[n-1-j] = sub[n-1-j], sub[j]
		}
	}
	return string(t)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
```

## 关键点

- 理解题目的反转规则：每 `2k` 个字符为一组，反转前 `k` 个
- 使用 `min()` 函数处理边界情况，避免数组越界
- 字符串反转可以使用双指针技巧：左右指针交换元素
- Python 可以利用切片的 `reversed()` 函数简化代码
- C++ 可以直接使用 STL 的 `reverse()` 函数
- Go 需要将字符串转为字节数组，因为字符串是不可变的