# 429. N 叉树的层序遍历

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/
- **难度**：Medium
- **标签**：树、广度优先搜索

## 题目描述

给定一个 N 叉树，返回其节点值的 **层序遍历** 。

N 叉树在输入中按层序遍历进行序列化表示，每组子节点由 `null` 值分隔。

## 示例

**示例 1：**
```
输入：root = [1,null,3,2,4,null,5,6]
输出：[[1],[3,2,4],[5,6]]
```

**示例 2：**
```
输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
```

## 解题思路

### 方法一：迭代（广度优先搜索 BFS）

#### 思路与算法

层序遍历天然适合用 BFS。

1. 使用队列存放当前层待遍历的节点。
2. 每次循环前记录当前队列长度 `size`，表示当前层节点数。
3. 依次弹出 `size` 个节点，将它们的值加入当前层数组，并把它们的所有子节点依次入队。
4. 当前层遍历完成后，将层数组加入最终结果。

## 代码实现

### C++

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        if (root != NULL) que.push(root);
        vector<vector<int>> result;
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                vec.push_back(node->val);
                for (int i = 0; i < node->children.size(); i++) {
                    if (node->children[i]) que.push(node->children[i]);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};
```

### Python

详见 [429_N 叉树的层序遍历.py](./429_N%20叉树的层序遍历.py)

### Go

详见 [429_N 叉树的层序遍历.go](./429_N%20叉树的层序遍历.go)

## 复杂度分析

时间复杂度：O(n)，其中 n 是树中包含的节点个数。在广度优先搜索的过程中，我们需要遍历每一个节点恰好一次。

空间复杂度：O(n)，即为队列需要使用的空间。在最坏的情况下，树只有两层，且最后一层有 n−1 个节点，此时就需要 O(n) 的空间。

## 关键点

1. BFS 分层遍历时，一定要先记录固定的 `size`，用来界定当前层的节点范围。
2. N 叉树节点的孩子是一个列表/数组，遍历时将所有孩子依次入队。