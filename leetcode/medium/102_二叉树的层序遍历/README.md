# 102. 二叉树的层序遍历

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
- **难度**：Medium
- **标签**：树、广度优先搜索、二叉树

## 题目描述

给你二叉树的根节点 `root` ，返回其节点值的 **层序遍历** 。 （即逐层地，从左到右访问所有节点）。

## 示例

**示例 1：**
![示例图](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)
```
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]
```

**示例 2：**
```
输入：root = [1]
输出：[[1]]
```

**示例 3：**
```
输入：root = []
输出：[]
```

## 解题思路

### 方法一：迭代（广度优先搜索 BFS）

#### 思路与算法

层序遍历要求我们按照层级从上到下、每层从左到右访问节点。这天然符合**广度优先搜索（BFS）**的特点。

具体实现时，我们使用一个**队列**来辅助：
1. 首先将根节点 `root` 入队。
2. 当队列不为空时，进行循环：
   - 获取当前队列的长度 `size`，这代表当前层级的节点数量。
   - 连续弹出 `size` 个节点，并将它们的值存入当前层的搜索结果中。
   - 在弹出每个节点的同时，如果它有左/右孩子，则按顺序将孩子节点入队。
3. 当队列为空时，遍历结束。

### 方法二：递归（深度优先搜索 DFS）

#### 思路与算法

虽然层序遍历通常使用 BFS，但也可以使用 DFS 实现。

关键点在于：在递归过程中记录当前节点的**层级（level）**：
1. 传入当前节点和对应的 `level`（根节点为 0）。
2. 如果结果数组的长度等于 `level`，说明是第一次进入该层，需要新建一个子数组。
3. 将当前节点的值加入到结果数组中索引为 `level` 的子数组里。
4. 递归处理左孩子和右孩子，层级设为 `level + 1`。

## 代码实现

### C++

#### 迭代（队列实现）

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        vector<vector<int>> result;
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是变化的
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};
```

### Python

详见 [102_二叉树的层序遍历.py](./102_二叉树的层序遍历.py)

### Go

详见 [102_二叉树的层序遍历.go](./102_二叉树的层序遍历.go)

## 复杂度分析

设节点数为 `n`。

- **时间复杂度**：每个点进队出队各一次，故渐进时间复杂度为 $O(n)$。
- **空间复杂度**：队列中元素的个数不超过 $n$ 个，故渐进空间复杂度为 $O(n)$。

## 关键点

1. **BFS 核心**：使用队列，并利用 `size` 变量控制每一层节点的处理边界。
2. **DFS 技巧**：通过传递 `level` 参数，将节点值分发到正确的层级结果中。