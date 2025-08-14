# 209. 长度最小的子数组

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/minimum-size-subarray-sum/description/
- **难度**：Medium
- **标签**：数组、二分查找、前缀和、滑动窗口

## 题目描述

给定一个含有 `n` 个正整数的数组和一个正整数 `target`。

找出该数组中满足其和 ≥ `target` 的长度最小的**连续子数组** `[numsl, numsl+1, ..., numsr-1, numsr]`，并返回其长度。如果不存在符合条件的子数组，返回 `0`。

### 示例

**示例 1:**
```
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是满足条件的长度最小的子数组。
```

**示例 2:**
```
输入：target = 4, nums = [1,4,4]
输出：1
```

**示例 3:**
```
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
```

## 算法思路

### 方法一：暴力解法 (Time Limit Exceeded)

**思路**：使用两层循环，外层固定起始位置，内层找到第一个满足条件的结束位置。

**时间复杂度**：O(n²)  
**空间复杂度**：O(1)

虽然逻辑正确，但在大数据量下会超时。

### 方法二：滑动窗口（推荐）

**核心思想**：使用双指针维护一个滑动窗口，动态调整窗口大小。

**算法步骤**：
1. 使用 `left` 和 `right` 两个指针维护窗口边界
2. `right` 指针不断右移扩大窗口，累加元素到 `sum`
3. 当 `sum ≥ target` 时：
   - 记录当前窗口长度，更新最小值
   - `left` 指针右移缩小窗口，直到 `sum < target`
4. 重复步骤2-3，直到 `right` 遍历完整个数组

### 图解过程：
```
数组: [2, 3, 1, 2, 4, 3], target = 7

初始: left=0, right=0, sum=0, result=∞
      [2, 3, 1, 2, 4, 3]
       ↑
    left,right

步骤1: sum=2 < 7, right++
      [2, 3, 1, 2, 4, 3]
       ↑  ↑
     left right

步骤2: sum=5 < 7, right++
      [2, 3, 1, 2, 4, 3]
       ↑     ↑
     left   right

步骤3: sum=6 < 7, right++
      [2, 3, 1, 2, 4, 3]
       ↑        ↑
     left      right

步骤4: sum=8 ≥ 7, 长度=4, result=4, 缩小窗口
      [2, 3, 1, 2, 4, 3]
          ↑     ↑
        left   right

...继续直到找到最小长度为2
```

## 代码实现

### C++ 实现（暴力解法）
```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0;
        int length = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum = 0;
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if(sum >= target) {
                    length = j - i + 1;
                    result = min(result, length);
                    break;
                }
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};
```

### C++ 实现（滑动窗口）
```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0;
        int length = 0;
        int i = 0;  // 左指针
        
        for(int j = 0; j < nums.size(); j++) {  // 右指针
            sum += nums[j];
            
            while(sum >= target) {
                length = j - i + 1;
                result = min(result, length);
                sum -= nums[i++];  // 缩小窗口
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};
```

### Python 实现
```python
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        result = float('inf')
        sum_val = 0
        length = 0
        i = 0  # 左指针
        
        for j in range(len(nums)):  # 右指针
            sum_val += nums[j]
            
            while sum_val >= target:
                length = j - i + 1
                result = min(result, length)
                sum_val -= nums[i]
                i += 1  # 缩小窗口
                
        return 0 if result == float('inf') else result
```

### Go 实现
```go
func minSubArrayLen(target int, nums []int) int {
    result := int(^uint(0) >> 1)  // INT_MAX
    sum := 0
    length := 0
    i := 0  // 左指针
    
    for j := 0; j < len(nums); j++ {  // 右指针
        sum += nums[j]
        
        for sum >= target {
            length = j - i + 1
            if length < result {
                result = length
            }
            sum -= nums[i]
            i++  // 缩小窗口
        }
    }
    
    if result == int(^uint(0) >> 1) {
        return 0
    }
    return result
}
```

## 复杂度分析

### 滑动窗口解法
- **时间复杂度**: O(n)，每个元素最多被访问两次（一次被右指针访问，一次被左指针访问）
- **空间复杂度**: O(1)，只使用了常数级别的额外空间

### 暴力解法
- **时间复杂度**: O(n²)，两层嵌套循环
- **空间复杂度**: O(1)，只使用了常数级别的额外空间

## 关键点

1. **滑动窗口精髓**：用双指针维护一个动态窗口，避免重复计算
2. **窗口扩展**：右指针负责扩大窗口，寻找可能的解
3. **窗口收缩**：当找到满足条件的窗口时，左指针负责收缩窗口，寻找最优解
4. **边界处理**：注意数组越界和无解情况的处理
5. **最值更新**：每次找到合法窗口时都要更新最小长度