<div align="center">

# 📚 核心笔记 (Core Notes)

<p align="center">
  <img src="https://img.shields.io/badge/Algorithm-Study%20Notes-brightgreen?style=for-the-badge&logo=github" alt="Algorithm Study Notes">
  <img src="https://img.shields.io/badge/Language-多语言-blue?style=for-the-badge" alt="Multi Language">
  <img src="https://img.shields.io/badge/Status-Active-success?style=for-the-badge" alt="Status">
</p>

> *🎯 一份系统化的算法学习笔记，助力编程面试和竞赛准备*

> *📈 从基础到进阶，覆盖核心算法思想与实战技巧*

</div>

---

## 📖 目录 (Table of Contents)

- [🔍 二分查找](#-二分查找)
- [👫 双指针法](#-双指针法快慢指针法)
- [🪟 滑动窗口](#-滑动窗口)
- [📊 复杂度分析](#-复杂度分析)
- [🛠️ 解题技巧](#️-解题技巧)
---

## 🔍 二分查找

### 💡 核心思想
在<span style="color: #FF6B6B; font-weight: bold;">有序数组</span>中使用分治策略，每次将搜索范围缩小一半，快速定位目标元素。

### 🎯 关键原则
> <span style="color: red; font-weight: bold;">⚠️ 循环不变量原则</span>：要在二分查找的过程中，保持不变量，这也就是「循环不变量」

> 💭 **思考要点**：只要看到面试题里给出的数组是有序数组，都可以想一想是否可以使用二分法。

### 📋 区间定义
确定要查找的区间到底是：
- 🔸 **左闭右开** `[left, right)`
- 🔹 **左闭右闭** `[left, right]`

<span style="color: #4ECDC4; font-weight: bold;">这就是不变量，「二分查找的循环中，坚持循环不变量的原则」</span>

### 🔨 标准模板

#### 模板一：左闭右闭 [left, right]
```cpp
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;  // 定义target在左闭右闭的区间里
    
    while (left <= right) {  // 当left==right，区间[left, right]依然有效
        int mid = left + (right - left) / 2;  // 防止溢出
        
        if (nums[mid] > target) {
            right = mid - 1;  // target在左区间，新区间是[left, mid-1]
        } else if (nums[mid] < target) {
            left = mid + 1;   // target在右区间，新区间是[mid+1, right]
        } else {
            return mid;       // 找到目标值
        }
    }
    return -1;  // 未找到目标
}
```

#### 模板二：左闭右开 [left, right)
```cpp
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size();  // 定义target在左闭右开的区间里
    
    while (left < right) {  // 因为left == right的时候，区间[left, right)无效
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > target) {
            right = mid;      // target在左区间，新区间是[left, mid)
        } else if (nums[mid] < target) {
            left = mid + 1;   // target在右区间，新区间是[mid+1, right)
        } else {
            return mid;       // 找到目标值
        }
    }
    return -1;  // 未找到目标
}
```

## 👫 双指针法（快慢指针法）

### 💡 核心思想
通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。

### 🎯 适用场景
- **数组去重**：移除重复元素
- **数组移动**：移除特定元素
- **链表操作**：环检测、中点查找
- **字符串处理**：回文判断、字符统计

### 🔨 经典模板

#### 模板一：数组元素移除
```cpp
int removeElement(vector<int>& nums, int val) {
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
        if (nums[fastIndex] != val) {
            nums[slowIndex++] = nums[fastIndex];
        }
    }
    return slowIndex;
}
```

#### 模板二：链表快慢指针
```cpp
// 检测链表是否有环
bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while (slow != fast) {
        if (!fast || !fast->next) return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}
```

#### 模板三：对撞指针
```cpp
// 判断回文字符串
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
```

### 💡 核心要点
- **速度差异**：快指针每次移动2步，慢指针1步
- **相遇条件**：有环时快慢指针必然相遇
- **边界处理**：注意空指针和单节点情况
- **应用灵活**：根据问题调整指针移动策略


## 🪟 滑动窗口

### 💡 核心思想
滑动窗口是一种基于**双指针**的高效算法技巧，通过不断调节子序列的起始位置和终止位置来解决特定问题。

其精妙之处在于根据当前子序列状态（如和、长度等），动态调节窗口边界，从而将 **O(n²)** 的暴力解法优化为 **O(n)**。

### 🎯 适用场景
- **子数组/子字符串问题**：最小/最大长度、和为目标值
- **字符统计问题**：无重复字符、字符频次
- **区间优化问题**：最大/最小覆盖、定长窗口
- **连续序列问题**：连续子数组、滑动最值

### 🔨 经典模板

#### 模板一：固定窗口大小
```cpp
vector<int> slidingWindowFixed(vector<int>& nums, int k) {
    vector<int> result;
    int sum = 0;
    
    // 初始化窗口
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    result.push_back(sum);
    
    // 滑动窗口
    for (int i = k; i < nums.size(); i++) {
        sum = sum - nums[i - k] + nums[i];  // 移除左边，添加右边
        result.push_back(sum);
    }
    return result;
}
```

#### 模板二：可变窗口大小（最小长度）
```cpp
int minSubArrayLen(int target, vector<int>& nums) {
    int result = INT_MAX;
    int sum = 0;
    int left = 0;
    
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];  // 扩大窗口
        
        while (sum >= target) {  // 收缩窗口
            result = min(result, right - left + 1);
            sum -= nums[left++];
        }
    }
    return result == INT_MAX ? 0 : result;
}
```

#### 模板三：可变窗口大小（最大长度）
```cpp
int lengthOfLongestSubstring(string s) {
    unordered_set<char> window;
    int maxLen = 0;
    int left = 0;
    
    for (int right = 0; right < s.length(); right++) {
        // 收缩窗口直到无重复字符
        while (window.count(s[right])) {
            window.erase(s[left++]);
        }
        
        window.insert(s[right]);  // 扩大窗口
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

### 💡 核心要点
- **窗口维护**：明确窗口的含义和维护方式
- **双指针协作**：left收缩窗口，right扩大窗口
- **状态更新**：及时更新窗口内的状态（和、计数等）
- **边界条件**：注意空数组和单元素情况
- **优化思路**：避免重复计算，利用窗口的连续性

### 🔄 算法流程
```
1. 初始化：left = 0, right = 0, 窗口状态
2. 扩大窗口：right右移，更新窗口状态
3. 判断条件：检查当前窗口是否满足条件
4. 收缩窗口：如需要，left右移，更新状态
5. 记录结果：更新最优解
6. 重复2-5直到right到达边界
```


## 📊 复杂度分析

### ⏱️ 时间复杂度对照表
| 复杂度 | 名称 | 典型算法 | 数据规模 |
|--------|------|----------|----------|
| O(1) | 常数 | 数组访问 | ∞ |
| O(log n) | 对数 | 二分查找 | 10^8 |
| O(n) | 线性 | 遍历数组 | 10^6 |
| O(n log n) | 线性对数 | 快速排序 | 10^5 |
| O(n²) | 平方 | 冒泡排序 | 10^3 |
| O(2^n) | 指数 | 回溯算法 | ≤25 |

### 🔢 空间复杂度对照表
| 复杂度 | 名称 | 典型场景 | 说明 |
|--------|------|----------|------|
| O(1) | 常数空间 | 原地算法 | 只使用有限个变量 |
| O(log n) | 对数空间 | 递归调用 | 二分查找的递归实现 |
| O(n) | 线性空间 | 额外数组 | 哈希表、动态规划 |
| O(n²) | 平方空间 | 二维数组 | 图的邻接矩阵 |

---

## 🛠️ 解题技巧

### 🎯 识别模式
- **🔍 有序数组** → 二分查找
- **📏 连续子数组** → 滑动窗口、前缀和
- **👫 数组双指针** → 对撞指针、快慢指针
- **🪟 窗口问题** → 固定/可变滑动窗口
- **🔄 排列组合** → 回溯算法、DFS
- **💰 最优化问题** → 动态规划、贪心
- **🌳 树形结构** → 递归、层序遍历
- **📊 图论问题** → BFS、DFS、最短路径

### ⚡ 优化技巧
- **🎨 空间换时间**：哈希表、前缀和、缓存
- **⏰ 预处理**：排序、预计算、建索引
- **🔢 位运算**：状态压缩、快速计算、掩码
- **🪟 窗口技巧**：双指针、滑动统计、单调队列
- **✂️ 剪枝优化**：提前返回、条件过滤、边界处理
- **📝 记忆化**：递归缓存、状态记录、避免重计算

---

<div align="center">

## 🎉 Happy Coding! 🎉

> *"算法不是目的，思维才是核心"*

<p align="center">
  <img src="https://img.shields.io/badge/Made%20with-❤️-red?style=for-the-badge" alt="Made with Love">
  <img src="https://img.shields.io/badge/Last%20Updated-2025--08--13-blue?style=for-the-badge" alt="Last Updated">
</p>

**⭐ 如果这份笔记对你有帮助，请给个Star支持一下！⭐**

</div>