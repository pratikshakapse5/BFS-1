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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)
            return {};

        vector<vector<int>> ans;
       
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* front;
        while(!q.empty())
        {   
             vector<int> temp;
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                front=q.front(); q.pop();
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);

                    temp.push_back(front->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};