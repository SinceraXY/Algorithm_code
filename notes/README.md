<div align="center">

# 📚 核心笔记 (Core Notes)

<p align="center">
  <img src="https://img.shields.io/badge/Algorithm-Study%20Notes-brightgreen?style=for-the-badge&logo=github" alt="Algorithm Study Notes">
  <img src="https://img.shields.io/badge/Language-多语言-blue?style=for-the-badge" alt="Multi Language">
  <img src="https://img.shields.io/badge/Status-Active-success?style=for-the-badge" alt="Status">
  <img src="https://img.shields.io/badge/Templates-30+-orange?style=for-the-badge" alt="Templates">
</p>

> *🎯 一份系统化的算法学习笔记，助力编程面试和竞赛准备*
>
> *📈 从基础到进阶，覆盖核心算法思想与实战技巧*
>
> *💡 理论 + 模板 + 实战，打造完整的算法知识体系*

---

**✨ 特色亮点**

🎨 **系统化** - 知识体系完整，由浅入深  
⚡ **实战性** - 30+ 代码模板，直接套用  
🔍 **可视化** - 图文并茂，易于理解  
🌍 **多语言** - C++ / Python / Go 三语言对照  

</div>

---

## 🚀 快速导航

<table>
<tr>
<td width="25%" align="center">
  <h3>📊 数组专题</h3>
  <p>二分查找 · 双指针</p>
  <p>滑动窗口 · 前缀和</p>
  <a href="./topics/数组算法专题.md">进入专题 →</a>
</td>
<td width="25%" align="center">
  <h3>🔗 链表专题</h3>
  <p>虚拟头节点 · 反转</p>
  <p>快慢指针 · 环检测</p>
  <a href="./topics/链表算法专题.md">进入专题 →</a>
</td>
<td width="25%" align="center">
  <h3>🔢 哈希表专题</h3>
  <p>快速查找 · 计数</p>
  <p>去重集合 · 映射</p>
  <a href="./topics/哈希表算法专题.md">进入专题 →</a>
</td>
<td width="25%" align="center">
  <h3>🔤 字符串专题</h3>
  <p>KMP · 滑动窗口</p>
  <p>回文 · 动态规划</p>
  <a href="./topics/字符串算法专题.md">进入专题 →</a>
</td>
</tr>
</table>

---

## 📖 目录 (Table of Contents)

### 🎯 核心算法专题
| 专题 | 难度 | 核心技巧 | 文档链接 |
|------|------|----------|----------|
| 📊 数组算法 | ⭐⭐ | 二分查找、双指针、滑动窗口 | [查看详情](./topics/数组算法专题.md) |
| 🔗 链表算法 | ⭐⭐ | 虚拟头节点、快慢指针、反转 | [查看详情](./topics/链表算法专题.md) |
| 🔢 哈希表算法 | ⭐⭐ | 计数统计、快速查找、去重 | [查看详情](./topics/哈希表算法专题.md) |
| 🔤 字符串算法 | ⭐⭐⭐ | KMP、滑动窗口、回文、DP | [查看详情](./topics/字符串算法专题.md) |

### 📚 核心笔记章节

<div style="background-color: #F5F5F5; padding: 16px; border-radius: 8px; margin: 16px 0;">

