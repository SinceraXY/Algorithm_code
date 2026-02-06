# 94. 二叉树的中序遍历

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
- **难度**：Easy
- **标签**：栈、树、深度优先搜索、二叉树

## 题目描述

给你二叉树的根节点 `root` ，返回它节点值的 **中序遍历** 结果。

中序遍历顺序：`左 -> 根 -> 右`。

## 示例

**示例 1：**
```
输入：root = [1,null,2,3]
输出：[1,3,2]
```

**示例 2：**
```
输入：root = []
输出：[]
```

**示例 3：**
```
输入：root = [1]
输出：[1]
```

## 解题思路

### 方法一：递归（DFS）

#### 思路与算法

中序遍历的顺序是“左子树 -> 根节点 -> 右子树”。当遍历到任意节点 `root` 时：

1. 递归遍历 `root.left`
2. 将 `root.val` 加入结果
3. 递归遍历 `root.right`

递归终止条件：当前节点为空。

### 方法二：迭代（显式栈模拟递归）

#### 思路与算法

递归遍历时，系统会隐式维护一条从根到当前节点的路径栈。迭代写法本质上是把这个“隐式栈”改为“显式栈”。

做法是：

1. 沿着左孩子不断向下，把路径节点依次入栈；
2. 当左侧走到底后弹栈，访问该节点（这是中序的“根”位置）；
3. 再转向其右子树，重复以上过程。

### 方法三：Morris 遍历（进阶，O(1) 额外空间）

#### 思路与算法

Morris 中序遍历利用树中的空闲指针建立临时线索，从而避免显式栈。

对当前节点 `root`：

1. 如果 `root.left` 为空：直接访问 `root`，然后 `root = root.right`。
2. 如果 `root.left` 不为空：找到 `root` 的中序前驱 `predecessor`（左子树最右节点）。
   - 若 `predecessor.right` 为空：令 `predecessor.right = root` 建立线索，并令 `root = root.left` 继续遍历左子树。
   - 若 `predecessor.right == root`：说明左子树已遍历完，先访问 `root`，再恢复 `predecessor.right = nullptr`，并令 `root = root.right`。

## 代码实现

### C++

#### 递归

```cpp
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};
```

#### 迭代（栈）

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};
```

#### Morris 遍历

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                
                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                else {
                    res.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
```

### Python

详见 [94_二叉树的中序遍历.py](./94_二叉树的中序遍历.py)

### Go

详见 [94_二叉树的中序遍历.go](./94_二叉树的中序遍历.go)

## 复杂度分析

设节点数为 `n`，树高为 `h`。

- **方法一（递归）**：
  - 时间复杂度：`O(n)`，每个节点恰好被遍历一次。
  - 空间复杂度：`O(h)`，为递归调用栈的开销；平均情况下为 `O(log n)`，最坏情况下树呈链状为 `O(n)`。
- **方法二（迭代）**：
  - 时间复杂度：`O(n)`，每个节点恰好被遍历一次。
  - 空间复杂度：`O(h)`，为显式栈的开销；平均情况下为 `O(log n)`，最坏情况下树呈链状为 `O(n)`。
- **方法三（Morris）**：
  - 时间复杂度：`O(n)`，建立/恢复线索会让部分节点被处理多次，但总次数仍为线性级别。
  - 空间复杂度：`O(1)`，只操作树上已有指针，额外空间为常数。

## 关键点

1. 中序遍历顺序固定为：**左 -> 根 -> 右**。
2. 迭代写法的关键是“先一路入栈走到最左，再出栈访问，再转向右子树”。
3. Morris 遍历会临时修改指针（建立线索），遍历结束时需要恢复原结构。