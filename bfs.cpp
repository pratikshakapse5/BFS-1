//implemented BFS for level order traversal
//TIme : O(N)
//Space: O(N)


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
    vector<vector<int>> res;
    vector<int> temp;
        
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)
            return res;
        bfs(root);
        return res;
    }
    void bfs(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left!=nullptr)
                    q.push(node->left);
                if(node->right!=nullptr)
                    q.push(node->right);
            }
            res.push_back(temp);
            temp.clear();
        }
    }
};
