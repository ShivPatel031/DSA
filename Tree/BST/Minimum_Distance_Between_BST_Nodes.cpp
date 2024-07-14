// Minimum Distance Between BST Nodes leetcode 783 530

// Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

// Example 1:

// Input: root = [4,2,6,1,3]
// Output: 1
  
// Example 2:

// Input: root = [1,0,48,null,null,12,49]
// Output: 1

// Constraints:

// The number of nodes in the tree is in the range [2, 100].
// 0 <= Node.val <= 105

void helper(TreeNode* root,int &m,int &prev)
{
    if(!root) return;

    helper(root->left,m,prev);

    if(prev!=INT_MIN)  m=min(m,root->val-prev);

    prev=root->val;

    helper(root->right,m,prev);
}

int minDiffInBST(TreeNode* root) 
{
    int min = INT_MAX;
    int prev=INT_MIN;

    helper(root,min,prev);

    return min;    
}
