# 📚 核心笔记 (Core Notes)

> *一份系统化的算法学习笔记，助力编程面试和竞赛准备*

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

---

## 🛠️ 解题技巧

### 🎯 识别模式
- **🔍 有序数组** → 二分查找
- **📏 子数组问题** → 滑动窗口、前缀和
- **🔄 排列组合** → 回溯算法
- **💰 最优化问题** → 动态规划、贪心

### ⚡ 优化技巧
- **🎨 空间换时间**：哈希表、前缀和
- **⏰ 预处理**：排序、预计算
- **🔢 位运算**：状态压缩、快速计算

---

<div align="center">

**🎉 Happy Coding! 🎉**

*最后更新：2025-08-13*

</div>