# 459. 重复的子字符串

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/repeated-substring-pattern/description/
- **难度**：Easy
- **标签**：字符串、字符串匹配

## 题目描述

给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母。

**示例 1:**
```
输入: "abab"
输出: True
解释: 可由子字符串 "ab" 重复两次构成。
```

**示例 2:**
```
输入: "aba"
输出: False
```

**示例 3:**
```
输入: "abcabcabcabc"
输出: True
解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
```

## 解题思路

### 方法一：KMP算法 + Next数组

如果一个字符串是由重复的子字符串组成，那么这个字符串一定有一个周期性的结构。利用KMP算法的Next数组可以找到字符串中的最长公共前后缀。

**核心思路：**
1. 如果字符串s是由重复子串构成，那么`s[0...k]`和`s[len-k-1...len-1]`应该是相等的
2. 通过Next数组，`next[len-1]`表示整个字符串的最长公共前后缀长度
3. 如果`next[len-1] != -1`且`len % (len - (next[len-1] + 1)) == 0`，说明存在重复子串

**时间复杂度：** O(n)  
**空间复杂度：** O(n)

### 方法二：字符串匹配

**核心思路：**
如果字符串s是由重复子串构成的，那么将两个s拼接起来得到`s+s`，在这个新字符串中从位置1开始查找s，如果能找到且位置不是s.length()，说明s是由重复子串构成的。

**时间复杂度：** O(n)  
**空间复杂度：** O(n)

## 代码实现

### C++实现

**方法一：KMP算法**
```cpp
class Solution {
public:
    void getNext(int*next,const string& s) {
        next[0]=-1;
        int j=-1;
        for(int i=1;i<s.size();i++) {
            while(j>=0&&s[i]!=s[j+1]) {
                j=next[j];
            }
            if(s[i]==s[j+1]) {
                j++;
            }
            next[i]=j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if(s.size()==0) {
            return false;
        }
        int next[s.size()];
        getNext(next,s);
        int len=s.size();
        if(next[len-1]!=-1&&len%(len-(next[len-1]+1))==0) {
            return true;
        }
        return false;
    }
};
```

**方法二：字符串匹配**
```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};
```

### Python实现

```python
class Solution:
    def getNext(self, s: str) -> list:
        n = len(s)
        next_arr = [-1] * n
        j = -1
        for i in range(1, n):
            while j >= 0 and s[i] != s[j + 1]:
                j = next_arr[j]
            if s[i] == s[j + 1]:
                j += 1
            next_arr[i] = j
        return next_arr
    
    def repeatedSubstringPattern(self, s: str) -> bool:
        if len(s) == 0:
            return False
        next_arr = self.getNext(s)
        length = len(s)
        if next_arr[-1] != -1 and length % (length - (next_arr[-1] + 1)) == 0:
            return True
        return False
```

### Go实现

```go
func getNext(s string) []int {
    n := len(s)
    next := make([]int, n)
    for i := 0; i < n; i++ {
        next[i] = -1
    }
    j := -1
    for i := 1; i < n; i++ {
        for j >= 0 && s[i] != s[j+1] {
            j = next[j]
        }
        if s[i] == s[j+1] {
            j++
        }
        next[i] = j
    }
    return next
}

func repeatedSubstringPattern(s string) bool {
    if len(s) == 0 {
        return false
    }
    next := getNext(s)
    length := len(s)
    if next[length-1] != -1 && length%(length-(next[length-1]+1)) == 0 {
        return true
    }
    return false
}
```

## 总结

- **KMP方法**：利用字符串匹配算法的思想，通过Next数组找到最长公共前后缀，判断是否存在重复模式
- **字符串拼接方法**：简洁但需要额外空间，利用重复字符串的性质进行判断
- 两种方法时间复杂度都是O(n)，KMP方法更能体现算法思想，字符串拼接方法更简洁