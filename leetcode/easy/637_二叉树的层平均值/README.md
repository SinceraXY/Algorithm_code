# 637. 二叉树的层平均值

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/average-of-levels-in-binary-tree/description/
- **难度**：Easy
- **标签**：树、深度优先搜索、广度优先搜索、二叉树

## 题目描述

给定一个非空二叉树的根节点 `root`，以数组的形式返回每一层节点值的平均值。与实际答案相差 `10^-5` 以内的结果可以被接受。

## 示例

**示例 1：**
```
输入：root = [3,9,20,null,null,15,7]
输出：[3.00000,14.50000,11.00000]
解释：第 0 层平均值为 3，第 1 层平均值为 (9+20)/2 = 14.5，第 2 层平均值为 (15+7)/2 = 11。
```

**示例 2：**
```
输入：root = [3,9,20,15,7]
输出：[3.00000,14.50000,11.00000]
```

## 解题思路

### 方法一：迭代（广度优先搜索 BFS）

#### 思路与算法

按层遍历二叉树，每层统计其节点值之和与节点个数，即可得到该层的平均值。

1. 使用队列进行层序遍历。
2. 每次循环前记录当前队列长度 `size`（当前层节点数）。
3. 弹出 `size` 个节点：累加它们的值 `sum`，并将其左右孩子入队。
4. 本层遍历结束后，将 `sum / size` 加入答案。

## 代码实现

### C++

```cpp
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        if(root!=NULL) que.push(root);
        vector<double>result;
        while(!que.empty()) {
            int size = que.size();
            double sum = 0;     //统计每一层的和
            for(int i =0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                sum+=node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(sum/size);   //将每一层均值放进结果集
        }
        return result;
    }
};
```

### Python

详见 [637_二叉树的层平均值.py](./637_二叉树的层平均值.py)

### Go

详见 [637_二叉树的层平均值.go](./637_二叉树的层平均值.go)

## 复杂度分析

时间复杂度：O(n)，其中 n 是二叉树中的节点个数。
广度优先搜索需要对每个节点访问一次，时间复杂度是 O(n)。
需要对二叉树的每一层计算平均值，时间复杂度是 O(h)，其中 h 是二叉树的高度，任何情况下都满足 h≤n。
因此总时间复杂度是 O(n)。

空间复杂度：O(n)，其中 n 是二叉树中的节点个数。空间复杂度取决于队列开销，队列中的节点个数不会超过 n。

## 关键点

1. 分层遍历时必须先保存固定的 `size`，用来界定当前层的节点范围。
2. `sum` 使用 `double`（或在 Python 中使用 `float`）避免整除与精度问题。