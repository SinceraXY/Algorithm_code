# 0001 Two Sum

- 平台：LeetCode
- 链接：https://leetcode.com/problems/two-sum/
- 难度：Easy

## 思路
- 使用哈希表记录数值到下标的映射，遍历数组时查找 `target - x` 是否已出现。
- 命中则返回两下标；未命中则记录当前值与下标继续。

## 复杂度
- 时间：O(n)
- 空间：O(n)

## 代码（Python）
```python
from typing import List

def two_sum(nums: List[int], target: int) -> List[int]:
    index_by_value = {}
    for i, x in enumerate(nums):
        complement = target - x
        if complement in index_by_value:
            return [index_by_value[complement], i]
        index_by_value[x] = i
    return []
``` 