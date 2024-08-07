// Maximum Level Sum of a Binary Tree leetcode 1161 GFG

// Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

// Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

// Example 1:

// Input: root = [1,7,0,7,-8,null,null]
// Output: 2
// Explanation: 
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
// So we return the level with the maximum sum which is level 2.
  
// Example 2:

// Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
// Output: 2

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -105 <= Node.val <= 105

int maxLevelSum(TreeNode* root) 
{
    int ans=INT_MIN,level = 0,anslevel;

    if(!root) return ans;

    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty())
    {
        int count=q.size();
        int max=0;
        level++;
        
        while(count--)
        {
            TreeNode *temp=q.front();
            q.pop();

            max+=temp->val;

            if(temp->left) q.push(temp->left);

            if(temp->right) q.push(temp->right);
        }

        if(ans<max){
            ans=max;
            anslevel=level;
        }
    }

    return anslevel;
}
