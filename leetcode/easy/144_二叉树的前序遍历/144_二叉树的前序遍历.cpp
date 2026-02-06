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
public:
    void preorder(TreeNode *root, vector<int> &res) {
        if(root==nullptr){
            return;
        }
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};



//迭代
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr){
            return res;
        }

        stack<TreeNode*> stk;
        TreeNode* node = root;
        while(!stk.empty()||node!=nullptr) {
            while(node!=nullptr) {
                res.emplace_back(node->val);
                stk.emplace(node);
                node=node->left;
            }
            node=stk.top();
            stk.pop();
            node=node->right;
        }
        return res;
    }
};



//Morris遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        TreeNode *p1 = root, *p2 = nullptr;

        while (p1 != nullptr) {
            p2 = p1->left;
            if (p2 != nullptr) {
                while (p2->right != nullptr && p2->right != p1) {
                    p2 = p2->right;
                }
                if (p2->right == nullptr) {
                    res.emplace_back(p1->val);
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    p2->right = nullptr;
                }
            } else {
                res.emplace_back(p1->val);
            }
            p1 = p1->right;
        }
        return res;
    }
};