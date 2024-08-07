// Sum of Left Leaves leetcode 404 GFG

// Given the root of a binary tree, return the sum of all left leaves.

// A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
  
// Example 2:

// Input: root = [1]
// Output: 0
 
// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -1000 <= Node.val <= 1000

// using one function
int sumOfLeftLeaves(TreeNode* root) 
{
    if(!root) return 0;
    int sum=0;
    
    if(root->left && !root->left->left && !root->left->right)
    {
        sum+=root->left->val;
    }
    sum+=sumOfLeftLeaves(root->left);
    sum+=sumOfLeftLeaves(root->right);

    return sum;
}

// using two function
void leftLeavesSum(TreeNode *root,int &count)
{
    if(!root) return;

    if(root->left)
    {
        if(!root->left->left && !root->left->right)
        {
            count+=root->left->val;
        }
    }

    leftLeavesSum(root->left,count);
    leftLeavesSum(root->right,count);
}
int sumOfLeftLeaves(TreeNode* root) 
{
    int count =0;

    leftLeavesSum(root,count);

    return count;
}
