# 454. 四数相加 II

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/4sum-ii/description/
- **难度**：Medium
- **标签**：数组、哈希表

## 题目描述

给你四个整数数组 `nums1`、`nums2`、`nums3` 和 `nums4`，数组长度都是 `n`，请你计算有多少个四元组 `(i, j, k, l)` 能满足：

- `0 <= i, j, k, l < n`
- `nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0`

### 示例

**示例 1：**
```
输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
输出：2
解释：
两个四元组如下：
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
```

**示例 2：**
```
输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
输出：1
```

### 提示
- `n == nums1.length`
- `n == nums2.length`  
- `n == nums3.length`
- `n == nums4.length`
- `1 <= n <= 200`
- `-2²⁸ <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2²⁸`

## 解题思路

### 方法：哈希表分组

**核心思想：**
将四个数组分为两组，用哈希表存储前两个数组的和，然后在后两个数组中寻找目标值。

**算法步骤：**
1. **第一阶段**：遍历 `nums1` 和 `nums2`，计算所有可能的两数之和 `a + b`，用哈希表记录每个和值出现的次数
2. **第二阶段**：遍历 `nums3` 和 `nums4`，对于每个两数之和 `c + d`，在哈希表中查找 `-(c + d)`
3. **统计结果**：如果找到匹配的值，将其出现次数累加到结果中

**为什么这样分组：**
- 将 O(n⁴) 的暴力解法优化为 O(n²)
- 前两个数组的组合结果用哈希表存储，后两个数组直接查找互补值
- 空间换时间的经典策略

## 复杂度分析

- **时间复杂度**：O(n²)
  - 第一阶段遍历 nums1 和 nums2：O(n²)
  - 第二阶段遍历 nums3 和 nums4：O(n²) 
  - 哈希表查找操作：O(1)

- **空间复杂度**：O(n²)
  - 哈希表最多存储 n² 个不同的和值

## 代码实现

### C++ 实现
```cpp
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;   //key:a+b的数值，value:a+b数值出现的次数
        for(int a:nums1)
        {
            for(int b:nums2)
            {
                umap[a+b]++;
            }
        }
        int count=0;
        //在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就把map中key对应的value也就是出现次数统计出来。
        for(int c:nums3)
        {
            for(int d:nums4)
            {
                if(umap.find(0-(c+d))!=umap.end())
                {
                    count+=umap[0-(c+d)];
                }
            }
        }
        return count;
    }
};
```

### Python 实现
```python
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        countAB = collections.Counter(u + v for u in A for v in B)
        ans = 0
        for u in C:
            for v in D:
                if -u - v in countAB:
                    ans += countAB[-u - v]
        return ans
```

### Go 实现
```go
func fourSumCount(nums1 []int, nums2 []int, nums3 []int, nums4 []int) int {
    umap := make(map[int]int) // key:a+b的数值，value:a+b数值出现的次数
    for _, a := range nums1 {
        for _, b := range nums2 {
            umap[a+b]++
        }
    }
    count := 0
    // 在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就把map中key对应的value也就是出现次数统计出来。
    for _, c := range nums3 {
        for _, d := range nums4 {
            count += umap[-c-d]
        }
    }
    return count
}
```

## 实现差异分析

| 语言 | 特点 | 关键差异 |
|------|------|----------|
| **C++** | 严格的类型检查 | 需要显式检查 `find()` 结果判断键是否存在 |
| **Python** | 简洁优雅 | 使用 `collections.Counter` 和生成器表达式，代码最简洁 |
| **Go** | 高效简洁 | 直接访问 map，不存在的键返回零值，无需显式检查 |

## 关键知识点

1. **哈希表分组策略**：将四数和问题转化为两个两数和问题
2. **时间复杂度优化**：从 O(n⁴) 优化到 O(n²)
3. **空间换时间**：使用额外 O(n²) 空间换取时间效率
4. **互补数查找**：在哈希表中查找使和为0的补数

## 注意事项

1. **数组长度限制**：所有数组长度相等且为 n
2. **重复计数**：相同和值的不同组合需要分别统计
3. **数据范围**：注意整数溢出问题（题目保证在int范围内）
4. **哈希表操作**：不同语言处理不存在键的方式不同