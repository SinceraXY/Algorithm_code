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
    bool compare(TreeNode*left, TreeNode*right){
        //首先排除空节点的情况
        if(left==NULL&&right!=NULL) return false;
        else if(left!=NULL&&right==NULL) return false;
        else if(left==NULL&&right==NULL) return true;
        //再排除数值不相同的情况
        else if(left->val!=right->val) return false;

        //数值相同才做递归，做下一层的判断
        bool outside=compare(left->left,right->right);
        bool inside=compare(left->right,right->left);
        bool isSame=outside && inside;
        return isSame;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return compare(root->left,root->right);
    }
};



//迭代法(使用队列)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode*>que;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()){
            TreeNode*leftNode=que.front();
            que.pop();
            TreeNode*rightNode=que.front();
            que.pop();
            if(!leftNode && !rightNode){   //左节点为空、右节点为空，说明是对称的
                continue;
            }
            //左右一个节点不为空，或者都不为空但数值不相同，返回false
            if((!leftNode||!rightNode||(leftNode->val!=rightNode->val))){
                return false;
            }
            
            que.push(leftNode->left);
            que.push(rightNode->right);
            que.push(leftNode->right);
            que.push(rightNode->left);
        }
        return true;
    }
};



//迭代法(使用栈)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        stack<TreeNode*>st;
        st.push(root->left);
        st.push(root->right);
        while(!st.empty()){
            TreeNode*leftNode=st.top();
            st.pop();
            TreeNode*rightNode=st.top();
            st.pop();
            if(!leftNode&&!rightNode)
            {
                continue;
            }
            if(!leftNode||!rightNode||(leftNode->val!=rightNode->val)){
                return false;
            }
            st.push(leftNode->left);
            st.push(rightNode->right);
            st.push(leftNode->right);
            st.push(rightNode->left);
        }
        return true;
    }
};