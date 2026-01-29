# 239. 滑动窗口最大值

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/sliding-window-maximum/description/
- **难度**：Hard
- **标签**：队列、数组、滑动窗口、单调队列、堆（优先队列）

## 题目描述

给你一个整数数组 `nums`，有一个大小为 `k` 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 `k` 个数字。

滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

## 示例

**示例 1：**
```
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
```

**示例 2：**
```
输入：nums = [1], k = 1
输出：[1]
```

## 解题思路

### 方法一：单调队列（推荐，下标版）

**核心思路：**
- 用一个双端队列 `deque` 存储元素的**下标**，并保证队列对应的值从队首到队尾**单调递减**。
- 队首永远是当前窗口的最大值下标。

**维护规则：**
1. **入队（push）**：当新元素 `nums[i]` 进入窗口时，把队尾所有 `nums[队尾] <= nums[i]` 的下标弹出，再把 `i` 入队。
2. **出队（pop）**：当窗口右移时，如果队首下标已经滑出窗口（`q.front() <= i - k`），就从队首弹出。
3. **取最大值**：每次窗口形成后，`nums[q.front()]` 即当前窗口最大值。

### 方法二：单调队列（自定义队列版，存值）

**核心思路：**
- 自定义一个单调队列 `MyQueue`（从大到小），队首始终为最大值。
- 窗口右移时：先 `pop` 掉将离开窗口的值，再 `push` 新进入窗口的值。

### 方法三：优先队列（堆）

**核心思路：**
- 使用大根堆存储 `(值, 下标)`。
- 每次入堆当前元素，然后持续弹出堆顶中已离开窗口的元素（`index <= i-k`），此时堆顶就是窗口最大值。

## 代码实现

### C++（单调队列：下标版）

```cpp
//单调队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>q;
        for(int i=0;i<k;++i)
        {
            while(!q.empty()&&nums[i]>=nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans={nums[q.front()]};
        for(int i=k;i<n;++i)
        {
            while(!q.empty()&&nums[i]>=nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
            while(q.front()<=i-k)
            {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
```

### C++（单调队列：自定义队列版，存值）

```cpp
//单调队列
class Solution {
private:
    class MyQueue {  //单调队列（从大到小）
    public:
        deque<int> que;  //使用deque来实现单调队列
        //每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        //同时pop之前判断队列当前是否为空。
        void pop(int value)
        {
            if(!que.empty()&&value==que.front())
            {
                que.pop_front();
            }
        }
        //如果新加入的值大于队列尾部(back)的值，就不断弹出队尾元素，
        //直到新值小于等于队尾元素为止。
        //这样可以保持队列从front到back单调递减。
        void push(int value)
        {
            while(!que.empty()&&value>que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }
        //查询当前队列里的最大值，直接返回队列前端也就是front就可以了。
        int front()
        {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      MyQueue que;
      vector<int> result;
      for(int i=0;i<k;i++)   //先将前k的元素放进队列
      {
        que.push(nums[i]);
      }
      result.push_back(que.front());   //result记录前k的元素的最大值
      for(int i=k;i<nums.size();i++)
      {
        que.pop(nums[i-k]);   //滑动窗口移除最前面元素
        que.push(nums[i]);    //滑动窗口前加入最后面的元素
        result.push_back(que.front());   //记录对应的最大值
      }
      return result;
    }
};
```

### C++（优先队列）

```cpp
//优先队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>>q;
        for(int i =0;i<k;++i)
        {
            q.emplace(nums[i],i);
        }
        vector<int> ans = {q.top().first};
        for(int i=k;i<n;++i)
        {
            q.emplace(nums[i],i);
            while(q.top().second<=i-k)
            {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};
```

## 复杂度分析

### 单调队列（推荐）

- **时间复杂度**：O(n)，其中 n 是数组 nums 的长度。每一个下标恰好被放入队列一次，并且最多被弹出队列一次，因此时间复杂度为 O(n)。
- **空间复杂度**：O(k)。由于我们使用双端队列并且会不断从队首弹出窗口外的元素，因此队列中最多不会有超过 k+1 个元素，队列使用的空间为 O(k)。

### 优先队列

- **时间复杂度**：O(nlogn)，其中 n 是数组 nums 的长度。在最坏情况下，数组 nums 中的元素单调递增，那么最终优先队列中包含了所有元素，没有元素被移除。由于将一个元素放入优先队列的时间复杂度为 O(logn)，因此总时间复杂度为 O(nlogn)。
- **空间复杂度**：O(n)，即为优先队列需要使用的空间。这里所有的空间复杂度分析都不考虑返回的答案需要的 O(n) 空间，只计算额外的空间使用。

## 关键点

1. 单调队列要维护“从队首到队尾单调递减”，队首就是最大值。
2. 注意窗口右移时，要及时弹出已经离开窗口范围的元素（通过下标判断或通过值配合 pop）。
3. `k = 1` 时答案就是原数组；实现中也能自然处理。