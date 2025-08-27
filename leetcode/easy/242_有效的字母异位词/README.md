# 242. 有效的字母异位词

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/valid-anagram/description/
- **难度**：Easy
- **标签**：哈希表、字符串、排序

## 题目描述

给定两个字符串 `s` 和 `t`，编写一个函数来判断 `t` 是否是 `s` 的字母异位词。

**注意：** 若 `s` 和 `t` 中每个字符出现的次数都相同，则称 `s` 和 `t` 互为字母异位词。

**示例 1：**
```
输入: s = "anagram", t = "nagaram"
输出: true
```

**示例 2：**
```
输入: s = "rat", t = "car"
输出: false
```

**提示：**
- `1 <= s.length, t.length <= 5 * 10^4`
- `s` 和 `t` 仅包含小写字母

**进阶：** 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

## 解法思路

### 方法一：哈希表法（数组计数）

**核心思路：** 使用固定长度数组作为哈希表，统计两个字符串中每个字符的出现次数。

**算法步骤：**
1. 创建长度为26的数组，对应26个小写字母
2. 遍历字符串 `s`，将每个字符对应位置的计数+1
3. 遍历字符串 `t`，将每个字符对应位置的计数-1  
4. 检查数组中所有位置的计数是否都为0
   - 如果都为0，说明两字符串字符出现次数相同，是字母异位词
   - 如果有非0值，说明字符出现次数不同，不是字母异位词

**关键点：**
- 通过 `字符 - 'a'` 计算字符在数组中的索引位置
- 先增后减的操作，最终计数为0表示字符出现次数相同

### 方法二：排序法

将两个字符串分别排序后比较是否相等。如果是字母异位词，排序后的结果应该完全相同。

## 代码实现

### C++ 实现

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for(int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(record[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
```

### Python 实现

```python
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        record = [0] * 26
        for char in s:
            record[ord(char) - ord('a')] += 1
        for char in t:
            record[ord(char) - ord('a')] -= 1
        for count in record:
            if count != 0:
                return False
        return True
```

### Go 实现

```go
func isAnagram(s string, t string) bool {
    record := [26]int{}
    for _, char := range s {
        record[char-'a']++
    }
    for _, char := range t {
        record[char-'a']--
    }
    for i := 0; i < 26; i++ {
        if record[i] != 0 {
            return false
        }
    }
    return true
}
```

## 复杂度分析

### 哈希表法（数组计数）
- **时间复杂度**：O(n)，其中 n 是字符串的长度。需要遍历两个字符串各一次，以及遍历长度为26的数组。
- **空间复杂度**：O(1)，使用了固定长度为26的数组，空间复杂度为常数级别。

### 排序法
- **时间复杂度**：O(n log n)，主要时间消耗在排序上。
- **空间复杂度**：O(log n)，排序算法的额外空间开销。

## 其他解法

### 使用HashMap
```python
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        char_count = {}
        for char in s:
            char_count[char] = char_count.get(char, 0) + 1
        
        for char in t:
            if char not in char_count:
                return False
            char_count[char] -= 1
            if char_count[char] == 0:
                del char_count[char]
        
        return len(char_count) == 0
```

### 使用Counter（Python）
```python
from collections import Counter

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)
```

## 关键点总结

1. **数组计数法**是最优解，时间和空间复杂度都很理想
2. **字符映射**：通过 `字符 - 'a'` 将字符转换为数组索引
3. **计数策略**：先对第一个字符串计数+1，再对第二个字符串计数-1
4. **边界情况**：长度不同的字符串肯定不是字母异位词
5. **扩展思考**：对于Unicode字符，可以使用HashMap代替固定数组