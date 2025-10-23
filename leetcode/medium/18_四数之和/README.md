# 18. 四数之和

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/4sum/description/
- **难度**：Medium
- **标签**：数组、双指针、排序

## 题目描述

给你一个由 `n` 个整数组成的数组 `nums`，和一个目标值 `target`。请你找出并返回满足下述全部条件且**不重复**的四元组 `[nums[a], nums[b], nums[c], nums[d]]`：

- `0 <= a, b, c, d < n`
- `a`、`b`、`c` 和 `d` **互不相同**
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

你可以按**任意顺序**返回答案。

**示例 1：**
```
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

**示例 2：**
```
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
```

## 解题思路

### 方法：排序 + 双指针

本题是三数之和的升级版，采用**排序 + 双指针**的方法。

**基本思路：**
1. 先对数组进行排序
2. 使用四个指针：
   - 最外层循环：第一个数的指针 `k`
   - 第二层循环：第二个数的指针 `i`
   - 双指针：`left`（从 `i+1` 开始）和 `right`（从数组末尾开始）
3. 固定前两个数，用双指针寻找后两个数

**关键优化：**

### 1. 去重处理
- **第一层去重**：`if (k > 0 && nums[k] == nums[k-1]) continue;`
- **第二层去重**：`if (i > k+1 && nums[i] == nums[i-1]) continue;`
- **双指针去重**：找到答案后，跳过相同的元素
  ```cpp
  while(right > left && nums[right] == nums[right-1]) right--;
  while(right > left && nums[left] == nums[left+1]) left++;
  ```

### 2. 剪枝优化
- **最小值剪枝**：如果当前最小的四个数之和已经大于 target，直接 break
  ```cpp
  if (nums[k] + nums[k+1] + nums[k+2] + nums[k+3] > target) break;
  ```
- **最大值剪枝**：如果当前数与最大的三个数之和仍小于 target，continue
  ```cpp
  if (nums[k] + nums[length-3] + nums[length-2] + nums[length-1] < target) continue;
  ```

### 3. 溢出处理
- 使用 `long` 类型（或 `int64`）防止整数溢出
- **注意**：不能用 `nums[k] > target` 来剪枝，因为 target 可能是负数

## 复杂度分析

- **时间复杂度**：O(n³)，其中 n 是数组的长度
  - 排序的时间复杂度是 O(nlogn)
  - 枚举四元组的时间复杂度是 O(n³)
  - 因此总时间复杂度为 O(n³ + nlogn) = O(n³)

- **空间复杂度**：O(logn)，其中 n 是数组的长度
  - 空间复杂度主要取决于排序额外使用的空间
  - 此外排序修改了输入数组 nums，实际情况中不一定允许，因此也可以看成使用了一个额外的数组存储了数组 nums 的副本并排序，空间复杂度为 O(n)

## 代码实现

### C++
```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int length=nums.size();
        for(int k=0;k<length-3;k++)
        {
            //去重
            if(k>0&&nums[k]==nums[k-1])
            {
                continue;
            }
            //剪枝
            if ((long) nums[k] + nums[k + 1] + nums[k + 2] + nums[k + 3] > target)
            {
                break;
            }
            if ((long) nums[k] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target)
            {
                continue;
            }
            for(int i=k+1;i<length-2;i++)
            {
                //正确去重方法
                if(i>k+1&&nums[i]==nums[i-1])
                {
                    continue;
                }
                if ((long) nums[k] + nums[i] + nums[i + 1] + nums[i + 2] > target)
                {
                    break;
                }
                if ((long) nums[k] + nums[i] + nums[length - 2] + nums[length - 1] < target)
                {
                    continue;
                }
                int left=i+1;
                int right=length-1;
                while(right>left)
                {
                    if((long)nums[k]+nums[i]+nums[left]+nums[right]>target)
                    {
                        right--;
                    }
                    else if((long)nums[k]+nums[i]+nums[left]+nums[right]<target)
                    {
                        left++;
                    }
                    else
                    {
                        result.push_back(vector<int>{nums[k],nums[i],nums[left],nums[right]});
                        //去重逻辑应该放在成功找到一个四元组之后
                        while(right>left&&nums[right]==nums[right-1])right--;
                        while(right>left&&nums[left]==nums[left+1])left++;
                        //找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};
```

### Python
详见 [18_四数之和.py](./18_四数之和.py)

### Go
详见 [18_四数之和.go](./18_四数之和.go)

## 相关题目

- [1. 两数之和](https://leetcode.cn/problems/two-sum/)
- [15. 三数之和](https://leetcode.cn/problems/3sum/)
- [454. 四数相加 II](https://leetcode.cn/problems/4sum-ii/)