| 章节 | 内容概要 | 快速跳转 |
|:----:|:---------|:--------:|
| 🔍 | **二分查找** - 循环不变量、左闭右闭/左闭右开模板 | [查看 ↓](#-二分查找) |
| 👫 | **双指针技术** - 快慢指针、对撞指针、同向指针 | [查看 ↓](#-双指针技术) |
| 🪟 | **滑动窗口** - 固定窗口、可变窗口、时间优化 | [查看 ↓](#-滑动窗口) |
| 🎭 | **虚拟头节点** - 链表操作统一处理技巧 | [查看 ↓](#-虚拟头节点技巧) |
| 🔢 | **哈希表** - 数组/set/map选择、容器对比 | [查看 ↓](#-哈希表) |
| 📊 | **复杂度分析** - 时间空间复杂度速查表 | [查看 ↓](#-复杂度分析) |
| 🛠️ | **解题技巧** - 问题识别、优化策略、思维模式 | [查看 ↓](#️-解题技巧) |

</div>

---

## 🔍 二分查找

### 💡 核心思想
在<span style="color: #FF6B6B; font-weight: bold;">有序数组</span>中使用分治策略，每次将搜索范围缩小一半，快速定位目标元素。

### 🎯 关键原则

> ⚠️ **循环不变量原则**：在二分查找过程中，始终保持区间定义的一致性，避免边界混乱

> 💭 **应用识别**：有序数组 + 查找问题 → 优先考虑二分查找（O(log n)）

### 📋 区间定义

<div style="background-color: #E8F5E9; border-left: 4px solid #4CAF50; padding: 12px; margin: 16px 0;">

**区间定义决定边界处理**：

| 区间类型 | 表示 | 循环条件 | 更新方式 | 特点 |
|---------|------|---------|---------|------|
| **左闭右闭** | `[left, right]` | `left <= right` | `right = mid - 1` | C++ 风格，推荐 |
| **左闭右开** | `[left, right)` | `left < right` | `right = mid` | Python 风格 |

> 💡 **循环不变量**：选定一种区间定义后，整个查找过程保持一致

</div>

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
使用两个指针在一个循环中协同工作，完成原本需要嵌套循环的任务，将时间复杂度从 **O(n²)** 优化为 **O(n)**。

> 🎯 **本质**：通过双指针在不同位置或不同速度移动，一次遍历解决问题

### 🎯 适用场景

| 场景类型 | 具体应用 | 时间复杂度 |
|---------|---------|-----------|
| 🗑️ **数组去重** | 移除重复元素、原地删除 | O(n) |
| 🔄 **数组移动** | 移除特定元素、元素移位 | O(n) |
| 🔗 **链表操作** | 环检测、中点查找、倒数第k个 | O(n) |
| 🔤 **字符串处理** | 回文判断、字符统计、反转 | O(n) |
| 🎯 **有序数组** | 两数之和、三数之和 | O(n) |

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

<div style="background-color: #FFF9E6; border-left: 4px solid #FFB900; padding: 12px; margin: 16px 0;">

**双指针类型**：
- 🏃 **快慢指针**：速度不同，常用于链表（环检测、中点）
  - 快指针每次移动 2 步，慢指针 1 步
  - 有环时快慢指针必然相遇
- 👈👉 **对撞指针**：从两端向中间，常用于有序数组
  - 左右指针相向而行
  - 通常用于查找、回文判断
- 🔄 **同向指针**：同方向不同速度，常用于数组操作
  - 一个指针负责遍历，一个负责处理
  - 原地修改、去重操作

**关键技巧**：
- ✅ 边界处理：注意空指针、单节点、空数组情况
- ✅ 循环条件：明确指针移动和循环终止条件
- ✅ 应用灵活：根据问题调整指针移动策略

</div>


## 🪟 滑动窗口

### 💡 核心思想
滑动窗口是一种基于**双指针**的高效算法，通过动态调节窗口的左右边界，维护一个满足条件的连续子序列。

**核心优势**：将暴力枚举所有子序列的 **O(n²)** 算法优化为 **O(n)**，根据窗口内元素状态动态调整边界。

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
- **窗口定义**：明确窗口边界是左闭右闭 `[left, right]` 还是左闭右开 `[left, right)`
- **指针协作**：`right` 扩大窗口，`left` 收缩窗口
- **状态维护**：实时更新窗口内的统计信息（和、计数、频次等）
- **边界处理**：考虑空数组、单元素等特殊情况
- **性能优化**：利用窗口连续性，避免重复计算

### 🔄 算法流程

<div style="background-color: #F3E5F5; border-left: 4px solid #9C27B0; padding: 12px; margin: 16px 0;">

**标准流程**：
```
1. 📌 初始化：left = 0, right = 0, 窗口状态（sum, count等）
2. ➡️ 扩大窗口：right 右移，将 nums[right] 加入窗口  
3. ✅ 判断条件：检查当前窗口是否满足题目条件
4. ⬅️ 收缩窗口：while 条件满足时，left 右移，更新状态
5. 📊 记录结果：更新最优解（最大值、最小值等）
6. 🔁 重复步骤 2-5 直到 right 到达数组末尾
```

**关键点**：
- 🎯 窗口的定义：`[left, right]` 或 `[left, right)`
- 🔄 状态维护：保持窗口内的统计信息（和、个数、频次等）
- ⚡ 时间优化：避免在窗口移动时重复计算

</div>

## 🎭 虚拟头节点技巧

### 💡 核心思想
在链表头部添加一个虚拟节点（dummy node），使头节点和其他节点的操作逻辑统一，消除特殊边界判断。

> ⚠️ **关键点**：返回结果时需要 `return dummyHead->next;`（返回真正的头节点）

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

<div style="background-color: #E1F5FE; border-left: 4px solid #03A9F4; padding: 12px; margin: 16px 0;">

**为什么需要虚拟头节点？**

❌ **不使用虚拟头节点**：
```cpp
// 需要特殊处理头节点
if (head->val == target) {
    head = head->next;  // 特殊处理
}
// 处理其他节点
ListNode* cur = head;
while (cur && cur->next) {
    if (cur->next->val == target) {
        cur->next = cur->next->next;
    }
}
```

✅ **使用虚拟头节点**：
```cpp
// 统一处理所有节点
ListNode* dummy = new ListNode(0);
dummy->next = head;
ListNode* cur = dummy;
while (cur->next) {
    if (cur->next->val == target) {
        cur->next = cur->next->next;
    } else {
        cur = cur->next;
    }
}
return dummy->next;  // 记得返回真正的头节点
```

**优势总结**：
- ✨ **统一逻辑**：头节点和其他节点处理方式完全一致
- 🎯 **简化代码**：避免复杂的边界条件判断和分支
- 🛡️ **减少错误**：降低空指针异常和边界问题
- 📖 **易于理解**：代码逻辑更清晰直观

</div>


## 🔢 哈希表

### 💡 核心思想
哈希表通过**哈希函数**将关键字映射到存储位置，实现 **O(1)** 平均时间复杂度的快速访问，是用空间换时间的典型数据结构。

### 🎯 适用场景

| 场景 | 应用 | 使用容器 |
|------|------|---------|
| 🔍 **快速查找** | 判断元素是否存在 | `unordered_set` |
| 🔢 **计数统计** | 统计频次、字符计数 | `unordered_map` |
| 🎯 **去重操作** | 数组去重、集合运算 | `set/unordered_set` |
| 🔗 **映射关系** | 建立键值对应 | `map/unordered_map` |
| 💾 **缓存实现** | LRU缓存、备忘录 | `unordered_map` |

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

<div style="background-color: #FFEBEE; border-left: 4px solid #F44336; padding: 12px; margin: 16px 0;">

**⚠️ 关键判断流程**：

```
1️⃣ 数据范围小且连续（如26个字母）？
   ✅ 使用数组：int arr[26]  → O(1) 空间最优
   
2️⃣ 只需要判断存在性/去重？
   ✅ 使用 unordered_set  → O(1) 查询最快
   
3️⃣ 需要键值对映射/计数统计？
   ✅ 使用 unordered_map  → O(1) 最常用
   
4️⃣ 需要有序遍历？
   ✅ 使用 set/map  → O(log n) 自动排序
```

**容器选择优先级**：
`unordered_set/map` > `set/map` > 数组 > 其他容器

</div>

### 🎯 使用建议

| 问题类型 | 首选方案 | 备选方案 | 适用场景 |
|---------|---------|---------|---------|
| 🔍 **存在性判断** | `unordered_set` | `set` | 快速查找元素是否存在 |
| 🔢 **频次统计** | `unordered_map` | `map` | 统计元素出现次数 |
| 📊 **有序遍历** | `set/map` | 排序+数组 | 需要按顺序处理数据 |
| 🎯 **固定范围** | 数组 | - | 26个字母、0-9数字等 |
| 🔄 **允许重复** | `multiset/multimap` | `vector` | 需要保留重复元素 |

**详细说明**：
- **集合问题**：优先使用 `unordered_set`（查询增删效率最优 O(1)）
  - 需要有序：使用 `set`（O(log n)）
  - 需要有序+重复数据：使用 `multiset`
- **映射问题**：优先使用 `unordered_map`（key-value结构，性能最优 O(1)）
  - 需要key有序：使用 `map`（O(log n)）
  - 需要key有序+可重复：使用 `multimap`

### 🔧 底层原理

| 实现方式 | 数据结构 | 时间复杂度 | 是否有序 | 特点 |
|---------|---------|-----------|---------|------|
| **哈希表** | 散列表 | O(1) | 无序 | 查询最快，空间换时间 |
| **红黑树** | 平衡二叉搜索树 | O(log n) | 有序 | 自动排序，key不可修改 |

**跨语言通用性**：
- C++: `unordered_map/set`（哈希表）、`map/set`（红黑树）
- Python: `dict/set`（哈希表）
- Go: `map`（哈希表）
- Java: `HashMap`（哈希表）、`TreeMap`（红黑树）

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

| 方面 | 关键技术 | 说明 |
|------|---------|------|
| 🎯 **哈希函数** | 均匀分布、计算高效 | 好的哈希函数减少冲突 |
| 🔧 **冲突处理** | 链地址法、开放定址法 | 解决多个key映射到同一位置 |
| 📊 **负载因子** | 保持在 0.75 以下 | 超过阈值需扩容，避免性能退化 |
| 🚀 **扩容机制** | 动态调整，rehash | 表满时自动扩容并重新映射 |
| 💾 **空间选择** | 小范围数组，大范围哈希表 | 根据数据范围权衡空间 |

### 🚀 性能优化建议

- **预分配容量**：已知数据量时，预先 `reserve()` 避免频繁扩容
- **选择合适容器**：根据是否需要有序、是否允许重复选择
- **优化哈希函数**：自定义类型需实现高质量哈希函数
- **控制负载因子**：及时扩容保持查询效率

## 📊 复杂度分析

### ⏱️ 时间复杂度对照表

| 复杂度 | 名称 | 典型算法 | 数据规模 | 性能表现 |
|--------|------|----------|----------|----------|
| O(1) | 常数 | 数组访问、哈希查询 | ∞ | ⭐⭐⭐⭐⭐ 最优 |
| O(log n) | 对数 | 二分查找、平衡树 | 10^8 | ⭐⭐⭐⭐ 优秀 |
| O(n) | 线性 | 遍历数组、遍历链表 | 10^6 | ⭐⭐⭐ 良好 |
| O(n log n) | 线性对数 | 快排、归并、堆排序 | 10^5 | ⭐⭐ 可接受 |
| O(n²) | 平方 | 冒泡、选择、插入排序 | 10^3 | ⭐ 较慢 |
| O(n³) | 立方 | 三重循环、Floyd | 10^2 | ⚠️ 很慢 |
| O(2^n) | 指数 | 回溯、子集枚举 | ≤25 | ❌ 极慢 |
| O(n!) | 阶乘 | 全排列、旅行商 | ≤10 | ❌ 不可用 |

<div style="background-color: #E8EAF6; border-left: 4px solid #3F51B5; padding: 12px; margin: 16px 0;">

**💡 数据规模与时间复杂度选择**：

- 📌 `n ≤ 10`：可以使用 O(n!) 或 O(2^n) 的算法
- 📌 `n ≤ 25`：可以使用 O(2^n) 的算法（如回溯、状态压缩DP）
- 📌 `n ≤ 100`：可以使用 O(n³) 的算法
- 📌 `n ≤ 1000`：可以使用 O(n²) 的算法
- 📌 `n ≤ 10^5`：需要 O(n log n) 或更好的算法
- 📌 `n ≤ 10^6`：需要 O(n) 或 O(n log n) 的算法
- 📌 `n > 10^6`：只能使用 O(n) 或 O(log n) 的算法

</div>

### 🔢 空间复杂度对照表

| 复杂度 | 名称 | 典型场景 | 说明 | 示例 |
|--------|------|----------|------|------|
| O(1) | 常数空间 | 原地算法 | 只使用有限个变量 | 双指针、位运算 |
| O(log n) | 对数空间 | 递归调用栈 | 二分递归、树的高度 | 二分查找递归版 |
| O(n) | 线性空间 | 额外数组 | 哈希表、动态数组 | 哈希表、DP数组 |
| O(n²) | 平方空间 | 二维数组 | 矩阵、图邻接矩阵 | 二维DP、图存储 |

---

## 🛠️ 解题技巧

### 📌 库函数使用原则

> ⚠️ **重要提醒**：打基础的时候，不要太迷恋于库函数！

<div style="background-color: #FFF3CD; border-left: 4px solid #FFA500; padding: 12px; margin: 16px 0;">

**常见误区**：
- 习惯性调用 `substr`、`split`、`reverse` 等库函数
- 不了解其内部实现原理
- 不清楚其时间复杂度

**面试风险**：面试官询问时间复杂度分析时会措手不及

</div>

### 🎓 字符串处理技巧

<div style="background-color: #E3F2FD; border-left: 4px solid #2196F3; padding: 12px; margin: 16px 0;">

**💡 技巧一：循环步长控制**

当需要按固定规律分段处理字符串时，在 `for` 循环的步长表达式上做文章。

```cpp
// 示例：每隔 2k 个字符处理前 k 个字符
for (int i = 0; i < s.length(); i += 2*k) {
    reverse(s.begin() + i, s.begin() + min(i + k, n));
}
```

**💡 技巧二：从后向前填充**

对字符串或数组做填充/删除操作时，优先考虑**从后向前**操作：
- ✅ **先扩容**：预先扩展到目标大小
- ✅ **后填充**：从后向前遍历填充，避免元素重复移动
- ✅ **时间优化**：O(n²) → O(n)

**适用场景**：
- 字符替换（如空格替换为 `%20`）
- 数组元素插入
- 合并两个有序数组

</div>

**✅ 库函数使用原则**：

| 场景 | 建议 | 判断标准 |
|------|------|---------|
| 🔴 **核心算法逻辑** | ❌ 不用库函数 | 题目考察的关键算法部分 |
| 🟢 **辅助工具函数** | ✅ 可以使用 | 非核心部分 + 清楚时间复杂度 |
| 🟡 **练习阶段** | 🤔 手写实现 | 学习期间应手写加深理解 |

> 💡 **核心原则**：理解底层原理 > 熟练使用库函数

### 🎯 问题类型识别

<div style="background-color: #FFF8E1; border-left: 4px solid #FFC107; padding: 12px; margin: 16px 0;">

**根据题目关键词快速识别算法类型**：

</div>

| 关键词 | 算法类型 | 常用技巧 | 时间复杂度 | 典型题目 |
|--------|----------|----------|-----------|---------|
| 🔍 **有序数组** | 二分查找 | 左右边界、搜索插入位置 | O(log n) | 搜索旋转数组 |
| 📏 **连续子数组** | 滑动窗口 | 固定窗口、可变窗口 | O(n) | 最小覆盖子串 |
| 👫 **数组操作** | 双指针 | 对撞指针、快慢指针 | O(n) | 三数之和 |
| 🔗 **链表操作** | 虚拟头节点 | 统一删除、简化插入 | O(n) | 删除链表节点 |
| 🔢 **查找/计数** | 哈希表 | set去重、map计数 | O(n) | 两数之和 |
| 🌳 **树形结构** | 递归/DFS | 前序、中序、后序遍历 | O(n) | 二叉树遍历 |
| 📊 **图/层级** | BFS | 队列、层序遍历 | O(n+m) | 最短路径 |
| 🔄 **排列组合** | 回溯算法 | 剪枝、状态回溯 | O(2^n) | 全排列 |
| 💰 **最优解** | 动态规划 | 状态转移、最优子结构 | O(n²) | 背包问题 |
| 🎯 **贪心选择** | 贪心算法 | 局部最优→全局最优 | O(n log n) | 区间调度 |

### 📝 算法识别口诀

```
有序数组想二分，连续子串滑窗口
数组去重双指针，链表操作加虚头
快速查找哈希表，计数统计用映射
树的遍历递归解，图的搜索DFS/BFS
最优子结构用DP，排列组合需回溯
局部最优贪心法，数据规模定复杂度
```

**记忆技巧**：见到关键词 → 联想算法类型 → 套用对应模板

### ⚡ 优化策略

| 优化方向 | 技巧 | 适用场景 | 效果 |
|---------|------|---------|------|
| 🎨 **空间换时间** | 哈希表缓存、前缀和预计算 | 频繁查询、重复计算 | O(n²) → O(n) |
| ⏰ **预处理优化** | 数据排序、建立索引、预计算 | 多次查询、静态数据 | 查询 O(1) |
| 🔢 **位运算技巧** | 状态压缩、快速幂、掩码操作 | 集合操作、状态表示 | 空间优化 |
| 🪟 **区间优化** | 滑动窗口、双指针、单调队列 | 连续子数组问题 | O(n²) → O(n) |
| ✂️ **剪枝策略** | 提前返回、条件过滤、边界处理 | 搜索、回溯 | 减少搜索空间 |
| 📝 **记忆化搜索** | 递归缓存、DP数组 | 重叠子问题 | 指数 → 多项式 |

### 🧠 解题思维模式

<div style="background-color: #F3E5F5; border-left: 4px solid #9C27B0; padding: 12px; margin: 16px 0;">

**完整的解题流程**：

```
┌─────────────────────────────────────────────────┐
│ 1️⃣ 理解题意 - Understand                        │
├─────────────────────────────────────────────────┤
│ ✓ 明确输入输出格式                                │
│ ✓ 理解题目约束条件和边界情况                        │
│ ✓ 手动模拟几个测试用例                             │
└─────────────────────────────────────────────────┘
              ↓
┌─────────────────────────────────────────────────┐
│ 2️⃣ 识别模式 - Pattern Recognition               │
├─────────────────────────────────────────────────┤
│ ✓ 根据关键词识别算法类型                           │
│ ✓ 评估数据规模，选择合适时间复杂度                   │
│ ✓ 回忆类似题目的解法                               │
└─────────────────────────────────────────────────┘
              ↓
┌─────────────────────────────────────────────────┐
│ 3️⃣ 设计算法 - Algorithm Design                  │
├─────────────────────────────────────────────────┤
│ ✓ 选择合适的数据结构                               │
│ ✓ 设计核心算法逻辑                                 │
│ ✓ 考虑边界条件处理                                 │
└─────────────────────────────────────────────────┘
              ↓
┌─────────────────────────────────────────────────┐
│ 4️⃣ 编码实现 - Implementation                     │
├─────────────────────────────────────────────────┤
│ ✓ 使用清晰的变量命名                               │
│ ✓ 添加必要的注释                                   │
│ ✓ 处理特殊情况和边界                               │
└─────────────────────────────────────────────────┘
              ↓
┌─────────────────────────────────────────────────┐
│ 5️⃣ 测试验证 - Test & Verify                      │
├─────────────────────────────────────────────────┤
│ ✓ 正常用例测试                                     │
│ ✓ 边界用例测试（空、单元素、最大值）                 │
│ ✓ 时空复杂度分析                                   │
└─────────────────────────────────────────────────┘
              ↓
┌─────────────────────────────────────────────────┐
│ 6️⃣ 优化改进 - Optimize                           │
├─────────────────────────────────────────────────┤
│ ✓ 分析性能瓶颈                                     │
│ ✓ 考虑空间换时间                                   │
│ ✓ 简化代码逻辑                                     │
└─────────────────────────────────────────────────┘
```

**💡 解题心法**：
- ✅ 先思考后编码：理解题意 → 设计算法 → 验证可行性 → 开始编码
- ✅ 从简到优：先想暴力解法，明确瓶颈，再优化时间/空间复杂度
- ✅ 复杂度先行：明确数据规模，选择合适的时间复杂度
- ✅ 模式积累：多总结归纳，建立解题模式库

</div>

---

<div align="center">

## 🎉 Happy Coding! 🎉

> 💭 *"算法学习重在思维，而非死记硬背"*  
> 🚀 *"Practice makes perfect - 熟能生巧，坚持进步"*  
> 📖 *"学而不思则罔，思而不学则殆 - 理论与实践并重"*

### 📊 笔记统计

| 📝 核心专题 | 🔧 算法模板 | 📚 题目覆盖 | ⏰ 持续更新 |
|:----------:|:----------:|:----------:|:----------:|
| **4+ 专题** | **30+ 模板** | **100+ 题目** | **每周更新** |

<p align="center">
  <img src="https://img.shields.io/badge/Made%20with-❤️-red?style=for-the-badge" alt="Made with Love">
  <img src="https://img.shields.io/badge/Language-C++%20|%20Python%20|%20Go-blue?style=for-the-badge" alt="Languages">
  <img src="https://img.shields.io/badge/Last%20Updated-2025--11--07-green?style=for-the-badge" alt="Last Updated">
</p>

---

### 📈 内容概览

```
📚 核心算法专题
├── 🔍 二分查找 - 2 个模板
├── 👫 双指针技术 - 3 个模板（快慢指针、对撞指针、同向指针）
├── 🪟 滑动窗口 - 3 个模板（固定窗口、最小长度、最大长度）
├── 🎭 虚拟头节点 - 链表操作必备技巧
├── 🔢 哈希表 - 4 个模板（数组、集合、映射、字符串）
├── 📊 复杂度分析 - 时间空间复杂度速查表
└── 🛠️ 解题技巧 - 问题识别、优化策略、思维模式

🎯 覆盖内容
├── 基础算法：二分、双指针、滑动窗口
├── 数据结构：数组、链表、哈希表、树、图
├── 进阶技巧：动态规划、回溯、贪心、位运算
└── 实战经验：复杂度分析、问题识别、代码优化
```

### ⭐ 支持项目

<div style="background-color: #E8F5E9; border: 2px solid #4CAF50; border-radius: 8px; padding: 20px; margin: 20px 0;">

如果这份笔记对你有帮助，欢迎：

| 行动 | 说明 |
|:----:|:-----|
| 🌟 | **Star** - 给个星标支持一下，这是对我最大的鼓励！ |
| 🔀 | **Fork** - Fork 并添加你的笔记，一起完善内容 |
| 💬 | **Issue** - 提出问题或建议，帮助改进笔记质量 |
| 📢 | **Share** - 分享给更多需要的人，让更多人受益 |
| 🤝 | **Contribute** - 贡献你的解题思路和代码优化 |

> 💡 **温馨提示**：这份笔记会持续更新，建议 Watch 本项目以获取最新内容

</div>

---

<p align="center">
  <strong>⚡ 持续学习，不断进步！⚡</strong><br>
  <em>每天进步一点点，坚持就是胜利</em>
</p>

</div>