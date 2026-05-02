# 515. 在每个树行中找最大值

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/
- **难度**：Medium
- **标签**：树、深度优先搜索、广度优先搜索、二叉树
 
## 题目描述

给定一棵二叉树的根节点 `root` ，请找出该二叉树中每一层最大值。

## 示例

**示例 1：**
![示例图](https://assets.leetcode.com/uploads/2020/08/21/largest_e1.jpg)
```
输入: root = [1,3,2,5,3,null,9]
输出: [1,3,9]
```

**示例 2：**
```
输入: root = [1,2,3]
输出: [1,3]
```

## 解题思路

### 方法一：广度优先搜索（BFS）

#### 思路与算法

层序遍历是解决这类“每一层”问题的直观方法。使用队列保存当前层的所有节点，在处理每一层时，初始化一个当前层的最大值 `maxVal`，遍历完该层所有节点后，将 `maxVal` 加入结果集。

### 方法二：深度优先搜索（DFS）

#### 思路与算法

在深度优先搜索时，我们需要记录当前节点的层级 `curHeight`。
1. 如果 `curHeight` 等于当前结果集 `res` 的大小，说明这是该层访问的第一个节点，直接将其值加入结果集。
2. 否则，将当前节点的值与结果集中对应层级的最大值进行比较并更新。

## 代码实现

### C++

#### 深度优先搜索

```cpp
class Solution {
public:
    void dfs(vector<int>& res, TreeNode* root, int curHeight) {
        if (curHeight == res.size()) {
            res.push_back(root->val);
        } else {
            res[curHeight] = max(res[curHeight], root->val);
        }
        if (root->left) dfs(res, root->left, curHeight + 1);
        if (root->right) dfs(res, root->right, curHeight + 1);
    }

    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        dfs(res, root, 0);
        return res;
    }
};
```

#### 广度优先搜索

```cpp
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            int maxVal = INT_MIN;
            while (len > 0) {
                len--;
                auto t = q.front();
                q.pop();
                maxVal = max(maxVal, t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(maxVal);
        }
        return res;
    }
};
```

### Python

详见 [515_在每个树行中找最大值.py](./515_在每个树行中找最大值.py)

### Go

详见 [515_在每个树行中找最大值.go](./515_在每个树行中找最大值.go)

## 复杂度分析

### 深度优先搜索复杂度分析

时间复杂度：O(n)，其中 n 为二叉树节点个数。二叉树的遍历中每个节点会被访问一次且只会被访问一次。

空间复杂度：O(height)。其中 height 表示二叉树的高度。递归函数需要栈空间，而栈空间取决于递归的深度，因此空间复杂度等价于二叉树的高度。

### 广度优先搜索复杂度分析

时间复杂度：O(n)，其中 n 为二叉树节点个数，每一个节点仅会进出队列一次。

空间复杂度：O(n)，存储二叉树节点的空间开销。

## 关键点

1. **BFS**：利用队列层序遍历，处理每一层时维护局部最大值。
2. **DFS**：利用结果数组的长度判断是否是新的一层，并在递归过程中不断更新对应层的最大值。