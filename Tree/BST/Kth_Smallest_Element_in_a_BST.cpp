// Kth Smallest Element in a BST leetcode 230 GFG

// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

// Example 1:

// Input: root = [3,1,4,null,2], k = 1
// Output: 1
  
// Example 2:

// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3
 
// Constraints:

// The number of nodes in the tree is n.
// 1 <= k <= n <= 104
// 0 <= Node.val <= 104


// optimize way
void helper(TreeNode *root,int &count,int k,int &ans)
{
    if(!root) return;
    
    helper(root->left,count,k,ans);
    count++;
    if(k==count) ans=root->val;
    if(ans!=-1) return;
    helper(root->right,count,k,ans);
}

int kthSmallest(TreeNode* root, int k) 
{
    int ans=-1,count=0;
    
    helper(root,count,k,ans);
    
    return ans;
}

// using array
void helper(vector<int> &n,TreeNode *root)
{
    if(!root) return;
  
    helper(n,root->left);
    n.push_back(root->val);
    helper(n,root->right);
}

int kthSmallest(TreeNode* root, int k) 
{
    vector<int> n;
    helper(n,root);
    return n[k-1];
}
