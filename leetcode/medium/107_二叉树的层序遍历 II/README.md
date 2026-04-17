# 107. 二叉树的层序遍历 II

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/description/
- **难度**：Medium
- **标签**：树、广度优先搜索、二叉树

## 题目描述

给你二叉树的根节点 `root` ，返回其节点值 **自底向上的层序遍历** 。 （即按从叶子节点所在层到根节点所在层，逐层从左向右遍历）。

## 示例

**示例 1：**
![示例图](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)
```
输入：root = [3,9,20,null,null,15,7]
输出：[[15,7],[9,20],[3]]
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

### 方法一：迭代（广度优先搜索 BFS + 结果反转）

#### 思路与算法

本题是 [102. 二叉树的层序遍历](../102_%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86/README.md) 的变体。

1. **常规层序遍历**：使用队列按层访问节点，得到 `[[第1层], [第2层], ..., [第n层]]`。
2. **反转结果**：将得到的二维数组进行反转，即可得到 `[[第n层], ..., [第2层], [第1层]]`。

在 C++ 中可以使用 `std::reverse`，Python 中使用 `[::-1]`，Go 中则手动交换首尾元素。

## 代码实现

### C++

```cpp
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        vector<vector<int>> result;
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
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
        // 关键步骤：反转结果数组
        reverse(result.begin(), result.end());
        return result;
    }
};
```

### Python

详见 [107_二叉树的层序遍历 II.py](./107_二叉树的层序遍历%20II.py)

### Go

详见 [107_二叉树的层序遍历 II.go](./107_二叉树的层序遍历%20II.go)

## 复杂度分析

设节点数为 `n`。

- **时间复杂度**：$O(n)$，其中 $n$ 是二叉树中的节点个数。每个节点访问一次，结果列表使用链表的结构时，在结果列表头部添加一层节点值的列表的时间复杂度是 $O(1)$，因此总时间复杂度是 $O(n)$。
- **空间复杂度**：$O(n)$，其中 $n$ 是二叉树中的节点个数。空间复杂度取决于队列开销，队列中的节点个数不会超过 $n$。

## 关键点

1. **层序遍历基础**：熟练掌握使用队列进行 BFS 的模板。
2. **结果处理**：在得到正常的层序遍历结果后，进行一次 `reverse` 操作即可满足“自底向上”的要求。