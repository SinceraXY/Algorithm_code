# 5. 替换空格

- **平台**：剑指Offer
- **链接**：https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247484380&idx=1&sn=71d65b4c34c1c78d497115f109773343&scene=21#wechat_redirect
- **难度**：Easy
- **标签**：字符串、双指针

## 题目描述

请实现一个函数，把字符串 `s` 中的每个空格替换成 `"%20"`。

**示例 1：**
```
输入：s = "We are happy."
输出："We%20are%20happy."
```

**提示：**
- `0 <= s 的长度 <= 10000`

## 解题思路

这道题考察的是字符串的原地修改操作。关键在于**从后向前填充**，避免重复移动元素。

### 💡 核心思想

很多数组填充类的问题，都可以**先预先给数组扩容到填充后的大小，然后从后向前进行操作**。

**为什么要从后向前？**
- ✅ **从后向前**：每个元素只移动一次，时间复杂度 O(n)
- ❌ **从前向后**：每次插入都要移动后面的所有元素，时间复杂度 O(n²)

### 🔄 算法步骤

```
1️⃣ 统计空格数量 count
2️⃣ 扩容字符串：新长度 = 原长度 + count × 2
   （因为每个空格（1个字符）要替换成 "%20"（3个字符），增加2个字符）
3️⃣ 使用双指针从后向前遍历：
   - i 指向新字符串的末尾
   - j 指向原字符串的末尾
4️⃣ 遇到非空格字符：直接复制 s[j] → s[i]
5️⃣ 遇到空格字符：填充 "%20"，i 额外后退 2 位
```

### 📊 图解过程

```
原字符串: "We are happy."
空格数量: 2
扩容后:   "We are happy.      " (长度 + 2×2 = 原长度+4)

步骤1: j指向'.'  → 复制到i位置
步骤2: j指向'y'  → 复制到i位置
...
步骤N: j指向' '  → 填充'0', '2', '%'，i退3位
...
最终:   "We%20are%20happy."
```

## 复杂度分析

- **时间复杂度**：O(n)，其中 n 是字符串 s 的长度。需要遍历两次字符串：第一次统计空格，第二次替换操作。

- **空间复杂度**：
  - C++：O(1)，string 是可修改的，原地扩容
  - Python：O(n)，字符串不可变，需要创建列表
  - Go：O(n)，字符串不可变，需要创建字节数组

## 代码实现

### C++

```1:34:剑指offer/easy/5_替换空格/5_替换空格.cpp
class Solution {
public:
    string replaceSpace(string s)
    {
        int count = 0;     //统计空格的个数
        int OldSize = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                count++;
            }
        }
        //扩充字符串s的大小
        s.resize(s.size() + count * 2);
        int NewSize = s.size();
        //从后先前将空格替换为"%20"
        for (int i = NewSize - 1, j = OldSize - 1; j < i; i--, j--)
        {
            if (s[j] != ' ')
            {
                s[i] = s[j];
            } 
            else
            {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};
```

### Python

```1:31:剑指offer/easy/5_替换空格/5_替换空格.py
class Solution:
    def replaceSpace(self, s: str) -> str:
        count = 0       #统计空格的个数
        old_size = len(s)
        
        #统计空格数量
        for c in s:
            if c == ' ':
                count += 1
        
        #扩充列表大小
        res = list(s)
        res.extend([' '] * (count * 2))
        new_size = len(res)
        
        #从后向前将空格替换为"%20"
        i = new_size - 1
        j = old_size - 1
        
        while j < i:
            if s[j] != ' ':
                res[i] = s[j]
            else:
                res[i] = '0'
                res[i - 1] = '2'
                res[i - 2] = '%'
                i -= 2
            i -= 1
            j -= 1
        
        return ''.join(res)
```

### Go

```1:34:剑指offer/easy/5_替换空格/5_替换空格.go
func replaceSpace(s string) string {
	count := 0 //统计空格的个数
	oldSize := len(s)

	//统计空格数量
	for i := 0; i < len(s); i++ {
		if s[i] == ' ' {
			count++
		}
	}

	//扩充字符串的大小
	newSize := oldSize + count*2
	result := make([]byte, newSize)

	//从后向前将空格替换为"%20"
	i := newSize - 1
	j := oldSize - 1

	for j < i {
		if s[j] != ' ' {
			result[i] = s[j]
		} else {
			result[i] = '0'
			result[i-1] = '2'
			result[i-2] = '%'
			i -= 2
		}
		i--
		j--
	}

	return string(result)
}
```

## 关键点

### ⚡ 核心技巧

> **从后向前填充**：遇到对字符串或者数组做填充或删除的操作时，都要想想从后向前操作怎么样。

**优势对比**：

| 方向 | 时间复杂度 | 原因 |
|------|-----------|------|
| 从前向后 | O(n²) | 每次插入都需要移动后面所有元素 |
| 从后向前 | O(n) | 每个元素只移动一次，不需要重复移动 |

### 💡 通用模式

这种**先扩容再从后向前填充**的技巧适用于：
- ✅ 数组/字符串的插入操作
- ✅ 元素替换导致长度变化的问题
- ✅ 合并两个有序数组（从后向前合并）

### 🎯 实现要点

1. **双指针设置**：
   - `i` 指向新数组的末尾（写入位置）
   - `j` 指向原数组的末尾（读取位置）

2. **循环条件**：`j < i` 而不是 `j >= 0`
   - 当 `j == i` 时，前面的字符已经在正确位置，无需再移动

3. **空格处理**：
   - 填充 `"%20"` 后，`i` 需要额外后退 2 位
   - 因为一次循环 `i--` 后退 1 位，填充 3 个字符需要总共后退 3 位

4. **边界情况**：
   - 空字符串：直接返回
   - 无空格：直接返回原字符串
   - 全是空格：正常处理