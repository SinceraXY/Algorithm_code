# 15. 三数之和

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/3sum/description/
- **难度**：Medium
- **标签**：数组、双指针、排序

## 题目描述

给你一个整数数组 `nums` ，判断是否存在三元组 `[nums[i], nums[j], nums[k]]` 满足 `i != j`、`i != k` 且 `j != k` ，同时还满足 `nums[i] + nums[j] + nums[k] == 0` 。

请你返回所有和为 `0` 且不重复的三元组。

**注意：**答案中不可以包含重复的三元组。

## 示例

**示例 1：**
```
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
```

**示例 2：**
```
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
```

**示例 3：**
```
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
```

## 解题思路

### 方法一：哈希表法

**思路：**
1. 先对数组排序，便于去重
2. 遍历数组，固定第一个数 `nums[i]`
3. 在 `i` 后面的元素中寻找两数之和为 `0 - nums[i]` 的组合
4. 使用哈希表记录遍历过的元素，避免重复查找
5. 通过多层去重逻辑确保结果不重复

**去重策略：**
- 对第一个元素 `a` 去重：跳过与前一个相同的元素
- 对第二个元素 `b` 去重：连续三个相同元素时跳过
- 对第三个元素 `c` 去重：找到后从哈希表中删除

### 方法二：双指针法（推荐）

**思路：**
1. 对数组排序
2. 遍历数组，固定第一个数 `nums[i]`
3. 使用双指针 `left` 和 `right` 在剩余数组中寻找两数之和
4. 根据三数之和与目标值的关系移动指针
5. 找到解后进行去重处理

**优势：**
- 时间复杂度更优：O(n²)
- 去重逻辑更清晰
- 不需要额外的哈希表空间

**关键去重点：**
- **第一层去重**：`if(i > 0 && nums[i] == nums[i-1]) continue;`
- **找到解后去重**：移动 `left` 和 `right` 跳过相同元素
- **去重时机**：必须在找到解后再去重，否则可能漏解

## 代码实现

### C++ - 哈希表法
```cpp
//哈希法
class Solution {
  public:
      vector<vector<int>> threeSum(vector<int>& nums) {
          vector<vector<int>>result;
          sort(nums.begin(),nums.end());
          for(int i=0;i<nums.size();i++)
          {
              if(nums[i]>0)    //排序之后如果第一个元素已经大于零，那么不可能凑成三元组
              {
                  continue;
              }
              if(i>0&&nums[i]==nums[i-1])    //三元组元素a去重
              {
                  continue;
              }
              unordered_set<int>set;
              for(int j=i+1;j<nums.size();j++)
              {
                  if(j>i+2
                      &&nums[j]==nums[j-1]
                      &&nums[j-1]==nums[j-2])   //三元组元素b去重
                      {
                          continue;
                      }
                      int c=0-(nums[i]+nums[j]);
                      if(set.find(c)!=set.end())
                      {
                          result.push_back({nums[i],nums[j],c});
                          set.erase(c);       //三元组元素c去重
                      }
                      else
                      {
                          set.insert(nums[j]);
                      }
              }
          }
          return result;
      }
  };
```

### C++ - 双指针法
```cpp
//双指针法
class Solution {
  public:
      vector<vector<int>> threeSum(vector<int>& nums) {
          vector<vector<int>> result;
          sort(nums.begin(),nums.end());
          for(int i=0;i<nums.size();i++)
          {
              if(nums[i]>0)   //排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
              {
                  return result;
              }
              //正确去重方法
              if(i>0&&nums[i]==nums[i-1])
              {
                  continue;
              }
              int left=i+1;
              int right=nums.size()-1;
              while(right>left)
              {
                  if(nums[i]+nums[left]+nums[right]>0)
                  {
                      right--;
                  }
                  else if(nums[i]+nums[left]+nums[right]<0)
                  {
                      left++;
                  }
                  else
                  {
                      result.push_back(vector<int>{nums[i],nums[left],nums[right]});
                      //去重逻辑应该放在找到一个三元组之后
                      while(right>left&&nums[right]==nums[right-1])
                      {
                          right--;
                      }
                      while(right>left&&nums[left]==nums[left+1])
                      {
                          left++;
                      }
                      //找到答案时，双指针同时收缩
                      right--;
                      left++;
                  }
              }
          }
          return result;
      }
  };
```

### Python
```python
# 双指针法
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()
        
        for i in range(len(nums)):
            # 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if nums[i] > 0:
                return result
            
            # 正确去重方法
            if i > 0 and nums[i] == nums[i-1]:
                continue
            
            left = i + 1
            right = len(nums) - 1
            
            while right > left:
                if nums[i] + nums[left] + nums[right] > 0:
                    right -= 1
                elif nums[i] + nums[left] + nums[right] < 0:
                    left += 1
                else:
                    result.append([nums[i], nums[left], nums[right]])
                    # 去重逻辑应该放在找到一个三元组之后
                    while right > left and nums[right] == nums[right-1]:
                        right -= 1
                    while right > left and nums[left] == nums[left+1]:
                        left += 1
                    # 找到答案时，双指针同时收缩
                    right -= 1
                    left += 1
        
        return result
```

### Go
```go
// 双指针法
func threeSum(nums []int) [][]int {
    result := [][]int{}
    sort.Ints(nums)
    
    for i := 0; i < len(nums); i++ {
        // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
        if nums[i] > 0 {
            return result
        }
        
        // 正确去重方法
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        
        left := i + 1
        right := len(nums) - 1
        
        for right > left {
            if nums[i]+nums[left]+nums[right] > 0 {
                right--
            } else if nums[i]+nums[left]+nums[right] < 0 {
                left++
            } else {
                result = append(result, []int{nums[i], nums[left], nums[right]})
                // 去重逻辑应该放在找到一个三元组之后
                for right > left && nums[right] == nums[right-1] {
                    right--
                }
                for right > left && nums[left] == nums[left+1] {
                    left++
                }
                // 找到答案时，双指针同时收缩
                right--
                left++
            }
        }
    }
    
    return result
}
```

## 复杂度分析

### 哈希表法：
- **时间复杂度：** O(n²)，其中 n 是数组长度。外层循环 O(n)，内层循环 O(n)，哈希表操作 O(1)
- **空间复杂度：** O(n)，哈希表最多存储 n 个元素

### 双指针法：
- **时间复杂度：** O(n²)，排序 O(n log n)，外层循环 O(n)，双指针遍历 O(n)
- **空间复杂度：** O(1)，只使用常数额外空间（不算返回数组）

## 关键点

1. **排序的重要性**：排序后可以使用双指针技巧，且便于去重
2. **去重策略**：
   - 第一层去重：`i > 0 && nums[i] == nums[i-1]`
   - 找到解后去重：跳过相同的 `left` 和 `right` 值
3. **早期终止**：当 `nums[i] > 0` 时直接返回结果
4. **去重时机**：双指针法中，去重必须在找到解后进行，避免漏解
5. **指针移动**：找到解后双指针必须同时收缩