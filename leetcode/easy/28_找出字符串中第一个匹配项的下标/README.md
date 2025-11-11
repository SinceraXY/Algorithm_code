# 28. 找出字符串中第一个匹配项的下标

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
- **难度**：Easy
- **标签**：双指针、字符串、字符串匹配

## 题目描述

给你两个字符串 `haystack` 和 `needle` ，请你在 `haystack` 字符串中找出 `needle` 字符串的第一个匹配项的下标（下标从 0 开始）。如果 `needle` 不是 `haystack` 的一部分，则返回 `-1` 。

**示例 1：**
```
输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。
```

**示例 2：**
```
输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
```

**提示：**
- `1 <= haystack.length, needle.length <= 10^4`
- `haystack` 和 `needle` 仅由小写英文字符组成

## 解题思路

本题使用 **KMP算法**（Knuth-Morris-Pratt算法）来实现高效的字符串匹配。

### KMP算法核心思想

1. **前缀表（next数组）**：记录模式串中每个位置之前的最长相等前后缀长度
2. **避免重复匹配**：当匹配失败时，利用前缀表跳过已经匹配过的字符，不需要回溯主串指针

### 算法步骤

1. **构建next数组**（`getNext`函数）：
   - 初始化 `j = -1`，`next[0] = -1`
   - 从位置1开始遍历needle字符串
   - 当前后缀不匹配时，通过 `j = next[j]` 回退
   - 找到匹配时，`j++` 并记录到next数组

2. **模式匹配**（`strStr`函数）：
   - 初始化 `j = -1`
   - 遍历haystack字符串
   - 不匹配时利用next数组调整j的位置
   - 匹配时j和i同时前进
   - 当 `j == needle.length - 1` 时找到完整匹配

### 复杂度分析

- **时间复杂度**：O(n + m)，其中n是haystack长度，m是needle长度
- **空间复杂度**：O(m)，需要存储next数组

## 代码实现

### C++
```cpp
class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); i++) {
            while(j >= 0 && s[i] != s[j+1]) {
                j = next[j];
            }
            if(s[i] == s[j+1]) {
                j++;
            }
            next[i] = j;
        }
    }
    
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int next[needle.size()];
        getNext(next, needle);
        int j = -1;
        for(int i = 0; i < haystack.size(); i++) {
            while(j >= 0 && haystack[i] != needle[j+1]) {
                j = next[j];
            }
            if(haystack[i] == needle[j+1]) {
                j++;
            }
            if(j == (needle.size() - 1)) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};
```

### Python
```python
class Solution:
    def getNext(self, next, s):
        j = -1
        next[0] = j
        for i in range(1, len(s)):
            while j >= 0 and s[i] != s[j + 1]:
                j = next[j]
            if s[i] == s[j + 1]:
                j += 1
            next[i] = j
    
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0:
            return 0
        next = [0] * len(needle)
        self.getNext(next, needle)
        j = -1
        for i in range(len(haystack)):
            while j >= 0 and haystack[i] != needle[j + 1]:
                j = next[j]
            if haystack[i] == needle[j + 1]:
                j += 1
            if j == len(needle) - 1:
                return i - len(needle) + 1
        return -1
```

### Go
```go
func getNext(next []int, s string) {
    j := -1
    next[0] = j
    for i := 1; i < len(s); i++ {
        for j >= 0 && s[i] != s[j+1] {
            j = next[j]
        }
        if s[i] == s[j+1] {
            j++
        }
        next[i] = j
    }
}

func strStr(haystack string, needle string) int {
    if len(needle) == 0 {
        return 0
    }
    next := make([]int, len(needle))
    getNext(next, needle)
    j := -1
    for i := 0; i < len(haystack); i++ {
        for j >= 0 && haystack[i] != needle[j+1] {
            j = next[j]
        }
        if haystack[i] == needle[j+1] {
            j++
        }
        if j == len(needle)-1 {
            return i - len(needle) + 1
        }
    }
    return -1
}
```

## 关键点

1. **next数组的意义**：存储的是最长相等前后缀的长度（从-1开始）
2. **为什么是j+1**：因为next数组存储的是前一个位置的信息，所以比较时用j+1
3. **while循环的作用**：不断回退寻找可以匹配的位置，体现了KMP的核心优化
4. **边界条件**：needle为空串时返回0