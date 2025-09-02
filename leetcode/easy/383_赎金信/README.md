# 383. 赎金信

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/ransom-note/description/
- **难度**：Easy
- **标签**：哈希表、字符串、计数

## 题目描述

给你两个字符串：`ransomNote` 和 `magazine` ，判断 `ransomNote` 能不能由 `magazine` 里面的字符构成。

如果可以，返回 `true` ；否则返回 `false` 。

`magazine` 中的每个字符只能在 `ransomNote` 中使用一次。

## 示例

**示例 1：**
```
输入：ransomNote = "a", magazine = "b"
输出：false
```

**示例 2：**
```
输入：ransomNote = "aa", magazine = "ab"
输出：false
```

**示例 3：**
```
输入：ransomNote = "aa", magazine = "aab"
输出：true
```

## 解题思路

### 方法一：暴力枚举法

**思路：**
1. 遍历 `magazine` 中的每个字符
2. 在 `ransomNote` 中寻找相同的字符
3. 找到后从 `ransomNote` 中删除该字符
4. 最后检查 `ransomNote` 是否为空

**缺点：** 时间复杂度较高 O(n²)

### 方法二：哈希表法（数组模拟）

**思路：**
1. 先判断长度，如果 `ransomNote` 长度大于 `magazine`，直接返回 `false`
2. 创建长度为 26 的数组记录 `magazine` 中各字符出现次数
3. 遍历 `ransomNote`，对应字符计数减一
4. 如果某个字符计数小于 0，说明 `magazine` 中该字符不够用

**优势：** 时间复杂度 O(n)，空间复杂度 O(1)

## 代码实现

### C++ - 暴力枚举法
```cpp
//暴力枚举
class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            for(int i=0;i<magazine.length();i++)
            {
                for(int j=0;j<ransomNote.length();j++)
                {
                    if(magazine[i]==ransomNote[j])    //在ransomNote中找到和magazine相同的字符
                    {
                        ransomNote.erase(ransomNote.begin()+j);    //ransomNote删除这个字符
                        break;
                    }
                }
            }
            if(ransomNote.length()==0)
            {
                return true;
            }
            return false;
        }
    };

// 时间复杂度: O(n^2)
// 空间复杂度：O(1)
```

### C++ - 哈希表法
```cpp
//哈希
class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            if(ransomNote.size()>magazine.size())
            {
                return false;
            }
            vector<int> record(26);
            for(int i=0;i<magazine.length();i++)   //通过record数据记录magazine里各个字符出现次数
            {
                record[magazine[i]-'a']++;
            }
            for(int j=0;j<ransomNote.length();j++)
            {
                record[ransomNote[j]-'a']--;
                if(record[ransomNote[j]-'a']<0)    //如果小于零说明ransomNote里出现的字符，magazine里没有
                {
                    return false;
                }
            }
            return true;
        }
    };

// 时间复杂度: O(n)
// 空间复杂度：O(1)
```

### Python
```python
from collections import Counter

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        return Counter(ransomNote) <= Counter(magazine)
```

### Go
```go
// 哈希
func canConstruct(ransomNote string, magazine string) bool {
    if len(ransomNote) > len(magazine) {
        return false
    }
    record := make([]int, 26)   //记录magazine里各个字符出现次数
    for _, char := range magazine {
        record[char-'a']++
    }
    for _, char := range ransomNote {
        record[char-'a']--
        if record[char-'a'] < 0 {    //如果小于零说明ransomNote里出现的字符，magazine里没有
            return false
        }
    }
    return true
}

// 时间复杂度: O(n)
// 空间复杂度：O(1)
```

## 复杂度分析

### 暴力枚举法：
- **时间复杂度：** O(n²)，其中 n 是字符串的长度。对于每个 `magazine` 中的字符，都要在 `ransomNote` 中查找
- **空间复杂度：** O(1)，只使用了常数的额外空间

### 哈希表法：
- **时间复杂度：** O(n)，其中 n 是两个字符串长度的最大值。需要遍历两个字符串各一次
- **空间复杂度：** O(1)，使用了长度为 26 的数组，属于常数空间

## 关键点

1. **字符频次统计**：通过数组或哈希表记录字符出现次数，实现快速查找
2. **边界条件优化**：提前判断长度关系，减少不必要的计算
3. **字符映射**：利用 `char - 'a'` 将字符映射到数组索引
4. **Python简洁实现**：使用 `Counter` 可以大大简化代码逻辑