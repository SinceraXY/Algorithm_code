# 35. 搜索插入位置 (Search Insert Position)

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/search-insert-position
- **难度**：Easy
- **标签**：数组、二分查找

## 题目描述

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 `O(log n)` 的算法。

**示例：**
```
输入: nums = [1,3,5,6], target = 5
输出: 2

输入: nums = [1,3,5,6], target = 2
输出: 1

输入: nums = [1,3,5,6], target = 7
输出: 4
```

## 算法思路

### 二分查找法

使用二分查找在排序数组中寻找目标值的插入位置：

1. **定义区间**：使用左闭右闭区间 `[left, right]`
2. **循环条件**：`left <= right`，当 `left == right` 时区间仍然有效
3. **中点计算**：`middle = left + ((right - left) >> 1)` 防止整数溢出
4. **三种情况**：
   - `nums[middle] > target`：目标在左半部分，`right = middle - 1`
   - `nums[middle] < target`：目标在右半部分，`left = middle + 1`
   - `nums[middle] == target`：找到目标，返回 `middle`

### 四种处理情况

1. **目标值在数组所有元素之前**：`[0, -1]` → 返回 0
2. **目标值等于数组中某一个元素**：直接返回 `middle`
3. **目标值插入数组中的位置**：`[left, right]` → 返回 `right + 1`
4. **目标值在数组所有元素之后**：`[left, right]` → 返回 `right + 1`

## 复杂度分析

- **时间复杂度**：O(log n) - 每次将搜索范围缩小一半
- **空间复杂度**：O(1) - 只使用常数额外空间

## 实现方案

### C++ 实现

```cpp
//二分法  
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;    // 定义target在左闭右闭的区间里，[left, right]
        
        while(left <= right) {    // 当left==right，区间[left, right]依然有效
            int middle = left + ((right - left) >> 1);   // 防止溢出 等同于(left + right)/2
            if(nums[middle] > target) {
                right = middle - 1;
            }
            else if(nums[middle] < target) {
                left = middle + 1;
            }
            else {
                return middle;
            }
        }
        return right + 1;
    }
};
```

### Python 实现

```python
#二分法
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n = len(nums)
        left = 0
        right = n - 1
        
        while left <= right:
            middle = left + ((right - left) >> 1)
            if nums[middle] > target:
                right = middle - 1
            elif nums[middle] < target:
                left = middle + 1
            else:
                return middle
        
        return right + 1
```

### Go 实现

```go
//二分法
func searchInsert(nums []int, target int) int {
    n := len(nums)
    left := 0
    right := n - 1
    
    for left <= right {
        middle := left + ((right - left) >> 1)
        if nums[middle] > target {
            right = middle - 1
        } else if nums[middle] < target {
            left = middle + 1
        } else {
            return middle
        }
    }
    
    return right + 1
}
```

## 关键实现细节

### 1. 中点计算
- **使用位运算**：`((right - left) >> 1)` 相当于 `(right - left) / 2`
- **防止溢出**：`left + ((right - left) >> 1)` 避免 `(left + right)` 可能的整数溢出

### 2. 区间定义
- **左闭右闭**：`[left, right]` 两端都包含
- **循环条件**：`left <= right` 确保区间有效性

### 3. 语言差异
- **C++**：使用 `vector<int>&` 引用传参，类方法定义
- **Python**：使用 `List[int]` 类型提示，类方法定义  
- **Go**：使用 `[]int` 切片，函数定义（非类方法）

### 4. 返回值说明
- **找到目标**：返回确切索引位置
- **未找到目标**：返回应该插入的位置（`right + 1`）

## 测试用例

| 输入数组 | 目标值 | 预期输出 | 说明 |
|---------|--------|----------|------|
| [1,3,5,6] | 5 | 2 | 找到目标值 |
| [1,3,5,6] | 2 | 1 | 插入位置 |
| [1,3,5,6] | 7 | 4 | 末尾插入 |
| [1,3,5,6] | 0 | 0 | 开头插入 |