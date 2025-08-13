# 27. 移除元素

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/remove-element/description/
- **难度**：Easy
- **标签**：数组、双指针

## 题目描述

给你一个数组 `nums` 和一个值 `val`，你需要**原地**移除所有数值等于 `val` 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并**原地**修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

### 示例

**示例 1:**
```
输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2]
解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。
```

**示例 2:**
```
输入：nums = [0,1,2,2,3,0,4,2], val = 2
输出：5, nums = [0,1,4,0,3]
解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 [0,1,4,0,3]。注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。
```

## 算法思路

**双指针法（快慢指针法）**

使用两个指针：
- **慢指针（slowIndex）**：指向下一个有效元素应该存放的位置
- **快指针（fastIndex）**：用于遍历整个数组

### 算法步骤：
1. 初始化慢指针 `slowIndex = 0`
2. 快指针 `fastIndex` 遍历整个数组
3. 当 `nums[fastIndex] != val` 时：
   - 将 `nums[fastIndex]` 复制到 `nums[slowIndex]`
   - `slowIndex` 自增1
4. 返回 `slowIndex`，即为新数组的长度

### 图解过程：
```
原数组: [3, 2, 2, 3], val = 3
       slow fast
         ↓   ↓
步骤1:   [3, 2, 2, 3]  nums[0]=3==val, fast++
           slow fast
             ↓   ↓
步骤2:   [3, 2, 2, 3]  nums[1]=2!=val, nums[0]=2, slow++, fast++
               slow fast
                 ↓   ↓  
步骤3:   [2, 2, 2, 3]  nums[2]=2!=val, nums[1]=2, slow++, fast++
                   slow fast
                     ↓   ↓
步骤4:   [2, 2, 2, 3]  nums[3]=3==val, fast++
                     
结果: [2, 2, _, _], 返回 slowIndex = 2
```

## 代码实现

### C++ 实现
```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for(int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if(nums[fastIndex] != val) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};
```

### Python 实现
```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        slowIndex = 0
        for fastIndex in range(len(nums)):
            if nums[fastIndex] != val:
                nums[slowIndex] = nums[fastIndex]
                slowIndex += 1
        return slowIndex
```

### Go 实现
```go
func removeElement(nums []int, val int) int {
    slowIndex := 0
    for fastIndex := 0; fastIndex < len(nums); fastIndex++ {
        if nums[fastIndex] != val {
            nums[slowIndex] = nums[fastIndex]
            slowIndex++
        }
    }
    return slowIndex
}
```

## 复杂度分析

- **时间复杂度**: O(n)，其中 n 是数组的长度。我们只需要遍历数组一次。
- **空间复杂度**: O(1)，只使用了常数级别的额外空间。

## 关键点

1. **原地修改**：不能使用额外的数组空间
2. **双指针技巧**：快指针遍历，慢指针记录有效位置
3. **顺序可变**：不需要保持原有元素的相对顺序
4. **返回长度**：返回的是新数组的长度，而不是数组本身