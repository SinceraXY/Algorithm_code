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

//递归法
class Solution {
public:
    int getDepth(TreeNode* node) {
        if(node==NULL) return 0;
        int leftDepth=getDepth(node->left);
        int rightDepth=getDepth(node->right);

        if(node->left==NULL&&node->right!=NULL){
            return 1 + rightDepth;
        }
        if(node->left!=NULL&&node->right==NULL){
            return 1 + leftDepth;
        }
        int result= 1 + min(leftDepth,rightDepth);
        return result;
    }
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};



//迭代法
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            depth++;
            int flag=0;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                if(!node->left&&!node->right)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
        }
        return depth;
    }
};