# 226. 翻转二叉树

- **平台**：LeetCode
- **链接**：https://leetcode.cn/problems/invert-binary-tree/description/
- **难度**：Easy
- **标签**：树、深度优先搜索、广度优先搜索、二叉树

## 题目描述

给你一棵二叉树的根节点 `root` ，翻转这棵二叉树，并返回其根节点。

## 示例

**示例 1：**
```
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
```

**示例 2：**
```
输入：root = [2,1,3]
输出：[2,3,1]
```

**示例 3：**
```
输入：root = []
输出：[]
```

## 解题思路

### 方法一：递归（DFS）

#### 思路与算法

对每个节点做同样的事情：交换它的左、右子树，然后递归处理它的左右孩子。

### 方法二：迭代（栈）

#### 思路与算法

用栈模拟递归的调用过程：每弹出一个节点，就交换其左右子树，然后把（交换后的）左右孩子入栈继续处理。

### 方法三：统一迭代法（标记法）

#### 思路与算法

使用 `NULL` 指针作为标记，将“遍历节点”和“处理节点（交换左右孩子）”的动作分离。

当弹出 `NULL` 时，说明下一个弹出的节点是待处理节点，此时执行 `swap(node->left, node->right)`。

### 方法四：层序遍历（队列 BFS）

#### 思路与算法

按层遍历二叉树。访问到一个节点就交换其左右子树，然后将其左右孩子入队，直到队列为空。

## 代码实现

### C++

#### 递归法

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        swap(root->left,root->right);    //中
        invertTree(root->left);          //左
        invertTree(root->right);         //右
        return root;
    }
};
```

#### 迭代法（栈）

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();              //中
            st.pop();
            swap(node->left, node->right);
            if(node->right) st.push(node->right);   //右
            if(node->left) st.push(node->left);     //左
        }
        return root;
    }
};
```

#### 统一写法迭代法（标记法）

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                if (node->right) st.push(node->right);  //右
                if (node->left) st.push(node->left);    //左
                st.push(node);                          //中
                st.push(NULL);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                swap(node->left, node->right);          //节点处理逻辑
            }
        }
        return root;
    }
};
```

#### 层序遍历（队列）

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right);        //节点处理
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return root;
    }
};
```

### Python

详见 [226_翻转二叉树.py](./226_翻转二叉树.py)

### Go

详见 [226_翻转二叉树.go](./226_翻转二叉树.go)

## 复杂度分析

### 递归法

时间复杂度：O(N)，其中 N 为二叉树节点的数目。我们会遍历二叉树中的每一个节点，对每个节点而言，我们在常数时间内交换其两棵子树。

空间复杂度：O(N)。使用的空间由递归栈的深度决定，它等于当前节点在二叉树中的高度。在平均情况下，二叉树的高度与节点个数为对数关系，即 O(logN)。而在最坏情况下，树形成链状，空间复杂度为 O(N)。

### 迭代法（栈）/统一迭代法（标记法）

- **时间复杂度**：`O(N)`，每个节点都会被访问并交换一次。
- **空间复杂度**：`O(N)`，栈在最坏情况下会存下整条链。

### 层序遍历（队列）

- **时间复杂度**：`O(N)`。
- **空间复杂度**：`O(N)`，队列在最坏情况下可能存放同一层的所有节点。

## 关键点

1. 本题的节点“处理逻辑”就是交换 `left` 与 `right`。
2. 递归与迭代的差别在于：递归使用系统调用栈，迭代使用显式栈/队列。
3. 统一迭代法通过 `NULL` 标记将“遍历”和“处理”分离，模板更通用。