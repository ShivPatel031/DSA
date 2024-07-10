// Binary Tree Level Order Traversal II leetcode 107

// Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: [[15,7],[9,20],[3]]
  
// Example 2:

// Input: root = [1]
// Output: [[1]]
  
// Example 3:

// Input: root = []
// Output: []
 
// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000

vector<vector<int>> levelOrderBottom(TreeNode* root) 
{
    vector<vector<int> > ans;

    if(!root) return ans;

    queue<TreeNode *> q;
    int count = 0;

    q.push(root); 

    while(!q.empty())
    {
        count=q.size();
        vector<int> t;

        while(count--)
        {
            TreeNode *temp = q.front();
            q.pop();

            t.push_back(temp->val);

            if(temp->left) q.push(temp->left);

            if(temp->right) q.push(temp->right);
        }

        ans.push_back(t);
    }

    reverse(ans.begin(),ans.end());

    return ans;   
}
