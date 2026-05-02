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

//深度优先搜索
class Solution {
public:
    void dfs(vector<int>& res, TreeNode* root, int curHeight) {
        if (curHeight==res.size()){
            res.push_back(root->val);
        } else {
            res[curHeight]=max(res[curHeight], root->val);
        }
        if(root->left){
            dfs(res, root->left, curHeight+1);
        }
        if(root->right){
            dfs(res, root->right, curHeight+1);
        }
    }
    vector<int> largestValues(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> res;
        dfs(res, root, 0);
        return res;
    }
};



//广度优先搜索
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int len = q.size();
            int maxVal = INT_MIN;
            while(len>0)
            {
                len--;
                auto t = q.front();
                q.pop();
                maxVal = max(maxVal, t->val);
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            res.push_back(maxVal);
        }
        return res;
    }
};