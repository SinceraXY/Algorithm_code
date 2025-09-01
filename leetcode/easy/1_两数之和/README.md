# 1. 两数之和

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/two-sum/description/
- **难度**：Easy
- **标签**：数组、哈希表

## 题目描述

给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出**和为目标值** `target` 的那**两个**整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

## 示例

**示例 1：**
```
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```

**示例 2：**
```
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

**示例 3：**
```
输入：nums = [3,3], target = 6
输出：[0,1]
```

## 解题思路

### 方法：哈希表法

**思路：**
1. 遍历数组，对于每个元素 `nums[i]`，计算目标值与当前元素的差值 `complement = target - nums[i]`
2. 查找哈希表中是否存在这个差值
3. 如果存在，说明找到了两个数的和等于目标值，返回它们的下标
4. 如果不存在，将当前元素值和下标存入哈希表中
5. 继续遍历直到找到答案

**优势：**
- 时间复杂度：O(n) - 只需要遍历一次数组
- 空间复杂度：O(n) - 最坏情况下需要存储 n-1 个元素到哈希表

## 代码实现

### C++
```cpp
//哈希表法
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            std::unordered_map <int,int> map;
            for(int i = 0; i < nums.size(); i++) {
                auto iter = map.find(target - nums[i]);
                if(iter != map.end()) {
                    return {iter->second, i};
                }
                map[nums[i]]=i;
            }
            return {};
        }
    };
```

### Python
```python
# 哈希表法
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = dict()
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hashmap:
                return [hashmap[complement], i]
            hashmap[nums[i]] = i
        return []
```

### Go
```go
// 哈希表法
func twoSum(nums []int, target int) []int {
    hashMap := make(map[int]int)
    for i, num := range nums {
        complement := target - num
        if index, exists := hashMap[complement]; exists {
            return []int{index, i}
        }
        hashMap[num] = i
    }
    return []int{}
}
```

## 复杂度分析

- **时间复杂度：** O(n)，其中 n 是数组中的元素数量。对于每一个元素 x，我们可以 O(1) 地寻找 target - x
- **空间复杂度：** O(n)，其中 n 是数组中的元素数量。主要为哈希表的开销

## 关键点

1. **哈希表的使用**：利用哈希表可以快速查找的特性，将查找时间从 O(n) 降低到 O(1)
2. **一次遍历**：在遍历的同时查找和存储，避免了两次遍历的需要
3. **边界处理**：题目保证有解，所以不需要额外的边界判断