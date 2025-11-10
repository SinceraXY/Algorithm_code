# 58-II.左旋转字符串

- **平台**：剑指Offer
- **链接**：https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247484405&idx=1&sn=5b30d31cc55eb9123b58a86b0b6736ca&scene=21#wechat_redirect
- **难度**：Medium
- **标签**：字符串、双指针

## 题目描述

字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

**示例 1：**
```
输入: s = "abcdefg", k = 2
输出: "cdefgab"
```

**示例 2：**
```
输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"
```

**限制：**
- `1 <= k < s.length <= 10000`

## 解题思路

### 方法：局部反转 + 整体反转

**进阶要求：** 不能申请额外空间，只能在本串上操作。

如果直接模拟左旋转操作（将前 n 个字符依次移到末尾），需要多次移动或使用额外空间。但通过**"局部反转 + 整体反转"**可以巧妙地实现原地左旋转，这是一个意想不到的解法！

**核心思想：**

将字符串分为两部分：前 n 个字符（需要移到后面的部分）和剩余字符（需要移到前面的部分）。通过三次反转操作，可以在不使用额外空间的情况下完成位置交换。

**算法流程：**
1. **局部反转**：反转前 n 个字符
2. **局部反转**：反转剩余字符  
3. **整体反转**：反转整个字符串

**为什么这样做有效？**

以 `s = "abcdefg", n = 2` 为例（目标：`"cdefgab"`）：

```
原始字符串：  a b | c d e f g
           [前n个] [剩余部分]

步骤1 - 反转前n个：  b a | c d e f g

步骤2 - 反转剩余：    b a | g f e d c

步骤3 - 整体反转：    c d e f g | a b  ✓
```

**本质原理：**
- 两个局部反转后，整个字符串变成了"反向的两部分"
- 再进行整体反转，相当于交换了两部分的位置，且每部分内部顺序恢复正常
- 数学表示：`reverse(reverse(A) + reverse(B)) = B + A`

**复杂度分析：**
- **时间复杂度**：O(N)，其中 N 为字符串长度，需要遍历字符串三次
- **空间复杂度**：O(1)（原地操作，不考虑语言本身特性如 Python/Go 字符串不可变）

## 代码实现

### C++
```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
```

### Python
```python
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        s_list = list(s)
        # 翻转前n个字符
        s_list[:n] = reversed(s_list[:n])
        # 翻转剩余字符
        s_list[n:] = reversed(s_list[n:])
        # 翻转整个字符串
        s_list.reverse()
        return ''.join(s_list)
```

### Go
```go
func reverseLeftWords(s string, n int) string {
	runes := []rune(s)
	// 翻转前n个字符
	reverse(runes[:n])
	// 翻转剩余字符
	reverse(runes[n:])
	// 翻转整个字符串
	reverse(runes)
	return string(runes)
}

func reverse(arr []rune) {
	left, right := 0, len(arr)-1
	for left < right {
		arr[left], arr[right] = arr[right], arr[left]
		left++
		right--
	}
}
```