/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//递归
class Solution {
private:
    int getNodesNum(TreeNode* cur) {
        if(cur==0) return 0;
        int leftNum=getNodesNum(cur->left);
        int rightNum=getNodesNum(cur->right);
        int treeNum=leftNum+rightNum+1;
        return treeNum;
    }
public:
    int countNodes(TreeNode* root) {
        return getNodesNum(root);
    }
};



//迭代法
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*>que;
        if(root!=NULL) que.push(root);
        int result=0;
        while(!que.empty()) {
            int size=que.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node = que.front();
                que.pop();
                result++;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return result;
    }
};