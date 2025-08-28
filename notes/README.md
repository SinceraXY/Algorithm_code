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
- [👫 双指针技术](#-双指针技术)
- [🪟 滑动窗口](#-滑动窗口)
- [🎭 虚拟头节点技巧](#-虚拟头节点技巧)
- [🔍 哈希表](#-哈希表)
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

## 👫 双指针技术

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

## 🎭 虚拟头节点技巧

### 💡 核心思想
设置一个虚拟头节点（dummyHead），统一处理头节点和其他节点的操作，简化边界条件处理。

> ⚠️ **重要提醒**：返回结果时需要 `return dummyHead->next;`

### 🎯 适用场景
- **链表删除**：移除链表元素、删除重复节点
- **链表插入**：有序链表插入、节点重排
- **链表合并**：合并多个链表、拼接操作
- **链表构建**：从数组构建链表、逆向构建

### 🔨 标准模板
```cpp
// 虚拟头节点标准模板
ListNode* processLinkedList(ListNode* head) {
    ListNode* dummy = new ListNode(0);  // 创建虚拟头节点
    dummy->next = head;                 // 指向原头节点
    ListNode* cur = dummy;              // 工作指针
    
    while (cur->next != nullptr) {
        // 根据条件进行操作
        if (shouldProcess(cur->next)) {
            // 删除节点
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        } else {
            cur = cur->next;
        }
    }
    
    return dummy->next;  // 返回真正的头节点
}
```

### 💡 核心优势
- **统一逻辑**：头节点和其他节点处理方式一致
- **简化代码**：避免复杂的边界条件判断
- **减少错误**：降低空指针和边界问题
- **易于理解**：代码逻辑更清晰直观


## 🔍 哈希表

### 💡 核心思想
哈希表是根据关键码的值而直接进行访问的数据结构，通过**哈希函数**将关键字映射到存储位置，实现 **O(1)** 平均时间复杂度的查找、插入和删除操作。

### 🎯 适用场景
- **快速查找**：判断元素是否存在集合中
- **计数统计**：统计元素出现频次、字符计数
- **去重操作**：数组去重、集合运算
- **映射关系**：建立键值对应关系
- **缓存实现**：LRU缓存、数据缓存

### 🏗️ 数据结构选择

| 数据结构 | C++ | Python | Go | 时间复杂度 | 特点 |
|----------|-----|--------|----|-----------|----- |
| **数组** | `int arr[26]` | `[0] * 26` | `[26]int{}` | O(1) | 固定范围，空间高效 |
| **哈希集合** | `unordered_set` | `set()` | `map[int]bool` | O(1) | 去重，快速查找 |
| **哈希映射** | `unordered_map` | `dict` | `map[int]int` | O(1) | 键值对，计数统计 |
| **有序集合** | `set` | `sorted(set())` | `sync.Map` | O(log n) | 有序存储 |

### 🔍 C++容器详细对比

#### 集合类型 (Set)
| 集合类型 | `std::set` | `std::multiset` | `std::unordered_set` |
|----------|------------|-----------------|---------------------|
| **底层实现** | 红黑树 | 红黑树 | 哈希表 |
| **是否有序** | 有序 | 有序 | 无序 |
| **数值是否可重复** | 否 | 是 | 否 |
| **能否更改数值** | 否 | 否 | 否 |
| **查询效率** | O(log n) | O(log n) | O(1) |
| **增删效率** | O(log n) | O(log n) | O(1) |

#### 映射类型 (Map)  
| 映射类型 | `std::map` | `std::multimap` | `std::unordered_map` |
|----------|------------|-----------------|---------------------|
| **底层实现** | 红黑树 | 红黑树 | 哈希表 |
| **是否有序** | key有序 | key有序 | key无序 |
| **数值是否可重复** | key不可重复 | key可重复 | key不可重复 |
| **能否更改数值** | key不可修改 | key不可修改 | key不可修改 |
| **查询效率** | O(log n) | O(log n) | O(1) |
| **增删效率** | O(log n) | O(log n) | O(1) |

### 💡 选择原则
> <span style="color: #FF6B6B; font-weight: bold;">⚠️ 关键判断</span>：数据范围小且连续 → 数组；需要去重 → set；需要计数 → map

> **优先级**：`unordered_set/map` > `set/map` > 数组 > 其他容器

### 🎯 使用建议
- **集合问题**：优先使用 `unordered_set`（查询增删效率最优）
  - 需要有序：使用 `set`
  - 需要有序+重复数据：使用 `multiset`
- **映射问题**：优先使用 `unordered_map`（key-value结构，性能最优）
  - 需要key有序：使用 `map`
  - 需要key有序+可重复：使用 `multimap`

### 🔧 底层原理
- **红黑树特点**：平衡二叉搜索树，key值有序但不可修改（修改会破坏树结构）
- **哈希表特点**：通过哈希函数映射，平均O(1)访问，但无序存储
- **跨语言通用**：Java的HashMap/TreeMap、Python的dict/set等都遵循相同原理
- **术语统一**：虽然set/multiset底层是红黑树，但解决映射问题的方法仍称为"哈希法"

### 🔨 经典模板

#### 模板一：数组计数（字符/数字范围固定）
```cpp
// 统计字符频次
vector<int> charCount(string s) {
    vector<int> count(26, 0);  // 假设只有小写字母
    for (char c : s) {
        count[c - 'a']++;
    }
    return count;
}
```

#### 模板二：哈希集合去重
```cpp
// 数组交集
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> result;
    
    for (int num : nums2) {
        if (set1.count(num)) {
            result.insert(num);
        }
    }
    return vector<int>(result.begin(), result.end());
}
```

#### 模板三：哈希映射计数
```cpp
// 两数之和
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;  // 值 -> 索引
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (map.count(complement)) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {};
}
```

#### 模板四：字符串哈希
```cpp
// 字母异位词检测
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    
    unordered_map<char, int> count;
    for (char c : s) count[c]++;
    for (char c : t) count[c]--;
    
    for (auto& p : count) {
        if (p.second != 0) return false;
    }
    return true;
}
```

### 💡 核心要点
- **哈希函数设计**：均匀分布、计算高效、冲突少
- **冲突处理**：链地址法、开放定址法
- **负载因子控制**：保持在0.75以下，避免性能退化
- **扩容机制**：动态调整表大小，重新哈希
- **空间权衡**：小范围用数组，大范围用哈希表

### 🚀 性能优化
- **预分配容量**：避免频繁扩容rehash
- **选择合适结构**：根据数据特点选择容器
- **避免哈希冲突**：设计好的哈希函数
- **内存局部性**：连续访问提高缓存命中

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

### 🎯 问题类型识别
| 关键词 | 算法类型 | 常用技巧 |
|--------|----------|----------|
| 🔍 有序数组 | 二分查找 | 左右边界、搜索插入位置 |
| 📏 连续子数组 | 滑动窗口 | 固定窗口、可变窗口 |
| 👫 数组操作 | 双指针 | 对撞指针、快慢指针 |
| 🔗 链表操作 | 虚拟头节点 | 统一删除、简化插入 |
| 🌳 树形结构 | 递归/DFS | 前序、中序、后序遍历 |
| 🔄 排列组合 | 回溯算法 | 剪枝、状态回溯 |
| 💰 最优化 | 动态规划 | 状态转移、最优子结构 |
| 📊 图论问题 | BFS/DFS | 层序遍历、路径搜索 |

### ⚡ 优化策略
- **🎨 空间换时间**：哈希表缓存、前缀和预计算
- **⏰ 预处理优化**：数据排序、建立索引、预计算
- **🔢 位运算技巧**：状态压缩、快速幂、掩码操作
- **🪟 区间优化**：滑动窗口、双指针、单调队列
- **✂️ 剪枝策略**：提前返回、条件过滤、边界处理
- **📝 记忆化搜索**：递归缓存、避免重复计算

### 🧠 解题思维模式
```
1. 📖 理解题意 → 明确输入输出，理解约束条件
2. 🎯 分析模式 → 识别算法类型，选择合适方法
3. 🔧 设计算法 → 确定数据结构，设计核心逻辑
4. ✅ 验证正确性 → 边界测试，时空复杂度分析
5. 🚀 优化实现 → 代码简化，性能优化
```

---

<div align="center">

## 🎉 Happy Coding! 🎉

> *"算法不是目的，思维才是核心"*  
> *"Practice makes perfect, persistence makes progress"*

<p align="center">
  <img src="https://img.shields.io/badge/Made%20with-❤️-red?style=for-the-badge" alt="Made with Love">
  <img src="https://img.shields.io/badge/Last%20Updated-2025--08--28-blue?style=for-the-badge" alt="Last Updated">
</p>

**⭐ 如果这份笔记对你有帮助，请给个Star支持一下！⭐**

</div>