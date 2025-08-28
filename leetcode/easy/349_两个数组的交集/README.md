# 349. 两个数组的交集

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/intersection-of-two-arrays/description/
- **难度**：Easy
- **标签**：数组、哈希表、双指针、二分查找、排序

## 题目描述

给定两个数组 `nums1` 和 `nums2`，返回它们的交集。输出结果中的每个元素一定是**唯一的**。我们可以**不考虑输出结果的顺序**。

**示例 1：**
```
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
```

**示例 2：**
```
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4] 或 [4,9]
```

**提示：**
- `1 <= nums1.length, nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 1000`

## 解法思路

### 方法一：哈希集合法（推荐）

**核心思路：** 使用哈希集合进行快速查找，避免嵌套循环。

**算法步骤：**
1. 将数组 `nums1` 转换为哈希集合，实现O(1)查找
2. 创建结果集合，用于存储交集元素并自动去重
3. 遍历数组 `nums2`，检查每个元素是否在 `nums1` 的集合中
4. 如果存在，将该元素加入结果集合
5. 将结果集合转换为数组返回

**关键优势：**
- 时间复杂度优化：从O(n×m)降低到O(n+m)
- 自动去重：集合特性保证结果唯一性
- 空间换时间：用额外空间换取查找效率

### 方法二：双指针法

先对两个数组排序，然后使用双指针遍历找交集。

### 方法三：二分查找法

对较小的数组中的每个元素，在较大数组中进行二分查找。

## 代码实现

### C++ 实现

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for(int num : nums2) {
            if(nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
```

### Python 实现

```python
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result_set = set()
        nums_set = set(nums1)
        for num in nums2:
            if num in nums_set:
                result_set.add(num)
        return list(result_set)
```

### Go 实现

```go
func intersection(nums1 []int, nums2 []int) []int {
    resultSet := make(map[int]bool)
    numsSet := make(map[int]bool)
    
    // 将nums1放入哈希集合
    for _, num := range nums1 {
        numsSet[num] = true
    }
    
    // 遍历nums2，查找交集
    for _, num := range nums2 {
        if numsSet[num] {
            resultSet[num] = true
        }
    }
    
    // 转换为切片返回
    result := make([]int, 0, len(resultSet))
    for num := range resultSet {
        result = append(result, num)
    }
    return result
}
```

## 复杂度分析

### 哈希集合法
- **时间复杂度**：O(n + m)，其中 n 和 m 分别是两个数组的长度。需要遍历两个数组各一次。
- **空间复杂度**：O(n + m)，需要哈希集合存储两个数组的元素。

### 双指针法（排序后）
- **时间复杂度**：O(n log n + m log m)，主要开销在排序上。
- **空间复杂度**：O(log n + log m)，排序算法的额外空间开销。

### 二分查找法
- **时间复杂度**：O(n log m)，对较小数组的每个元素在较大数组中二分查找。
- **空间复杂度**：O(1)，只需要常数级别的额外空间。

## 其他解法

### 使用内置集合运算（Python）
```python
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list(set(nums1) & set(nums2))
```

### 双指针法实现
```python
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        
        result = []
        i = j = 0
        
        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                i += 1
            elif nums1[i] > nums2[j]:
                j += 1
            else:
                if not result or result[-1] != nums1[i]:
                    result.append(nums1[i])
                i += 1
                j += 1
        
        return result
```

## 解法对比

| 解法 | 时间复杂度 | 空间复杂度 | 特点 |
|------|------------|------------|------|
| 哈希集合法 | O(n + m) | O(n + m) | **最优解**，效率最高 |
| 双指针法 | O(n log n + m log m) | O(log n + log m) | 空间效率高 |
| 二分查找法 | O(n log m) | O(1) | 适合一个数组很小的情况 |
| 集合运算 | O(n + m) | O(n + m) | Python特有，代码最简洁 |

## 关键点总结

1. **哈希集合法**是最优解，在面试中首选
2. **去重特性**：使用集合自动保证结果唯一性
3. **语言差异**：Go语言需要用`map[int]bool`模拟集合
4. **边界情况**：空数组、单元素数组、无交集等情况都能正确处理
5. **扩展思考**：本题可以扩展到求多个数组的交集

